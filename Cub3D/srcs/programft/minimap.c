/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:58:35 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 16:45:19 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	rotate_player(t_cub *cub, int key, double angle)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;

	if (key == 123)
		angle *= -1;
	old_dirx = cub->player_pos.dirx;
	old_diry = cub->player_pos.diry;
	old_planex = cub->player_pos.plane.x;
	old_planey = cub->player_pos.plane.y;
	cub->player_pos.dirx = old_dirx * cos(angle) - old_diry * sin(angle);
	cub->player_pos.diry = old_dirx * sin(angle) + old_diry * cos(angle);
	cub->player_pos.plane.x = old_planex * cos(angle) - old_planey * sin(angle);
	cub->player_pos.plane.y = old_planex * sin(angle) + old_planey * cos(angle);
}

void	update_player_position(t_cub *tmp, int key)
{
	if (key == 1)
	{
		tmp->player_pos.x -= tmp->player_pos.dirx * MOVESTEP;
		tmp->player_pos.y -= tmp->player_pos.diry * MOVESTEP;
	}
	else if (key == 13)
	{
		tmp->player_pos.x += tmp->player_pos.dirx * MOVESTEP;
		tmp->player_pos.y += tmp->player_pos.diry * MOVESTEP;
	}
	else if (key == 0)
	{
		tmp->player_pos.y -= tmp->player_pos.dirx * MOVESTEP;
		tmp->player_pos.x += tmp->player_pos.diry * MOVESTEP;
	}
	else if (key == 2)
	{
		tmp->player_pos.y += tmp->player_pos.dirx * MOVESTEP;
		tmp->player_pos.x -= tmp->player_pos.diry * MOVESTEP;
	}
}

int	check_wall_collision(t_cub *cub, int key)
{
	t_cub		tmp;
	t_ray		ray;
	double		camera_x;
	int			x;

	tmp = *cub;
	update_player_position(&tmp, key);
	if (key == 124 || key == 123)
		rotate_player(&tmp, key, THREE_DEG);
	if (cub->map[(int)tmp.player_pos.y][(int)tmp.player_pos.x] == '1')
		return (1);
	set_plane(&tmp);
	x = 0;
	while (x < WIN_SIZE_W)
	{
		camera_x = 2 * x / (double)WIN_SIZE_W - 1;
		ray = raycast(&tmp, tmp.map, camera_x);
		if (ray.perp_wall_dist < 0.3)
			return (1);
		x++;
	}
	return (0);
}

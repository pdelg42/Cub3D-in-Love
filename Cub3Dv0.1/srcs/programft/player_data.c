/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:29:38 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/28 09:33:19 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	set_plane(t_cub *cub)
{
	if (cub->player_pos.dirx == 0)
	{
		if (cub->player_pos.diry == 1)
			cub->player_pos.plane.x = -1;
		else
			cub->player_pos.plane.x = 1;
		cub->player_pos.plane.y = 0;
	}
	else
	{
		if (cub->player_pos.dirx == 1)
			cub->player_pos.plane.y = 1;
		else
			cub->player_pos.plane.y = -1;
		cub->player_pos.plane.x = 0;
	}
	return ;
}

void	set_player_pos(t_cub* cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || \
				cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player_pos.x = (float)j + 0.5;
				cub->player_pos.y = (float)i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	set_player_orientation(t_cub* cub)
{
	if (cub->map[(int)cub->player_pos.y][(int)cub->player_pos.x] == 'N')
	{
		cub->player_pos.dirx = 0;
		cub->player_pos.diry = -1;
	}
	else if (cub->map[(int)cub->player_pos.y][(int)cub->player_pos.x] == 'S')
	{
		cub->player_pos.dirx = 0;
		cub->player_pos.diry = 1;	
	}
	else if (cub->map[(int)cub->player_pos.y][(int)cub->player_pos.x] == 'W')
	{
		cub->player_pos.dirx = -1;
		cub->player_pos.diry = 0;
	}
	else if (cub->map[(int)cub->player_pos.y][(int)cub->player_pos.x] == 'E')
	{
		cub->player_pos.dirx = 1;
		cub->player_pos.diry = 0;
	}
	return ;
}

void	set_player_data(t_cub* cub)
{
	set_player_pos(cub);
	set_player_orientation(cub);
	set_plane(cub);
	return ;
}
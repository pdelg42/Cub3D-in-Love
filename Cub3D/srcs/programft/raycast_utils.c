/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:51:41 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 14:13:41 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	update_ray(t_ray *ray, int axis)
{
	if (axis == 0)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	set_perp_wall_dist(t_ray *ray, t_player *pos)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - pos->x + (1 - ray->step_x) / 2.0)
			/ ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map_y - pos->y + (1 - ray->step_y) / 2.0)
			/ ray->ray_dir.y;
}

void	set_ray(t_cub *cub, t_ray *ray, double camera_x)
{
	ray->ray_dir.x = cub->player_pos.dirx + cub->player_pos.plane.x * camera_x;
	ray->ray_dir.y = cub->player_pos.diry + cub->player_pos.plane.y * camera_x;
	ray->map_x = (int)cub->player_pos.x;
	ray->map_y = (int)cub->player_pos.y;
	set_delta_dist(ray);
	set_step(ray);
	set_side_dist(ray, cub->player_pos);
}

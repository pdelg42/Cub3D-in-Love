/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:53:11 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 14:14:29 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

// set_ray

void	set_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir.y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

void	set_delta_dist(t_ray *ray)
{
	if (ray->ray_dir.y == 0)
	{
		ray->delta_dist.x = 0;
	}
	else
	{
		if (ray->ray_dir.x == 0)
			ray->delta_dist.x = 1;
		else
			ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	}
	if (ray->ray_dir.x == 0)
	{
		ray->delta_dist.y = 0;
	}
	else
	{
		if (ray->ray_dir.y == 0)
			ray->delta_dist.y = 1;
		else
			ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	}
}

void	set_side_dist(t_ray *ray, t_player pos)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = (pos.x - (double)ray->map_x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (ray->map_x + 1.0 - pos.x) * ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = (pos.y - (double)ray->map_y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map_y + 1.0 - pos.y) * ray->delta_dist.y;
}

// raycast

t_ray	raycast(t_cub *cub, char **map, double camera_x)
{
	t_ray	ray;
	int		hit;

	hit = 0;
	set_ray(cub, &ray, camera_x);
	while (hit == 0)
	{
		if (ray.side_dist.x < ray.side_dist.y)
			update_ray(&ray, 0);
		else if (ray.side_dist.x > ray.side_dist.y)
			update_ray(&ray, 1);
		else
		{
			update_ray(&ray, 0);
			update_ray(&ray, 1);
		}
		if (map[ray.map_y][ray.map_x] == '1')
			hit = 1;
	}
	set_perp_wall_dist(&ray, &cub->player_pos);
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:03:57 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 17:07:10 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	draw_line_y(t_player *sp, t_player *ep, t_cub *cub)
{
	double		m;
	double		k;
	t_player	point;
	int			size;
	int			i;

	m = (sp->y - ep->y) / (sp->x - ep->x);
	k = sp->y - m * (sp->x);
	size = fabs(sp->y - ep->y);
	if (sp->y < ep->y)
		point.y = sp->y;
	else
		point.y = ep->y;
	i = 0;
	while (i <= size)
	{
		if (sp->x != ep->x)
			point.x = floor(((point.y + i) - k) / m + 0.5);
		else
			point.x = sp->x;
		my_mlx_pixel_put(cub->data, point.x, point.y + i, 0xff0000);
		i++;
	}
}

void	draw_line_x(t_player *sp, t_player *ep, t_cub *cub)
{
	double		m;
	double		k;
	t_player	point;
	int			size;
	int			i;

	m = (sp->y - ep->y) / (sp->x - ep->x);
	k = sp->y - m * (sp->x);
	size = fabs(sp->x - ep->x);
	if (sp->x < ep->x)
		point.x = sp->x;
	else
		point.x = ep->x;
	i = 0;
	while (i <= size)
	{
		point.y = floor(m * (point.x + i) + k + 0.5);
		my_mlx_pixel_put(cub->data, point.x + i, point.y, 0xff0000);
		i++;
	}
}

void	draw_line(t_player *sp, t_player *ep, t_cub *cub)
{
	if (fabs(sp->x - ep->x) < 1)
	{
		draw_line_y(sp, ep, cub);
	}
	else
	{
		draw_line_x(sp, ep, cub);
	}
}

void	draw_ray(t_cub *cub, t_ray *ray)
{
	t_player	sp;
	t_player	ep;
	int			b_size;

	if ((int)ft_strlen(cub->map[0]) > row_counter(cub->map))
		b_size = MINI_WIN_SIZE / ft_strlen(cub->map[0]);
	else
		b_size = MINI_WIN_SIZE / row_counter(cub->map);
	sp.x = b_size * cub->player_pos.x;
	sp.y = b_size * cub->player_pos.y;
	if (ray->side == 0)
	{
		ep.y = b_size * (cub->player_pos.y + \
			ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (cub->player_pos.x + \
			ray->perp_wall_dist * ray->ray_dir.x);
	}
	else
	{
		ep.y = b_size * (cub->player_pos.y + \
			ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (cub->player_pos.x + \
			ray->perp_wall_dist * ray->ray_dir.x);
	}
	draw_line(&sp, &ep, cub);
}

void	draw_rays(t_cub *cub, float mapw, int b_size)
{
	int		x;
	double	camera_x;
	t_ray	ray;

	x = 0;
	while (x * 10 < (int)(mapw * b_size))
	{
		camera_x = 2 * (x * 10) / (double)(mapw * b_size) - 1;
		ray = raycast(cub, cub->map, camera_x);
		draw_ray(cub, &ray);
		x++;
	}
}

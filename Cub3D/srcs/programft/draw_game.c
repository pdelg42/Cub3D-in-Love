/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:44:40 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 14:18:03 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	draw_wall(t_cub *cub, t_ray *ray, int x)
{
	t_render_info	info;
	t_img_info		*tex_info;
	t_img_info		*img_info;
	int				color;

	img_info = &cub->graphic_info.img_info;
	info = get_render_info(ray, &cub->player_pos);
	tex_info = cub->graphic_info.texture_info;
	while (info.start_y < info.end_y)
	{
		info.tex_y = (int)info.tex_pos & (TILE_SIZE - 1);
		if (ray->side == 0 && ray->ray_dir.x > 0)
			color = get_img_color(&tex_info[0], info.tex_x, info.tex_y);
		else if (ray->side == 0 && ray->ray_dir.x < 0)
			color = get_img_color(&tex_info[1], info.tex_x, info.tex_y);
		else if (ray->side == 1 && ray->ray_dir.y > 0)
			color = get_img_color(&tex_info[2], info.tex_x, info.tex_y);
		else if (ray->side == 1 && ray->ray_dir.y < 0)
			color = get_img_color(&tex_info[3], info.tex_x, info.tex_y);
		draw_pixel(img_info, x, info.start_y, color);
		my_mlx_pixel_put(cub->data, x, info.start_y, color);
		info.tex_pos += info.ratio;
		info.start_y++;
	}
}

// draw everything

void	draw_game_bg(t_cub *cub)
{
	int			x;
	int			y;

	y = -1;
	while (++y < WIN_SIZE_H / 2)
	{
		x = -1;
		while (++x < WIN_SIZE_W)
		{
			my_mlx_pixel_put(cub->data, x, y, 0x7799f0);
			my_mlx_pixel_put(cub->data, x, y + (WIN_SIZE_H / 2),
				0x77f077);
		}
	}
}

void	draw_game(t_cub *cub)
{
	int		x;
	t_ray	ray;
	double	camera_x;

	x = 0;
	draw_game_bg(cub);
	while (x < WIN_SIZE_W)
	{
		camera_x = 2 * x / (double)WIN_SIZE_W - 1;
		ray = raycast(cub, cub->map, camera_x);
		draw_wall(cub, &ray, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win,
		cub->data->img, 0, 0);
}

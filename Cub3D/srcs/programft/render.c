/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:42:53 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 14:18:10 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

#define FLOOR 0x0055cc55
#define SKY 0x00aaaaee
#define WALL 0x0

t_render_info	get_render_info(t_ray *ray, t_player *player)
{
	t_render_info	render_info;

	render_info.line_height = (int)(WIN_SIZE_H / ray->perp_wall_dist);
	render_info.ratio = (double)TILE_SIZE / render_info.line_height;
	render_info.start_y = (WIN_SIZE_H / 2) - (render_info.line_height / 2);
	render_info.end_y = (WIN_SIZE_H / 2) + (render_info.line_height / 2);
	if (render_info.start_y < 0)
		render_info.start_y = 0;
	if (render_info.end_y >= WIN_SIZE_H)
		render_info.end_y = WIN_SIZE_H;
	render_info.tex_x = get_texture_scaled_x(player, ray);
	render_info.tex_pos = (render_info.start_y - WIN_SIZE_H / 2
			+ render_info.line_height / 2) * render_info.ratio;
	return (render_info);
}

// raycasting ops

void	add_walls(t_cub *cub)
{
	t_point		pos0;
	t_point		posf;
	t_fixed8	stepval;
	t_point		delta;
	int			i;

	pos0.x = int2fixed(8);
	pos0.y = int2fixed(5);
	posf.x = int2fixed(200);
	posf.y = int2fixed(200);
	stepval = 0;
	delta = point_delta(pos0, posf);
	if (delta.x > delta.y)
		stepval = delta.x;
	else
		stepval = delta.y;
	delta.x = fixdiv(delta.x, stepval);
	delta.y = fixdiv(delta.y, stepval);
	i = 0;
	while (i++ <= fixed2int(stepval))
	{
		pos0.x = fixsum(pos0.x, delta.x);
		pos0.y = fixsum(pos0.y, delta.y);
		my_mlx_pixel_put(cub->data, fixed2int(pos0.x), fixed2int(pos0.y), WALL);
	}
}

// funzione placeholder per stampa su finestra e definizione di un orizzonte

void	render(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	cub->data->img = mlx_new_image(cub->mlx, WIN_SIZE_W, WIN_SIZE_H);
	cub->data->img2 = mlx_new_image(cub->mlx, WIN_SIZE_W, WIN_SIZE_H);
	cub->data->addr = mlx_get_data_addr(cub->data->img, \
		&cub->data->bits_per_pixel, &cub->data->line_length, \
			&cub->data->endian);
	cub->data->addr2 = mlx_get_data_addr(cub->data->img2, \
		&cub->data->bits_per_pixel, &cub->data->line_length, \
			&cub->data->endian);
	add_walls(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:44:40 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/28 17:18:05 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

// update ray

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

// set_ray

static void	set_side_dist(t_ray *ray, t_player pos)
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

static void	set_step(t_ray *ray)
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

static void	set_delta_dist(t_ray *ray)
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

static unsigned int	get_img_color(t_img_info *img_info, int x, int y)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	return (*(img_info->buf + pixel));
}

static int	get_texture_scaled_x(t_player *player, t_ray *ray)
{
	double	wall_x;
	int		texture_x;

	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->ray_dir.x;
	wall_x = wall_x - floor(wall_x);
	texture_x = (int)(wall_x * (double)TILE_SIZE);
	if (ray->side == 0 && ray->ray_dir.x < 0)
		texture_x = TILE_SIZE - texture_x - 1;
	if (ray->side == 1 && ray->ray_dir.y > 0)
		texture_x = TILE_SIZE - texture_x - 1;
	return (texture_x);
}

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

void	draw_pixel(t_img_info *img_info, int x, int y, int color)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	*(img_info->buf + pixel) = color;
}

void	draw_wall(t_cub *cub, t_ray *ray, int x)
{
	t_render_info	info;
	t_img_info		*tex_info;
	t_img_info		*img_info;
	int				colora[4] = {0xaa0000, 0x00aa00, 0x0000aa, 0xabcdef};
	int				color;

	img_info = &cub->graphic_info.img_info;
	info = get_render_info(ray, &cub->player_pos);
	tex_info = cub->graphic_info.texture_info;
	while (info.start_y < info.end_y)
	{
		info.tex_y = (int)info.tex_pos & (TILE_SIZE - 1);
		if (ray->side == 0 && ray->ray_dir.x > 0)
			color = colora[0];
		else if (ray->side == 0 && ray->ray_dir.x < 0)
			color = colora[1];
		else if (ray->side == 1 && ray->ray_dir.y > 0)
			color = colora[2];
		else if (ray->side == 1 && ray->ray_dir.y < 0)
			color = colora[3];
	
		// if (ray->side == 0 && ray->ray_dir.x > 0)
		// 	color = get_img_color(&tex_info[0], info.tex_x, info.tex_y);
		// else if (ray->side == 0 && ray->ray_dir.x < 0)
		// 	color = get_img_color(&tex_info[1], info.tex_x, info.tex_y);
		// else if (ray->side == 1 && ray->ray_dir.y > 0)
		// 	color = get_img_color(&tex_info[2], info.tex_x, info.tex_y);
		// else if (ray->side == 1 && ray->ray_dir.y < 0)
		// 	color = get_img_color(&tex_info[3], info.tex_x, info.tex_y);
		// draw_pixel(img_info, x, info.start_y, color);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:16:47 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 14:19:27 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

unsigned int	get_img_color(t_img_info *img_info, int x, int y)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	return (*(img_info->buf + pixel));
}

int	get_texture_scaled_x(t_player *player, t_ray *ray)
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

void	draw_pixel(t_img_info *img_info, int x, int y, int color)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	*(img_info->buf + pixel) = color;
}

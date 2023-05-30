/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 13:35:21 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	draw_player(t_cub* cub)
{
	float	center_x;
	float	center_y;
	float	mapw;
	float	maph;
	int	final_x = 0;
	int	final_y = 0;

	int	b_size;
	mapw = ft_strlen(cub->map[0]);
	maph = row_counter(cub->map);
	if (mapw > maph)
		b_size = MINI_WIN_SIZE / mapw;
	else
		b_size = MINI_WIN_SIZE / maph;
    center_x = (cub->player_pos.x) * b_size;
    center_y = (cub->player_pos.y) * b_size;
    final_x = (int)(center_x);
    final_y = (int)(center_y);
    my_mlx_pixel_put(cub->data, final_x, final_y, 0x0cddddf);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
}

static void	draw_line_y(t_player *sp, t_player *ep, t_cub* cub)
{
	double	m;
	double	k;
	t_player	point;
	int		size;
	int		i;

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

static void	draw_line_x(t_player *sp, t_player *ep, t_cub* cub)
{
	double	m;
	double	k;
	t_player	point;
	int		size;
	int		i;

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

void	draw_line(t_player *sp, t_player *ep, t_cub* cub)
{
	if (fabs(sp->x - ep->x) < 1)
	{
		// printf("< 1");
		draw_line_y(sp, ep, cub);
	}
	else
	{
		// printf(">= 1");
		draw_line_x(sp, ep, cub);
	}
}

void	draw_ray(t_cub *cub, t_ray *ray)
{
	t_player	sp;
	t_player	ep;
	int		b_size;

	if ((int)ft_strlen(cub->map[0]) > row_counter(cub->map))
		b_size = MINI_WIN_SIZE / ft_strlen(cub->map[0]);
	else
		b_size = MINI_WIN_SIZE / row_counter(cub->map);

	// pos = define_player_pos(cub);

	sp.x = b_size * cub->player_pos.x;
	sp.y = b_size * cub->player_pos.y;

	if (ray->side == 0) // 0 = incide sul lato delle X
	{
		ep.y = b_size * (cub->player_pos.y + ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (cub->player_pos.x + ray->perp_wall_dist * ray->ray_dir.x);
	}
	else	// se non incide sulle X incide sulle Y
	{
		ep.y = b_size * (cub->player_pos.y + ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (cub->player_pos.x + ray->perp_wall_dist * ray->ray_dir.x);
	}

	draw_line(&sp, &ep, cub);
}

int	draw_minimap(t_cub* cub)
{
	float	k;
	float	m;

	float	mapw;
	float	maph;
	int i;
	int	j;
	int	b_size;


	mapw = ft_strlen(cub->map[0]);
	maph = row_counter(cub->map);

	if (mapw > maph)
		b_size = MINI_WIN_SIZE / mapw;
	else
		b_size = MINI_WIN_SIZE / maph;
	
	i = 0;
	while (i < maph)
	{
		j = 0;
		while (j < mapw)
		{
			if (cub->map[i][j] == '1')
			{
				m = 0;
				while (m < b_size)
				{
					k = 0;
					while (k < b_size)
					{
						my_mlx_pixel_put(cub->data, (int)((j * b_size) + m), (int)((i * b_size) + k), 0x0abcdef);
						k++;
					}
					m++;					
				}
			}
			else
			{
				m = 0;
				while (m < b_size)
				{
					k = 0;
					while (k < b_size)
					{
						my_mlx_pixel_put(cub->data, (int)((j * b_size) + m), (int)((i * b_size) + k), 0x0ffffff);
						k++;
					}
					m++;
				}
			}
			j++;
		}
		i++;
	}

	int		x;
	t_ray	ray;
	double	camera_x;

	x = 0;
	while (x * 10 < (int)(mapw * b_size))
	{
		camera_x = 2 * (x * 10)/ (double)(mapw * b_size) - 1;
		ray = raycast(cub, cub->map, camera_x);
		draw_ray(cub, &ray);
		x++;
	}

	mlx_put_image_to_window(cub->mlx, cub->win,
		cub->data->img, 0, 0);
	return (0);
}
 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/19 12:00:53 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

// void draw_borders(t_cub *cub)
// {
// 	int	i;
// 	int	j;
// 	int	tiles;

// 	i = 10;
// 	tiles = (64 * 3) + 13;
// 	while (i < tiles)
// 	{
// 		j = 10;
// 		while (j < tiles)
// 		{
// 			if ((i == 10 || i == tiles - 1) || (j == 10 || j == tiles - 1))
// 			{
// 				my_mlx_pixel_put(cub->data, j, i, 0x0055cc55);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	define_player_pos(t_cub* cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player_pos.x = i;
				cub->player_pos.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_cub* cub, float x, float y, float angle, int key)
{
	float	width;
	float	height;
	int	k;
	int	m;

	float	mapw;
	float	maph;

	mapw = ft_strlen(cub->map[0]);
	maph = row_counter(cub->map);

	width = (WIN_SIZE_W/mapw) / 2;
	height = (WIN_SIZE_H/maph) / 2;

	float	center_x;
	float	center_y;

    // Cancella la vecchia posizione del giocatore.
	if (key == 13)
	{
		center_x = ((cub->player_pos.y - (cub->player_pos.diry * 0.05))) * width;
		center_y = ((cub->player_pos.x - (cub->player_pos.dirx * 0.05))) * height;
	}
	else if (key == 1)
	{
		center_x = ((cub->player_pos.y + (cub->player_pos.diry * 0.05))) * width;
		center_y = ((cub->player_pos.x + (cub->player_pos.dirx * 0.05))) * height;
	}
	else if (key == 0) // a
	{
		center_x = (cub->player_pos.y + cub->player_pos.dirx * 0.05) * width;
		center_y = (cub->player_pos.x - cub->player_pos.diry * 0.05) * height;
	}
	else if (key == 2) // d
	{
		center_x = (cub->player_pos.y - cub->player_pos.dirx * 0.05) * width;
		center_y = (cub->player_pos.x + cub->player_pos.diry * 0.05) * height;
	}

	m = 0;
	while (m < width)
	{
		k = 0;
		while (k < width)
		{
            int final_x = (int)(center_x + m);
            int final_y = (int)(center_y + k);

            my_mlx_pixel_put(cub->data, final_x, final_y, 0xff00000);
			k++;
		}
		m++;
	}

    // Disegna il giocatore nella sua nuova posizione con la rotazione.
    center_x = (cub->player_pos.y) * width;
    center_y = (cub->player_pos.x) * height;

	m = 0;
	while (m < width)
	{
		k = 0;
		while (k < width)
		{
			float rotated_x = m * cos(angle) - k * sin(angle);
            float rotated_y = m * sin(angle) + k * cos(angle);

            int final_x = (int)(center_x + rotated_x);
            int final_y = (int)(center_y + rotated_y);

            my_mlx_pixel_put(cub->data, final_x, final_y, 0x0cddddf);
			k++;
		}
		m++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
}


int	draw_minimap(t_cub* cub)
{
	float	width;
	float	height;
	float	k;
	float	m;

	// int offset;

	float	mapw;
	float	maph;
	int i;
	int	j;

	// offset = 10;

	mapw = ft_strlen(cub->map[0]);
	maph = row_counter(cub->map);
	printf("w map: %zu, h map: %d\n", ft_strlen(cub->map[0]), row_counter(cub->map));

	width = (WIN_SIZE_W/mapw) / 2;
	height = (WIN_SIZE_H/maph) / 2;
	printf("w tile: %f, h tile: %f\n", width, height);

	i = 0;
	while (i < maph)
	{
		j = 0;
		while (j < mapw)
		{
			if (cub->map[i][j] == '1')
			{
				m = 1;
				while (m < width - 1)
				{
					k = 1;
					while (k < height - 1)
					{
						my_mlx_pixel_put(cub->data, (int)((j * width) + m), (int)((i * height) + k), 0x0abcdef);
						k++;
					}
					m++;					
				}
			}
			else
			{
				m = 1;
				while (m < width - 1)
				{
					k = 1;
					while (k < height - 1)
					{
						my_mlx_pixel_put(cub->data, (int)((j * width) + m), (int)((i * height) + k), 0x0ffffff);
						k++;
					}
					m++;
				}
			}
			j++;
		}
		i++;
	}
	//mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
	return (0);
}
 
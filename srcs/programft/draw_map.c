/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/19 15:43:19 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"


// void draw_tile(t_cub* cub, unsigned long int color, int w, int h)
// {
// 	int offset;
//     int i;

// 	offset = 10;
// 	i = 0;
// 	//i quadratini che rappresentano i caratteri sono di grandezza 13x13
// 	//con un distacco dal bordo in alto a sinitra di 10 in altezza e larghezza
//     while (i < 13)
//     {
//         int j = 0;
//         while (j < 13)
//         {
//             my_mlx_pixel_put(cub->data, ((h * 13) + (j + offset)), \
// 				((w * 13) + (i + offset)), color);
//             j++;
//         }
//         i++;
//     }
// }

// void update_coordinates(int* w, int* h)
// {
//     (*h)++;
//     if (*h == 15)
//     {
//         (*w)++;
//         *h = 0;
//     }
//     if (*w == 15)
//     {
//         *h = 0;
//         *w = 0;
//     }
// }

// void draw_square(t_cub* cub, unsigned long int color)
// {
//     static int w = 0;
//     static int h = 0;

//     draw_tile(cub, color, w, h);
//     update_coordinates(&w, &h);
// }

// void define_square(t_cub* cub, char tile)
// {
// 	if (tile == '\0')
// 		return ;
// 	if (tile == '0')
// 		draw_square(cub, 0x00101010);
// 	if (tile == '1')
// 		draw_square(cub, 0x00424242);
// 	if (tile == ' ')
// 		draw_square(cub, 0x00694202);
// 	if (tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
// 		draw_square(cub, 0x00fff000);
// }

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
				cub->player_pos.x = int2fixed(i);
				cub->player_pos.y = int2fixed(j);
				return ;
			}
			j++;
		}
		i++;
	}
}

// int	draw_minimap(t_cub* cub)
// {
// 	int	i;
// 	int	j;
// 	int width;
// 	int	height;

// 	width = ft_strlen(cub->minimap[0]);
// 	height = row_counter(cub->minimap);
// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			if (((i > cub->player_pos.x - 8.) && (i < cub->player_pos.x + 8.)) && ((j > cub->player_pos.y - 8.) && (j < cub->player_pos.y + 8.)))
// 			{
// 				define_square(cub, cub->minimap[i][j]);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_borders(cub);
// 	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
// 	return (0);
// }

void	player_img_init(t_cub *cub)
{
	t_data *pI = (t_data *) ft_calloc(sizeof(t_data), 1);

	pI->img = mlx_new_image(cub->mlx, 8, 8);
	pI->addr = mlx_get_data_addr(pI->img, 
		&pI->bits_per_pixel, &pI->line_length, &pI->endian);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			my_mlx_pixel_put(pI, j, i, 0x0aabbcc);
	cub->playerImg = pI;
}

void	draw_player(t_cub* cub)
{
	mlx_put_image_to_window(cub->mlx, cub->win, cub->playerImg->img, fixed2int(cub->player_pos.x), fixed2int(cub->player_pos.y));
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

	width = (WIN_SIZE_W/mapw) / 4;
	height = (WIN_SIZE_H/maph) / 4;
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
						//my_mlx_pixel_put(cub->data, (int)((j * width) + m), (int)((i * height) + k), 0x0ffffff);
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
 
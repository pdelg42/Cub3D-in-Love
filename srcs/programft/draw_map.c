/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/14 04:53:30 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	draw_square(t_cub* cub, unsigned long int color, int x, int y)
{
	int	i;
	int	j;
	int	miniw;
	int	minih;
	int	offset;

	offset = 10;
	// miniw = (64.f * 3.f / (float)(ft_strlen(cub->map[0]) - 1.f));
	miniw = (64 * 3 / (ft_strlen(cub->map[0]) - 1));
	minih = (64 * 3 / row_counter(cub->map));
	i = 0;
	while (i < minih)
	{
		j = 0;
		while (j < miniw)
		{
			my_mlx_pixel_put(cub->data, ( ((miniw * y) + (offset + j) - 1) ), ( ((minih * x) + (offset + i) + 1) ), color);
			j++;
		}
		i++;
	}
}

void define_square(t_cub* cub, char tile, int x, int y)
{
	if (tile == '\0')
	{
		return ;
	}
	else if (tile == '0')
	{
		draw_square(cub, 0x00101010, x, y);
	}
	else if (tile == '1')
	{
		draw_square(cub, 0x00424242, x, y);
	}
	else if (tile == ' ')
	{
		draw_square(cub, 0x00694202, x, y);
	}
	else if (tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
	{
		draw_square(cub, 0x00fff000, x, y);
	}
	else
	{
		write(1, "Char not printable: Error map\n", \
			ft_strlen("Char not printable: Error map\n"));
	}
}

void draw_borders(t_cub *cub)
{
	int	i;
	int	j;
	int	tiles;

	i = 10;
	tiles = (64 * 3) + 12;
	while (i < tiles)
	{
		j = 9;
		while (j < tiles)
		{
			if ((i == 10 || i == tiles - 1) || (j == 9 || j == tiles - 1))
			{
				my_mlx_pixel_put(cub->data, j, i, 0x0055cc55);
			}
			j++;
		}
		i++;
	}
}

int	draw_minimap(t_cub* cub)
{
	int	i;
	int	j;

	// my_mlx_pixel_put(cub->data, 10, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 11, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 12, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 13, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 14, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 15, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 16, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 17, 9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 18,  9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 19,  9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 20,  9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 21,  9, 0x00eee000);
	// my_mlx_pixel_put(cub->data, 22,  9, 0x00eee000);

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			write(1, &cub->map[i][j], 1);
			define_square(cub, cub->map[i][j], i, j);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	draw_borders(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
	return (0);
}
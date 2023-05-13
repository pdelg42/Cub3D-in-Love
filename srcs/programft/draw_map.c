/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/13 19:39:27 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	count_rows(char** map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	draw_square(t_cub* cub, unsigned long int color, int x, int y)
{
	int	i;
	int	j;
	int	miniw;
	int	minih;

	miniw = (64 * 3 / ft_strlen(cub->map[0]));
	minih = (64 * 3 / row_counter(cub->map));
	i = 0;
	while (i < minih)
	{
		j = 0;
		while (j < miniw)
		{
			my_mlx_pixel_put(cub->data, ( ((miniw * y) + (11 + j)) ), ( ((minih * x) + (11 + i)) ), color);
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
		draw_square(cub, 0x00ff3400, x, y);
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
	tiles = (64 * 3) + 1;
	while (i < tiles)
	{
		j = 10;
		while (j < tiles)
		{
			if ((i == 10 || i == tiles) || (j == 10 || j == tiles))
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

	draw_borders(cub);
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
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/14 06:39:46 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	draw_square(t_cub* cub, unsigned long int color, int x, int y)
{
	int miniw;
	int	minih;
	int	offset;
	static int w;
	static int h;

	offset = 10;
	miniw = 13;
	minih = 13;

	int i;
	int j;
	i = 0;
	while (i < minih)
	{
		j = 0;
		while (j < miniw)
		{
			my_mlx_pixel_put(cub->data, ((h * 13) + (j + offset)), ((w * 13) + (i + offset)), color);
			j++;
		}
		i++;
	}
	h++;
	if (h == 15)
	{
		w++;
		h = 0;
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
		// printf("PLAYERX: %d PLAYERY %d\n", x, y);
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
	tiles = (64 * 3) + 13;
	while (i < tiles)
	{
		j = 10;
		while (j < tiles)
		{
			if ((i == 10 || i == tiles - 1) || (j == 10 || j == tiles - 1))
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

	//valori placeholder da sostituire con la posizione del player in modo dinamico
	int playerx = 7;
	int	playery = 14;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			write(1, &cub->map[i][j], 1);
			//disegna solo i quadrati attorno al player in un area di 8 caselle
			if (((i > playerx - 8) && (i < playerx + 8)) && ((j > playery - 8) && (j < playery + 8)))
			{
				define_square(cub, cub->map[i][j], i, j);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	draw_borders(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:45 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/16 00:33:41 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void draw_tile(t_cub* cub, unsigned long int color, int w, int h)
{
	int offset;
    int i;

	offset = 10;
	i = 0;
	//i quadratini che rappresentano i caratteri sono di grandezza 13x13
	//con un distacco dal bordo in alto a sinitra di 10 in altezza e larghezza
    while (i < 13)
    {
        int j = 0;
        while (j < 13)
        {
            my_mlx_pixel_put(cub->data, ((h * 13) + (j + offset)), \
				((w * 13) + (i + offset)), color);
            j++;
        }
        i++;
    }
}

void update_coordinates(int* w, int* h)
{
    (*h)++;
    if (*h == 15)
    {
        (*w)++;
        *h = 0;
    }
    if (*w == 15)
    {
        *h = 0;
        *w = 0;
    }
}

void draw_square(t_cub* cub, unsigned long int color)
{
    static int w = 0;
    static int h = 0;

    draw_tile(cub, color, w, h);
    update_coordinates(&w, &h);
}

void define_square(t_cub* cub, char tile)
{
	if (tile == '\0')
	{
		return ;
	}
	else if (tile == '0')
	{
		draw_square(cub, 0x00101010);
	}
	else if (tile == '1')
	{
		draw_square(cub, 0x00424242);
	}
	else if (tile == ' ')
	{
		draw_square(cub, 0x00694202);
	}
	else if (tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
	{
		draw_square(cub, 0x00fff000);
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

void	define_player_pos(t_cub* cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->minimap[i])
	{
		j = 0;
		while (cub->minimap[i][j])
		{
			if (cub->minimap[i][j] == 'N' || cub->minimap[i][j] == 'S' || cub->minimap[i][j] == 'W' || cub->minimap[i][j] == 'E')
			{
				cub->player_pos.x = i;
				cub->player_pos.y = j;
				printf("Mini check player pos: %c\n", cub->minimap[cub->player_pos.x][cub->player_pos.y]);
				return ;
			}
			j++;
		}
		i++;
	}
}

//cicla esattamente i valori +-8 di distanza dal player e disegnali
//se la posizione del player+-8 esce dalla mappa stampa il padding

int	draw_minimap(t_cub* cub)
{
	int	i;
	int	j;

	int width;
	int	height;

	width = ft_strlen(cub->minimap[0]);
	height = row_counter(cub->minimap);

	printf("MINIWIDTH: %d\n", width);
	printf("MINIHEIGHT: %d\n", height);
	printf("PLAYERX: %d PLAYERY: %d\n", cub->player_pos.x, cub->player_pos.y);

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			//disegna solo i quadrati attorno al player in un area di 8 caselle partendo dal player, sommando 8 a playerx e playery per compensare il padding
			if (((i > cub->player_pos.x - 8) && (i < cub->player_pos.x + 8)) && ((j > cub->player_pos.y - 8) && (j < cub->player_pos.y + 8)))
			{
				write(1, &cub->minimap[i][j], 1);
				define_square(cub, cub->minimap[i][j]);
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
 
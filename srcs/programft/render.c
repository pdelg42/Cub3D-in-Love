/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:42:53 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/10 09:15:32 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

#define FLOOR 0x0055cc55
#define SKY 0x00aaaaee
#define WALL 0x00aa2222

// disegna i muri

void	add_walls(t_cub *cub)
{
	(void) cub;
}

// funzione placeholder per stampa su finestra e definizione di un orizzonte

void	render(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	cub->data->img = mlx_new_image(cub->mlx, WIN_SIZE_W, WIN_SIZE_H);
	cub->data->addr = mlx_get_data_addr(cub->data->img, 
		&cub->data->bits_per_pixel, &cub->data->line_length, &cub->data->endian);
	for (int y = 0; y < WIN_SIZE_H; y++)
	{
		for (int x = 0; x < WIN_SIZE_W; x++)
		{
			if (y > (WIN_SIZE_H / 2))
				my_mlx_pixel_put(cub->data, x, y, cub->floor_color->rgb);
			else
				my_mlx_pixel_put(cub->data, x, y, cub->ceil_color->rgb);
		}
	}
	add_walls(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
}
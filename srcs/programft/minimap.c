/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:58:35 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/16 19:50:48 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

//per testare uso la key (cioé il movimento del player), in seguito
//questo valore sará sostituito dall orientamento del player + key
//es: player orientato a nord va avanti con w 
//la x rimane uguale mentre la y diminuisce di 1 (si sta muovendo verso l alto)

void add_map_padding(t_cub* cub) 
{
	int	width;
	int	height;
	int	k;
	int	m;

	//+8 per il padding a destra, +8 a sinistra, sopra e sotto, +1 alla width per il \0 o \n character
	width = ft_strlen(cub->map[0]) + 16;
	height = row_counter(cub->map) + 16;
	
	int i;
	cub->minimap = (char**) malloc (sizeof(char*) * height);
	for (i = 0; i < height; i++) 
	{
    	cub->minimap[i] = (char*) malloc (sizeof(char) * width + 1);
	}
	cub->minimap[i] = NULL;


	k = 0;
	while (k < height)
	{
		m = 0;
		while (m < width)
		{
			cub->minimap[k][m] = '0';
			write(1, &cub->minimap[k][m], 1);
			m++;
		}
		write(1, "\n", 1);
		cub->minimap[k][m] = '\0';
		k++;
	}
	write(1, "\n", 1);

	k = 0;
	while (k < height - 16)
	{
		m = 0;
		while (m < width - 16)
		{
			cub->minimap[k + 8][m + 8] = cub->map[k][m];
			// write(1, &cub->minimap[k + 8][m + 8], 1);
			m++;
		}
		// write(1, "\n", 1);
		k++;
	}
}

int	mov_offset_y(int key)
{
	if (key == 2)
		return (1);
	else if (key == 0)
		return (-1);
	return (0);
}

int	mov_offset_x(int key)
{
	if (key == 1)
		return (1);
	else if (key == 13)
		return (-1);
	return (0);
}

char	get_orientation(char** map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				return ('N');
			}
			else if (map[i][j] == 'S')
				return ('S');
			else if (map[i][j] == 'W')
				return ('W');
			else if (map[i][j] == 'E')
				return ('E');
		}
	}
	return ('N');
}

void	update_minimap(t_cub* cub, int x, int y)
{
	char	orientation;
	
	// orientation = get_orientation(cub->map);
	cub->minimap[cub->player_pos.x][cub->player_pos.y] = '0';	
	cub->minimap[cub->player_pos.x + x][cub->player_pos.y + y] = 'N';
}

void	minimove(t_cub* cub, int key)
{
	int	x;
	int	y;

	x = mov_offset_x(key);
	y = mov_offset_y(key);
	if (cub->minimap[cub->player_pos.x + x][cub->player_pos.y + y] == '1')
	{
		return ;
	}
	update_minimap(cub, x, y);
	cub->player_pos.x += x;
	cub->player_pos.y += y;
	draw_minimap(cub);
}
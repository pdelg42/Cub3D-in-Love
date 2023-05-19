/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:58:35 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/19 15:07:15 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void allocate_minimap_memory(t_cub* cub, int height, int width)
{
    int i;
    cub->minimap = (char**)malloc(sizeof(char*) * height);
    for (i = 0; i < height; i++) 
    {
        cub->minimap[i] = (char*)malloc(sizeof(char) * width + 1);
    }
    cub->minimap[i] = NULL;
}

void initialize_minimap(t_cub* cub, int height, int width)
{
    int k, m;
    for (k = 0; k < height; k++)
    {
        for (m = 0; m < width; m++)
        {
            cub->minimap[k][m] = '0';
        }
        cub->minimap[k][m] = '\0';
    }
}

void copy_map_to_minimap(t_cub* cub, int height, int width)
{
    int k, m;
    for (k = 0; k < height - 16; k++)
    {
        for (m = 0; m < width - 16; m++)
        {
            cub->minimap[k + 8][m + 8] = cub->map[k][m];
        }
    }
}


//per testare uso la key (cioé il movimento del player), in seguito
//questo valore sará sostituito dall orientamento del player + key
//es: player orientato a nord va avanti con w 
//la x rimane uguale mentre la y diminuisce di 1 (si sta muovendo verso l alto)

void add_map_padding(t_cub* cub) 
{
	int	width;
	int	height;

	//+8 per il padding a destra, +8 a sinistra, sopra e sotto, +1 alla width per il \0 o \n character
	width = ft_strlen(cub->map[0]) + 16;
	height = row_counter(cub->map) + 16;
	
    allocate_minimap_memory(cub, height, width);
    initialize_minimap(cub, height, width);
    copy_map_to_minimap(cub, height, width);
}

float	mov_offset_x(int key)
{
	if (key == 2)
		return (0.5);
	else if (key == 0)
		return (-0.5);
	return (0.);
}

float	mov_offset_y(int key)
{
	if (key == 1)
		return (0.5);
	else if (key == 13)
		return (-0.5);
	return (0.);
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

void	minimove(t_cub* cub, int key)
{
	float	x;
	float	y;

	x = mov_offset_x(key);
	y = mov_offset_y(key);
	cub->player_pos.x = fixsum(cub->player_pos.x, flo2fixed(x));
	cub->player_pos.y = fixsum(cub->player_pos.y, flo2fixed(y));
	draw_player(cub);
}

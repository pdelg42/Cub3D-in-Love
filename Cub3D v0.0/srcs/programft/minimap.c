/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:58:35 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/23 02:18:15 by sgerace          ###   ########.fr       */
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

void add_map_padding(t_cub* cub) 
{
	int	width;
	int	height;

	width = ft_strlen(cub->map[0]) + 16;
	height = row_counter(cub->map) + 16;
    allocate_minimap_memory(cub, height, width);
    initialize_minimap(cub, height, width);
    copy_map_to_minimap(cub, height, width);
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
				return ('N');
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

void rotate_player(t_cub* cub, float angle)
{
	float old_dirx;
	float old_diry;

	old_dirx = cub->player_pos.dirx;
	old_diry = cub->player_pos.diry;
	cub->player_pos.dirx = old_dirx * cos(angle) - old_diry * sin(angle);
	cub->player_pos.diry = old_dirx * sin(angle) + old_diry * cos(angle);
	cub->player_pos.angle += (angle * 180 / M_PI);
}

void minimove(t_cub* cub, int key)
{
	float moveStep = 0.05;

	if (key == 13) // w
	{
		cub->player_pos.x -= cub->player_pos.dirx * moveStep;
		cub->player_pos.y -= cub->player_pos.diry * moveStep;
	}
	else if (key == 1) // s
	{
		cub->player_pos.x += cub->player_pos.dirx * moveStep;
		cub->player_pos.y += cub->player_pos.diry * moveStep;
	}
	else if (key == 0) // a
	{
		cub->player_pos.y -= cub->player_pos.dirx * moveStep;
		cub->player_pos.x += cub->player_pos.diry * moveStep;
	}
	else if (key == 2) // d
	{
		cub->player_pos.y += cub->player_pos.dirx * moveStep;
		cub->player_pos.x -= cub->player_pos.diry * moveStep;
	}
	else if (key == 124) // ->
	{
		rotate_player(cub, ONE_DEG);
	}
	else if (key == 123) // <-
	{
		rotate_player(cub, -ONE_DEG);
	}
	// draw_player(cub, 0., 0., 0., key);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:58:35 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/26 19:43:19 by sgerace          ###   ########.fr       */
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

void rotate_player(t_cub* cub, double angle)
{
	double old_dirx;
	double old_diry;
	double old_planex;
	double old_planey;

	old_dirx = cub->player_pos.dirx;
	old_diry = cub->player_pos.diry;
	old_planex = cub->player_pos.plane.x;
	old_planey = cub->player_pos.plane.y;
	cub->player_pos.dirx = old_dirx * cos(angle) - old_diry * sin(angle);
	cub->player_pos.diry = old_dirx * sin(angle) + old_diry * cos(angle);
	cub->player_pos.plane.x = old_planex * cos(angle) - old_planey * sin(angle);
	cub->player_pos.plane.y = old_planex * sin(angle) + old_planey * cos(angle);
	// cub->player_pos.angle += (angle * 180 / M_PI);
}

int	check_wall_collision(t_cub* cub, int key)
{
	t_cub		tmp;
	t_ray		ray;
	double		camera_x;
	int			x;
	
	tmp = *cub;
	if (key == 1) // w
	{
		tmp.player_pos.x -= tmp.player_pos.dirx * 0.1;
		tmp.player_pos.y -= tmp.player_pos.diry * 0.1;
	}
	else if (key == 13) // s
	{
		tmp.player_pos.x += tmp.player_pos.dirx * 0.1;
		tmp.player_pos.y += tmp.player_pos.diry * 0.1;
	}
	else if (key == 0) // a
	{
		tmp.player_pos.y -= tmp.player_pos.dirx * 0.1;
		tmp.player_pos.x += tmp.player_pos.diry * 0.1;
	}
	else if (key == 2) // d
	{
		tmp.player_pos.y += tmp.player_pos.dirx * 0.1;
		tmp.player_pos.x -= tmp.player_pos.diry * 0.1;
	}
	else if (key == 124) // ->
	{
		rotate_player(&tmp, ONE_DEG);
	}
	else if (key == 123) // <-
	{
		rotate_player(&tmp, -ONE_DEG);
	}
	set_plane(&tmp);
	x = 0;
	while (x < WIN_SIZE_W)
	{
		camera_x = 2 * x / (double)WIN_SIZE_W - 1;
		ray = raycast(&tmp, tmp.map, camera_x);
		if (ray.perp_wall_dist < 0.1 + 0.5)
			return (1);
		x++;
	}
	return (0);
}

void minimove(t_cub* cub, int key)
{
	float moveStep = 0.1;

	if (key == 1) // w
	{
		if (!check_wall_collision(cub, key))
		{
			cub->player_pos.x -= cub->player_pos.dirx * moveStep;
			cub->player_pos.y -= cub->player_pos.diry * moveStep;
		}
	}
	else if (key == 13) // s
	{
		if (!check_wall_collision(cub, key))
		{
			cub->player_pos.x += cub->player_pos.dirx * moveStep;
			cub->player_pos.y += cub->player_pos.diry * moveStep;
		}
	}
	else if (key == 0) // a
	{
		if (!check_wall_collision(cub, key))
		{
			cub->player_pos.y -= cub->player_pos.dirx * moveStep;
			cub->player_pos.x += cub->player_pos.diry * moveStep;
		}
	}
	else if (key == 2) // d
	{
		if (!check_wall_collision(cub, key))
		{
			cub->player_pos.y += cub->player_pos.dirx * moveStep;
			cub->player_pos.x -= cub->player_pos.diry * moveStep;
		}
	}
	else if (key == 124) // ->
	{
		rotate_player(cub, ONE_DEG);
	}
	else if (key == 123) // <-
	{
		rotate_player(cub, -ONE_DEG);
	}
}

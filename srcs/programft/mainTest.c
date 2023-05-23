/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/23 02:02:03 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

// chiudi e libera

void	close_game(t_cub *cub, char *mex)
{
	int i;

	if (!cub->mlx)
		exit(1);
	if (!cub->win)
		exit(1);
	mlx_destroy_window(cub->mlx, cub->win);
	freematrix(cub->map, row_counter(cub->map));
	freematrix(cub->mat_tmp, row_counter(cub->mat_tmp));
	// freematrix(cub->minimap, row_counter(cub->minimap));
	if (cub->str_tmp)
		free(cub->str_tmp);
	if (!cub->data)
		exit(1);
	free(cub->data);
	i = 0;
	while (i < 4)
		if (cub->wall_imgs_addrs[i++])
			free(cub->wall_imgs_addrs[i - 1]);
	fprintf(stderr, "\033[0;32m Quitting Cube: %s\033[0;37m\n", mex);
	exit(0);
}

// exit call per l'hook

int	exit_call(t_cub *cub)
{
	close_game(cub, "Closed program");
	return (0);
}

int	move(int key, t_cub *cub)
{
	cub->key_state[key] = 1;
	if (key == 53)			//tasto associato all esc
	{
		exit_call(cub);
	}
	return (1);
}

int	stop_motion(int key, t_cub* cub)
{
	cub->key_state[key] = 0;
	return (0);
}

void	draw_everything(t_cub* cub)
{
	if (draw_minimap(cub))
		close_game(cub, "\033[1;31mMap Error");
	draw_player(cub, 0., 0., 0., 0);
}

void	define_player_orientation(t_cub* cub)
{
	if (cub->map[(int)cub->player_pos.x][(int)cub->player_pos.y] == 'N')
	{
		cub->player_pos.dirx = 1;
		cub->player_pos.diry = 0;
	}
	else if (cub->map[(int)cub->player_pos.x][(int)cub->player_pos.y] == 'S')
	{
		cub->player_pos.dirx = -1;
		cub->player_pos.diry = 0;	
	}
	else if (cub->map[(int)cub->player_pos.x][(int)cub->player_pos.y] == 'E')
	{
		cub->player_pos.dirx = 0;
		cub->player_pos.diry = -1;	
	}
	else if (cub->map[(int)cub->player_pos.x][(int)cub->player_pos.y] == 'W')
	{
		cub->player_pos.dirx = 0;
		cub->player_pos.diry = 1;
	}
}

void	define_player_stats(t_cub* cub)
{
	define_player_pos(cub);
	define_player_orientation(cub);
}


// int main(int argc, char **argv)
// {
// 	t_cub	cub;

// 	if (argc < 2)
// 		return (1);
// 	if (!game_init(&cub))
// 		close_game(&cub, "\033[1;31mInit error");
// 	if (!parser(file_validator(argv[1]), &cub))
// 		exit(printf("NO\n"));
// 	render(&cub);

// 	define_player_stats(&cub);
// 	add_map_padding(&cub);
// 	draw_everything(&cub);

// 	mlx_do_key_autorepeaton(cub.mlx);
// 	mlx_hook(cub.win, 17, 0, exit_call, &cub);
// 	mlx_hook(cub.win, 2, 0, move, &cub);
// 	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
// 	mlx_loop_hook(cub.mlx, game_loop, &cub);
// 	mlx_loop(cub.mlx);
// 	return (0);
// }

void	draw_wall(t_cub *cub, int x, float wall_height)
{
	printf("%f\n", wall_height);
	int wall_top = ((WIN_SIZE_H / 2) - (wall_height * TILE_SIZE / 2));
	int wall_bottom = ((WIN_SIZE_H / 2) + (wall_height * TILE_SIZE / 2));

	for (int y = 0; y <= WIN_SIZE_H; y++) 
	{
		//sky grey
		if (y < wall_top)
			my_mlx_pixel_put(cub->data, x, y, 0x00afafaf);
		//floor red
		else if (y > wall_bottom)
			my_mlx_pixel_put(cub->data, x, y, 0x00ee5555);
		//wall green
		else
			my_mlx_pixel_put(cub->data, x, y, 0x0011aa11);
	}
}

int	render0(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	for (int x = 0; x <= WIN_SIZE_W; x++)
	{
		float ray_angle = (((cub->player_pos.angle) - (FOV_ANGLE / 2)) + (((float)x / WIN_SIZE_W) * FOV_ANGLE));
		float distance_to_wall = 0.f;
		float step_size = 0.1f;

		while (distance_to_wall < 100)
		{
			float test_x = cub->player_pos.x + distance_to_wall * cos((ray_angle / 180) * M_PI);
			float test_y = cub->player_pos.y + distance_to_wall * sin((ray_angle / 180) * M_PI);

			if (cub->map[((int)test_y)][((int)test_x)] == '1')
				break ;
			
			distance_to_wall += step_size;
		}
		
		float wall_height = (distance_to_wall / TILE_SIZE) * ((float)(WIN_SIZE_W / 2) / (float)tan(((FOV_ANGLE / 180) * M_PI) / 2));

		draw_wall(cub, x , wall_height);
		// add_walls(cub);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
	return (0);
}

int	game_loop(t_cub* cub)
{
	if (cub->key_state[13])
		minimove(cub, 13);
	if (cub->key_state[0])
		minimove(cub, 0);
	if (cub->key_state[1])
		minimove(cub, 1);
	if (cub->key_state[2])
		minimove(cub, 2);
	if (cub->key_state[124])
		minimove(cub, 124);
   	if (cub->key_state[123])
		minimove(cub, 123);
	render0(cub);
	return (0);
}

int	main(int argc, char **argv) 
{
	t_cub	cub;

	if (argc != 2)
		return (1);
	if (!game_init(&cub))
		close_game(&cub, "\033[1;31mInit error");
	if (!parser(file_validator(argv[1]), &cub))
		exit(printf("NO\n"));
	
	define_player_orientation(&cub);

	cub.player_pos.dirx = 0;
	cub.player_pos.dirx = 1;
	cub.player_pos.angle = 0;
	mlx_do_key_autorepeaton(cub.mlx);
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
	mlx_loop_hook(cub.mlx, game_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

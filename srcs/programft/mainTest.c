/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/26 19:04:35 by sgerace          ###   ########.fr       */
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

int	game_loop(t_cub* cub)
{
	int	key;

	if (cub->key_state[13])
	{
		minimove(cub, 13);
		key = 13;
	}
	if (cub->key_state[0])
	{
		minimove(cub, 0);
		key = 0;
	}
	if (cub->key_state[1])
	{
		minimove(cub, 1);
		key = 1;
	}
	if (cub->key_state[2])
	{
		minimove(cub, 2);
		key = 2;
	}
	if (cub->key_state[124])
	{
		minimove(cub, 124);
		key = 124;
	}
   	if (cub->key_state[123])
	{
		minimove(cub, 123);
		key = 123;
	}
	draw_game(cub);
	draw_minimap(cub);
	draw_player(cub, 0., 0., 0., key);
	return (0);
}

int	move(int key, t_cub *cub)
{
	cub->key_state[key] = 1;
	if (key == 53)
	{
		exit_call(cub);
	}
	// game_loop(cub);
	return (1);
}

int	stop_motion(int key, t_cub* cub)
{
	cub->key_state[key] = 0;
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
	// if (!import_elements(&cub))
	// 	close_game(&cub, "\033[1;31mParse Error");

	define_player_pos(&cub);
	define_player_orientation(&cub);
	set_plane(&cub);

	draw_game(&cub);
	draw_minimap(&cub);
	draw_player(&cub, 0., 0., 0., 13);
	
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
	mlx_loop_hook(cub.mlx, game_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

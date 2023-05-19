/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/19 12:03:03 by sgerace          ###   ########.fr       */
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
	printf("Key: %d\n", key);
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
		cub->player_pos.dirx = -1;
		cub->player_pos.diry = 0;
	}
	else if (cub->map[(int)cub->player_pos.x][(int)cub->player_pos.y] == 'S')
	{
		cub->player_pos.dirx = 1;
		cub->player_pos.diry = 0;	
	}
	else if (cub->map[(int)cub->player_pos.x][(int)cub->player_pos.y] == 'E')
	{
		cub->player_pos.dirx = 0;
		cub->player_pos.diry = 1;	
	}
	else if (cub->map[(int)cub->player_pos.x][(int)cub->player_pos.y] == 'W')
	{
		cub->player_pos.dirx = 0;
		cub->player_pos.diry = -1;	
	}
}

void	define_player_stats(t_cub* cub)
{
	define_player_pos(cub);
	define_player_orientation(cub);
}

int	game_loop(t_cub* cub)
{
	if (cub->key_state[13])
	{
		minimove(cub, 13);
	}
	if (cub->key_state[0])
	{
		minimove(cub, 0);
	}
	if (cub->key_state[1])
	{
		minimove(cub, 1);
	}
	if (cub->key_state[2])
	{
		minimove(cub, 2);
	}
	if (cub->key_state[124])
	{
		minimove(cub, 124);
	}
   	if (cub->key_state[123])
	{
		minimove(cub, 123);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_cub	cub;

	if (argc < 2)
		return (1);
	if (!game_init(&cub))
		close_game(&cub, "\033[1;31mInit error");
	if (!parser(file_validator(argv[1]), &cub))
		exit(printf("NO\n"));
	render(&cub);

	define_player_stats(&cub);
	add_map_padding(&cub);
	draw_everything(&cub);

	mlx_do_key_autorepeaton(cub.mlx);
	mlx_hook(cub.win, 17, 0, exit_call, &cub);
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
	mlx_loop_hook(cub.mlx, game_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

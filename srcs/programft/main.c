/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/16 22:58:24 by sgerace          ###   ########.fr       */
=======
/*   Updated: 2023/05/16 21:11:05 by sgerace          ###   ########.fr       */
>>>>>>> 4f2f74dfc07f18ef1ad8fdcc60e90ee378ffc4de
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

// inizzializza array statici

// void	init_statics(t_cub *cub)
// {
// 	int i;

// 	i = 0;
// 	while (i < 5)
// 		cub->wall_imgs_addrs[i++] = NULL;
// 	i = 0;
// 	while (i < 4)
// 		cub->wall_imgs[i++] = NULL;
// 	cub->mat_tmp = NULL;
// 	cub->str_tmp = NULL;
// }

int	move(int key, t_cub *cub)
{
	if (key == 13)
	{
		minimove(cub, key);
		printf("w");
	}
	else if (key == 0)
	{
		minimove(cub, key);
		printf("a");
	}
	else if (key == 1)
	{
		minimove(cub, key);
		printf("s");
	}
	else if (key == 2)
	{
		minimove(cub, key);
		printf("d");
	}
	printf("\n");
	return (1);
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
	// pause();
	render(&cub);
	printf("avadachedabra\n");
	printf("avadachedabra\n");
	printf("avadachedabra\n");

	printf("ualsjfoiaj\n");

	add_map_padding(&cub);
	define_player_pos(&cub);
	if (draw_minimap(&cub))
		close_game(&cub, "\033[1;31mMap Error");

	mlx_do_key_autorepeaton(cub.mlx);
	mlx_hook(cub.win, 17, 0, exit_call, &cub);
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

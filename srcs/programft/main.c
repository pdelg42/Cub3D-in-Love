/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/13 19:38:22 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char g_minimappa[8][18] = {
	"    1111111111111\0",
	"    10001   11111\0",
	"111110001   10011\0",
	"1001100111111111 \0",
	"1001100000011    \0",
	"1001100000011    \0",
	"1001111110011    \0",
	"1111111111111    \0"
};
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

void	init_statics(t_cub *cub)
{
	int i;

	i = 0;
	while (i < 5)
		cub->wall_imgs_addrs[i++] = NULL;
	i = 0;
	while (i < 4)
		cub->wall_imgs[i++] = NULL;
	cub->mat_tmp = NULL;
	cub->str_tmp = NULL;
}

int	move(int key, t_cub *cub)
{
	if (key == 13)
		printf("w");
	if (key == 0)
		printf("a");
	if (key == 1)
		printf("s");
	if (key == 2)
		printf("d");
	printf("\n");
	return (1);
}

// inizializza le variabili mlx

int game_init(t_cub *cub)
{
	t_data	*d;

	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (0);
	cub->win = mlx_new_window(cub->mlx, WIN_SIZE_W, WIN_SIZE_H, "cub3d");
	if (!cub->win)
		return (0);
	d = (t_data *) ft_calloc(sizeof(t_data), 1);
	if (!d)
		return (0);
	cub->data = d;
	init_statics(cub);
	return (1);
}

// void define_player_position(t_cub *cub)
// {
// 	int rows;

// 	rows = row_counter(cub->map);
// 	int y = 0;
// 	while (y < rows)
// 	{
// 		int x = 0;
// 		while (cub->map[y][x])
// 		{
// 			if (cub->map[y][x] == 'N')
// 			{
// 				cub->player_pos = set_point(int2fixed(x), int2fixed(y));
// 				return ;
// 			}
// 		}
// 		y++;
// 	}
// }


// main

int main(int argc, char **argv)
{
	t_cub	cub;

	//inserimento manuale della minimappa per testing purpose
	cub.map = (char**)malloc(8 * sizeof(char*));
	for (int i = 0; i < 8; i++) 
	{
		cub.map[i] = (char*)malloc(18 * sizeof(char));
		strcpy(cub.map[i], g_minimappa[i]);
	}

	if (argc < 2)
		return (1);
	if (!game_init(&cub))
		close_game(&cub, "\033[1;31mInit error");
	if (!parse_map(&cub, argv[1]))
		close_game(&cub, "\033[1;31mParse Error");
	// define_player_pos(&cub);
	render(&cub);
	if (draw_minimap(&cub))
		close_game(&cub, "\033[1;31mMap Error");
	mlx_do_key_autorepeaton(cub.mlx);
	mlx_hook(cub.win, 17, 0, exit_call, &cub);
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/16 20:40:07 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char g_minimappa[15][34] = {
	"1111111111111111111111111        \0",
	"10000000001100N0000000001        \0",
	"1011000001110000000000001        \0",
	"1001000000000000000000001        \0",
	"111111111011000001110000000000001\0",
	"100000000011000001110111111111111\0",
	"11110111111111011100000010001    \0",
	"11110111111111011101010010001    \0",
	"11000000110101011100000010001    \0",
	"10000000000000001100000010001    \0",
	"10000000000000001101010010001    \0",
	"1100000111010101111101111000111  \0",
	"11110111 1110101 101111010001    \0",
	"11111111111111111111111111111    \0",
	"11111111 1111111 111111111111    \0"
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

	//inserimento manuale della minimappa per testing purpose
	cub.map = (char**)malloc((15 * sizeof(char*) + 1));
	int i;
	for (i = 0; i < 15; i++) 
	{
		cub.map[i] = (char*)malloc(34 * sizeof(char));
		strcpy(cub.map[i], g_minimappa[i]);
	}
	cub.map[i] = NULL;

	if (argc < 2)
		return (1);
	if (!game_init(&cub))
		close_game(&cub, "\033[1;31mInit error");
	if (!parser(file_validator(argv[1]), &cub))
		exit(printf("NO\n"));
	// pause();
	render(&cub);
	printf("Grazie Marî\n");

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

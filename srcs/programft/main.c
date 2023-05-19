/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/19 17:51:17 by gdel-giu         ###   ########.fr       */
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
	//left arrow
	if (key == 123)
		cub->player_angle -= 0.1;
	//right arrow
	if (key == 124)
		cub->player_angle += 0.1;
	if (key == 53)
		exit_call(cub);
	minimove(cub, key);
	draw2d(cub);
	return (1);
}

void	draw_shit(t_cub* cub)
{
	if (draw_minimap(cub))
		close_game(cub, "\033[1;31mMap Error");
	draw_player(cub);
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
	cub.map = list_to_matrix(&cub.fetched->map);
	player_img_init(&cub);
	render(&cub);
	// define_player_pos(&cub);

	// printf("Mini check player pos: %c\n", cub.map[(int)cub.player_pos.x][(int)cub.player_pos.y]);
	// add_map_padding(&cub);
	// draw_shit(&cub);
	draw2d(&cub);
	mlx_do_key_autorepeaton(cub.mlx);
	// mlx_loop_hook(cub.mlx, draw2d, &cub);
	mlx_hook(cub.win, 17, 0, exit_call, &cub);
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

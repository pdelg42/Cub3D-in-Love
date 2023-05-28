/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/28 11:47:36 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	start_game(t_cub* cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	draw_game(cub);
	draw_minimap(cub);
	draw_player(cub);
	return ;
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
	set_player_data(&cub);
	start_game(&cub);
	
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
	// mlx_loop_hook(cub.mlx, moves_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/06/05 13:55:40 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	start_game(t_cub *cub)
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
		exit(printf("Ritenta.\n"));
	init_graphic_info(&cub.graphic_info, &cub);
	insert_img(&cub);
	set_player_data(&cub);
	start_game(&cub);
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

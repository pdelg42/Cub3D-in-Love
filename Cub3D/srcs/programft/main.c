/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/31 21:18:15 by gdel-giu         ###   ########.fr       */
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
	{
		// pause();
		//close_game(&cub, "\033[1;31mInit error");
		//freematrix(cub.fetched->map_mtx, row_counter(cub.fetched->map_mtx));
		//freematrix(cub.fetched->paths_mtx, row_counter(cub.fetched->map_mtx));
		// free(cub.fetched->paths_mtx[0]);
		// cub.fetched->paths_mtx[0] = NULL;
		// free(cub.fetched->paths_mtx[1]);
		// cub.fetched->paths_mtx[1] = NULL;
		// free(cub.fetched->paths_mtx[2]);
		// cub.fetched->paths_mtx[2] = NULL;
		// free(cub.fetched->paths_mtx[3]);
		// cub.fetched->paths_mtx[3] = NULL;
		// free(cub.fetched->paths_mtx);
		//cub.fetched->paths_mtx = NULL;
		
		// freecontent(cub.fetched->map);
		// freelist(&cub.fetched->map);
		// printlist(&cub.fetched->checks);
		// freecontent(cub.fetched->checks);
		// freelist(&cub.fetched->checks);

		int i =0;
		while (cub.fetched->paths_mtx && i < 5)
			printf("%p\n", cub.fetched->paths_mtx[i++]);
		// printlist(&cub.fetched->map);
		//pause();
		exit(printf("NO\n"));
	}
	mlx_do_key_autorepeaton(cub.mlx);
	init_graphic_info(&cub.graphic_info, &cub);
	insert_img(&cub);
	set_player_data(&cub);
	start_game(&cub);
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

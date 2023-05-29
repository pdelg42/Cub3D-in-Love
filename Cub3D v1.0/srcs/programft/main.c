/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/28 17:17:42 by sgerace          ###   ########.fr       */
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

// void	init_img(t_graphic_info *graphic_info, t_cub* cub)
// {
// 	t_img_info	img_info;

// 	graphic_info->img = mlx_new_image(cub->mlx, WIN_SIZE_W, WIN_SIZE_H);
// 	img_info.buf = (unsigned int *)mlx_get_data_addr(graphic_info->img,
// 			&img_info.bpp,
// 			&img_info.size_line,
// 			&img_info.endian);
// 	graphic_info->img_info = img_info;
// }

// void	init_graphic_info(t_graphic_info *graphic_info, t_cub* cub)
// {
// 	int	i;

// 	init_img(graphic_info, cub);
// 	i = 0 - 1;
// 	while (++i < 4)
// 		graphic_info->texture[i] = NULL;
// 	return ;
// 	i = 0 - 1;
// 	while (++i < 2)
// 		graphic_info->color[i] = -1;
// }

// void	*make_img(void *mlx_ptr, char *xpmFile)
// {
// 	char	*path;
// 	void	*img;
// 	int		width;
// 	int		height;

// 	path = xpmFile;
// 	img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
// 	if (!img)
// 	{
// 		printf("XPM Error : check IMG_PATH or fileName");
// 	}
// 	return (img);
// }

// void	insert_img(t_cub* cub)
// {
// 	t_img_info	img_info;
// 	int			i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (i == 0)
// 			cub->graphic_info.texture[i] = make_img(cub->mlx, "/Users/sgerace/Desktop/Cub3D-in-Love/img/EA.xmp");
// 		else if (i == 1)
// 			cub->graphic_info.texture[i] = make_img(cub->mlx, "/Users/sgerace/Desktop/Cub3D-in-Love/img/NO.xmp");
// 		else if (i == 2)
// 			cub->graphic_info.texture[i] = make_img(cub->mlx, "/Users/sgerace/Desktop/Cub3D-in-Love/img/SO.xmp");
// 		else if (i == 3)
// 			cub->graphic_info.texture[i] = make_img(cub->mlx, "/Users/sgerace/Desktop/Cub3D-in-Love/img/WE.xmp");
// 		img_info.buf = (unsigned *)mlx_get_data_addr(cub->graphic_info.texture[i],
// 				&img_info.bpp, &img_info.size_line, &img_info.endian);
// 		cub->graphic_info.texture_info[i] = img_info;
// 		i++;
// 	}
// 	return ;
// }

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

	// init_graphic_info(&cub.graphic_info, &cub);
	// insert_img(&cub);

	set_player_data(&cub);
	start_game(&cub);
	
	mlx_hook(cub.win, 2, 0, move, &cub);
	mlx_hook(cub.win, 3, 0, stop_motion, &cub);
	// mlx_loop_hook(cub.mlx, moves_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

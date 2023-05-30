/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:21:13 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 18:13:27 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	init_img(t_graphic_info *graphic_info, t_cub *cub)
{
	t_img_info	img_info;

	graphic_info->img = mlx_new_image(cub->mlx, WIN_SIZE_W, WIN_SIZE_H);
	img_info.buf = (unsigned int *)mlx_get_data_addr(graphic_info->img,
			&img_info.bpp,
			&img_info.size_line,
			&img_info.endian);
	graphic_info->img_info = img_info;
}

void	init_graphic_info(t_graphic_info *graphic_info, t_cub *cub)
{
	int	i;

	init_img(graphic_info, cub);
	i = 0 - 1;
	while (++i < 4)
		graphic_info->texture[i] = NULL;
	return ;
	i = 0 - 1;
	while (++i < 2)
		graphic_info->color[i] = -1;
}

void	*make_img(void *mlx_ptr, char *xpmFile)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	path = xpmFile;
	img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	if (!img)
	{
		printf("XPM Error : check IMG_PATH or fileName");
	}
	return (img);
}

void	insert_img(t_cub *cub)
{
	t_img_info	img_info;
	int			i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			cub->graphic_info.texture[i] = make_img(cub->mlx, \
				"/Users/aperrone/Desktop/Cub3D-in-Love/Cub3D/img/EA.xpm");
		else if (i == 1)
			cub->graphic_info.texture[i] = make_img(cub->mlx, \
				"/Users/aperrone/Desktop/Cub3D-in-Love/Cub3D/img/NO.xpm");
		else if (i == 2)
			cub->graphic_info.texture[i] = make_img(cub->mlx, \
				"/Users/aperrone/Desktop/Cub3D-in-Love/Cub3D/img/SO.xpm");
		else if (i == 3)
			cub->graphic_info.texture[i] = make_img(cub->mlx, \
				"/Users/aperrone/Desktop/Cub3D-in-Love/Cub3D/img/WE.xpm");
		img_info.buf = \
			(unsigned *)mlx_get_data_addr(cub->graphic_info.texture[i],
				&img_info.bpp, &img_info.size_line, &img_info.endian);
		cub->graphic_info.texture_info[i] = img_info;
		i++;
	}
	return ;
}

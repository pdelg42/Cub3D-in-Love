/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 07:58:47 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/22 21:17:15 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	init_fetch(t_cub *cub)
{
	cub->fetched = malloc(sizeof(t_fetch));
	cub->fetched->paths = NULL;
	cub->fetched->colors = NULL;
	cub->fetched->map = NULL;
	cub->fetched->paths_mtx = NULL;
	cub->fetched->paths_mtx = NULL;
	cub->fetched->colors_str = NULL;
	cub->fetched->p_t = NULL;
	cub->fetched->len = 0;
	cub->fetched->checks = NULL;
	cub->player_existence = 0;
	cub->fetched->map_mtx = NULL;
	add_t(&cub->fetched->checks, new_("WE", 1));
	add_t(&cub->fetched->checks, new_("NO", 2));
	add_t(&cub->fetched->checks, new_("SO", 3));
	add_t(&cub->fetched->checks, new_("EA", 4));
	add_t(&cub->fetched->checks, new_("F ", 5));
	add_t(&cub->fetched->checks, new_("C ", 6));
	cub->player_pos.x = 0.;
	cub->player_pos.y = 0.;
}

void	init_statics(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 5)
		cub->wall_imgs_addrs[i++] = NULL;
	i = 0;
	while (i < 4)
		cub->wall_imgs[i++] = NULL;
	i = 0;
	while (i < KEY_COUNT)
		cub->key_state[i++] = 0;
	cub->mat_tmp = NULL;
	cub->str_tmp = NULL;
	cub->data->img = mlx_new_image(cub->mlx, WIN_SIZE_W, WIN_SIZE_H);
	cub->data->addr = mlx_get_data_addr(cub->data->img, 
	&cub->data->bits_per_pixel, &cub->data->line_length, &cub->data->endian);
	cub->player_pos.x = 5.f;
	cub->player_pos.y = 1.f;
	cub->player_pos.angle = 0.f;
}

int	game_init(t_cub *cub)
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
	init_fetch(cub);
	init_statics(cub);
	return (1);
}

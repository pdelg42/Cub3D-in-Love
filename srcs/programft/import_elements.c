/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:47:10 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/10 21:29:42 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub.h"

// define di colori per effettuare un fallback nel caso non si riesca ad
// aprire un immagine (da decidere se solo per debug o per feature)
// ci sará comunque il messaggio da prompt per la mancata apertura dell'immagine

#define FLBK_NO 0x00aa1111
#define FLBK_SO 0x00aa5555
#define FLBK_WE 0x00dd2222
#define FLBK_EA 0x00dd8888

// funzione da utilizzare per smistare i componenti ottenuti dal parsing
// in variabili e struct necessarie all'esecuzione

t_rgb *get_color_from_string(char *str)
{
	int i;
	char **tmp_mat;
	t_rgb *new_color;

	while (ft_isspace(*str) && *str != '\n' && *str != '\0')
		str++;
	if (!ft_isdigit(*str) && *str != '+')
		return (NULL);
	tmp_mat = ft_split(str, ',');
	if (!tmp_mat || row_counter(tmp_mat) != 3)
		return (NULL);
	i = 0;
	new_color = (t_rgb *) ft_calloc(sizeof(t_rgb), 1);
	while (tmp_mat[i])
	{
		if (!ft_isnum(tmp_mat[i]))
		{
			free(new_color);
			new_color = NULL;
			break;
		}
		tmp_mat[i] = ft_strtrim(tmp_mat[i], " \t");
		new_color->rgb = new_color->rgb << 8l;
		new_color->col_param = ft_clamp(a_(tmp_mat[i++], 10), 0, 255);
	}
	freematrix(tmp_mat, row_counter(tmp_mat));
	return (new_color);
}

int	is_color_type(char *str)
{
	return ((str[0] == 'C' || str[0] == 'F')
		&& str[1] == ' ');
}

int	validate_colors(t_cub *cub, char *str)
{
	int i;

	if (!str || !*str)
		return (0);
	cub->mat_tmp = ft_split(str, ':');
	if (row_counter(cub->mat_tmp) != 2)
		return (0);
	i = 0;
	while (i < 2)
	{
		cub->mat_tmp[i] = ft_strtrim(cub->mat_tmp[i], " \t");
		if (is_color_type(cub->mat_tmp[i]))
		{
			if (cub->mat_tmp[i][0] == 'C')
				cub->ceil_color = get_color_from_string(cub->mat_tmp[i] + 1);
			else
				cub->floor_color = get_color_from_string(cub->mat_tmp[i]  + 1);
		}
		else
			return (0);
		i++;
	}
	freematrix(cub->mat_tmp, row_counter(cub->mat_tmp));
	cub->mat_tmp = NULL;
	return (cub->ceil_color && cub->floor_color);
}

int	import_elements(t_cub *cub)
{
	int i;
	int sizes[2];

	if (row_counter(cub->wall_imgs_addrs) != 4 || !cub->str_tmp)
		return (0);
	if (!validate_colors(cub, cub->str_tmp))
		return (0);
	i = 0;
	while (cub->wall_imgs_addrs[i])
	{
		cub->wall_imgs[i] = mlx_xpm_file_to_image(cub->mlx,
		cub->wall_imgs_addrs[i], &sizes[0], &sizes[1]);
		if (!cub->wall_imgs[i++])
		{
			i = 0;
			while (cub->wall_imgs[i])
				mlx_destroy_image(cub->mlx, cub->wall_imgs[i]);
			return (0);
		}
	}
	free(cub->str_tmp);
	cub->str_tmp = NULL;
	return (1);
}

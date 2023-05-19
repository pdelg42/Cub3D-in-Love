/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:03:55 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/19 09:01:20 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	is_void(char **map, int i, int k)
{
	if (map[i - 1][k] == ' ' || !map[i - 1][k]
		|| map[i + 1][k] == ' ' || !map[i + 1][k]
		|| map[i][k - 1] == ' ' || !map[i][k - 1]
		|| map[i][k + 1] == ' ' || !map[i][k + 1])
		return (1);
	return (0);
}

int	is_player(t_cub **cub, char c, int i, int k)
{
	if (c == 'N' || c == 'S' || c == 'E'|| c == 'W')
	{
		printf("isplayer\n");
		(*cub)->player_existence++;
		// (*cub)->player_pos.x = k;
		// (*cub)->player_pos.y = i;
		return (1);
	}
	return (0);
}

int	map_normalizer(t_cub **cub)
{
	char	*to_normalize;
	int		len;
	int		temp;
	t_node	*map_;

	map_ = (*cub)->fetched->map;
	len = (*cub)->fetched->map->prev->id;
	while (map_ && len--)
	{
		temp = (*cub)->fetched->len - ft_strlen(map_->box);
		to_normalize = malloc(temp);
		ft_memset(to_normalize, '0', temp);
		to_normalize[temp] = 0;
		map_->box = ft_strjoin(map_->box, to_normalize);
		free(to_normalize);
		map_ = map_->next;
	}
	(*cub)->map = list_to_matrix(&(*cub)->fetched->map);
	return (1);
}

int	map_checks(t_cub **cub)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while ((*cub)->fetched->map_mtx[++i])
	{
		if (first_last((*cub)->fetched->map_mtx[i], &k))
		{
			while ((*cub)->fetched->map_mtx[i][++(k)])
				if ((*cub)->fetched->map_mtx[i][(k)] == '0'
				|| is_player(cub, (*cub)->fetched->map_mtx[i][(k)], i, (k)))
					if (is_void((*cub)->fetched->map_mtx, i, (k)))
						return (0);
		}
		else
			return (0);
	}
	if ((*cub)->player_existence == 1)
	{
		freecontent((*cub)->fetched->map);
		freelist(&(*cub)->fetched->map);
		(*cub)->fetched->map = matrix_to_list((*cub)->fetched->map_mtx);
		freematrix((*cub)->fetched->map_mtx, row_counter((*cub)->fetched->map_mtx));
		return (1);
	}
	return (0);
}

int	map_validator(t_cub **cub)
{
	int	i;
	int	len;

	(*cub)->fetched->p_t = (*cub)->fetched->map;
	len = (*cub)->fetched->map->prev->id;
	while ((*cub)->fetched->p_t && len--)
	{
		i = -1;
		while ((*cub)->fetched->p_t->box[++i])
			if (!valid_char((*cub)->fetched->p_t->box[i]))
				return (0);
		(*cub)->fetched->p_t = (*cub)->fetched->p_t->next;
	}
	(*cub)->fetched->map_mtx = list_to_matrix(&(*cub)->fetched->map);
	return (1);
}

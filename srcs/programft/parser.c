/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/17 01:12:08 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void		info_checks(t_node *info, t_fetch *fetched)
{
	if (presence_validator(info, fetched) == 6)
	{
		info_adjust(&info, fetched);
		// printlist(&info);
		// printlist(&fetched->map);
		// pause();
		printf("continua ad eseguire\n");
	}
	else
		printf("Invalid information\n");
}

int	map_normalizer(t_fetch **fetched)
{
	char	*to_normalize;
	int		len;
	int		temp;
	t_node	*map_;

	map_ = (*fetched)->map;
	len = (*fetched)->map->prev->id;
	while (map_ && len--)
	{
		temp = (*fetched)->len - ft_strlen(map_->box);
		to_normalize = malloc(temp);
		ft_memset(to_normalize, '0', temp);
		to_normalize[temp] = 0;
		map_->box = ft_strjoin(map_->box, to_normalize);
		free(to_normalize);
		map_ = map_->next;
	}
	return (1);
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
	(*cub)->map = list_to_matrix(&(*cub)->fetched->map);
	return (1);
}

int	map_checks(t_cub **cub)
{
	int	i;
	int	k;

	i = 0;
	while ((*cub)->map[++i])
	{
		if (first_last((*cub)->map[i]))
		{
			k = 0;
			{
				while ((*cub)->map[i][++k])
				{
					if ((*cub)->map[i][k] == '0')
					{
						if (((*cub)->map[i - 1][k] == ' '
							|| ((*cub)->map[i + 1][k] == ' '))
							|| ((*cub)->map[i][k - 1] == ' '
							|| (*cub)->map[i][k + 1] == ' '))
							return (0);
					}
				}
			}
		}
	}
	return (1);
}

int	build_information(int fd, t_node **info, t_cub **cub)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			if (i < 6)
				add_t(info, new_(ft_strtrim(line, " \t\n"), ++i));
			else
			{
				add_t(&(*cub)->fetched->map,
					new_(ft_strtrim(line, " \t\n"), ++i));
				if ((*cub)->fetched->len < ft_strlen(line))
					(*cub)->fetched->len = ft_strlen(line) - 1;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	relister(&(*cub)->fetched->map);
	if (wall_line((*cub)->fetched->map->box)
		&& wall_line((*cub)->fetched->map->prev->box))
		if (map_validator(cub))
			if (map_checks(cub))
				pause(); 
				// if (map_normalizer(&(*cub)->fetched))
				// 	return (1);
	return (0);
}

int	parser(int fd, t_cub *cub)
{
	t_node	*info;

	info = NULL;
	if (fd > 0)
	{
		if (build_information(fd, &info, &cub))
			info_checks(info, cub->fetched);
		else
			return (0);
		printlist(&info);
		printlist(&cub->fetched->map);
		// cub->map = list_to_matrix(&cub->fetched->map);
		return (1);
	}
	return (0);
}

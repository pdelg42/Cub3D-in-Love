/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/16 19:56:45 by aperrone         ###   ########.fr       */
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

int	map_validator(t_fetch **fetched)
{
	int	i;
	int	len;

	(*fetched)->p_t = (*fetched)->map;
	len = (*fetched)->map->prev->id;
	while ((*fetched)->p_t && len--)
	{
		i = -1;
		while ((*fetched)->p_t->box[++i])
			if (!valid_char((*fetched)->p_t->box[i]))
				return (0);
		(*fetched)->p_t = (*fetched)->p_t->next;
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
				add_t(&(*cub)->fetched->map, new_(ft_strtrim(line, " \t\n"), ++i));
				if ((*cub)->fetched->len < ft_strlen(line))
					(*cub)->fetched->len = ft_strlen(line) - 1;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	relister(&(*cub)->fetched->map);
	if (map_validator(&(*cub)->fetched))
		if (map_normalizer(&(*cub)->fetched))
			return (1);
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
		cub->map = list_to_matrix(&cub->fetched->map);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/19 12:04:19 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int		info_checks(t_node *info, t_fetch *fetched)
{
	if (presence_validator(info, fetched) == 6)
		if (info_adjust(&info, fetched))
			return (1);
	return (0);
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
				if (map_normalizer(cub))
					return (1);
	return (0);
}

int	parser(int fd, t_cub *cub)
{
	t_node	*info;

	info = NULL;
	if (fd > 0)
		if (build_information(fd, &info, &cub))
			if(info_checks(info, cub->fetched))
				return (1);
	return (0);
}

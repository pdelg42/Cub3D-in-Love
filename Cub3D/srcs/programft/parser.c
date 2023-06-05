/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/05 16:00:41 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	info_checks(t_node **info, t_fetch *fetched)
{
	if (presence_validator(*info, fetched) == 6)
		if (info_adjust(info, fetched))
			if (relist_information(info, fetched))
				return (1);
	return (0);
}

void	sub_information(t_node **info, char *temp, int *i, t_cub **cub)
{
	if (*i < 6)
		add_t(info, new_(temp, ++(*i)));
	else
		add_t(&(*cub)->fetched->map,
			new_(temp, ++(*i)));
}

int	map_checker(t_cub **cub, t_node **info)
{
	if (!(*cub)->fetched->map || !*info)
		return (0);
	relister(&(*cub)->fetched->map);
	if (wall_line((*cub)->fetched->map->box)
		&& wall_line((*cub)->fetched->map->prev->box))
		if (map_validator(cub))
			if (map_checks(cub, 0))
				if (map_normalizer(cub))
					return (1);
	return (0);
}

int	build_information(int fd, t_node **info, t_cub **cub, int i)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			temp = ft_strtrim(line, " \t\n");
			sub_information(info, temp, &i, cub);
			if ((*cub)->fetched->len < (int)ft_strlen(line))
				(*cub)->fetched->len = ft_strlen(line) - 1;
			free(temp);
		}
		else if (!ft_strcmp(line, "\n") && i > 6)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (map_checker(cub, info))
		return (1);
	return (0);
}

int	parser(int fd, t_cub *cub)
{
	t_node	*info;

	info = NULL;
	if (fd > 0)
		if (build_information(fd, &info, &cub, 0))
			if (info_checks(&info, cub->fetched))
				if (split_info(info, &cub))
					return (1);
	freecontent(info);
	freelist(&info);
	return (0);
}

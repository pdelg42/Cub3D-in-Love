/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/29 14:30:03 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	rgb_fetcher(t_cub *cub, int piece, int i)
{
	int		r;
	int		g;
	int 	b;
	char	hex[9];

	if (i )
}

int		split_info(t_node *info, t_cub **cub)
{
	t_node	*temp;
	int		i;
	int		piece;
	char	c[4];


	hex[0] = '0';
	hex[1] = 'x';
	hex[8] = '\0';

	(*cub)->graphic_info.texture = list_to_matrixDest(&info, 4);
	temp = info;
	i = 1;
	while (temp && i++ < 5)
		temp = temp->next;
	while (temp && i++ < 7)
	{
		int k = 0;
		ft_memset(c, 0, ft_strlen(c));
		printf("c: %s\n", c);
		while (!ft_isdigit(temp->box[k]))
			k++;
		printf("k: %d\n", k);
		int	h = 0;
		while (ft_isdigit(temp->box[k]))
		{
			if (h > 2)
				return (0);
			c[h] = temp->box[k++];
			printf("c: %c\n", c[h]);
			h++;
		}
		c[h] = 0;
		printf("c: %s\n", c);
		piece = a_(c, 10);
		printf("piece: %d\n", piece);
		pause();
	}
	pause();
	return (0);
}

int		info_checks(t_node *info, t_fetch *fetched)
{
	if (presence_validator(info, fetched) == 6)
		if (info_adjust(&info, fetched))
		{
			printlist(&info);
			// pause();
		}
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
			if (info_checks(info, cub->fetched))
				if (split_info(info, &cub))
					return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 13:10:21 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	hex_converter(int value, char *color)
{
	int	x;
	int	y;

	x = value / 16;
	y = value % 16;
	if (x < 10)
		color[0] = x + '0';
	else
		color[0] = x - 10 + 'A';
	if (y < 10)
		color[1] = y + '0';
	else
		color[1] = y - 10 + 'A';

}

int	rgb_fetcher(t_cub **cub, char c[4], int nvalue)
{
	char	hex[9];
	int		f;

	f = 0;
	if (nvalue == 1)
		(*cub)->coloR.r = a_(c, 10);
	if (nvalue == 2)
		(*cub)->coloR.g = a_(c, 10);
	if (nvalue == 3)
	{
		hex[0] = '0';
		hex[1] = 'x';
		(*cub)->coloR.b = a_(c, 10);
		hex_converter((*cub)->coloR.r, &hex[2]);
		hex_converter((*cub)->coloR.g, &hex[4]);
		hex_converter((*cub)->coloR.b, &hex[6]);
		hex[8] = 0;
		printf("hex: %s\n", hex);
	}
	return (1);
}

int	value_builder(char *box, int *k, int *h, char c[4])
{
	ft_memset(c, 0, ft_strlen(c));
	*h = 0;
	while (ft_isdigit(box[(*k)]))
	{
		if (*h > 2)
			return (0);
		c[*h] = box[(*k)++];
		(*h)++;
	}
	c[*h] = 0;
	return (1);
}

int skip_char(char *box, int *k, int *nvalue)
{
	while (!ft_isdigit(box[*k]))
		(*k)++;
	(*nvalue)++;
	return (1);
}

int	rgb_builder(t_cub **cub, t_node *temp, int *i) 
{
	int		k;
	int		h;
	int		value;
	int		nvalue;
	char	c[4];

	while (temp && (*i)++ < 7)
	{
		k = -1;
		nvalue = 0;
		while (temp->box[++k] && nvalue < 3)
			if (skip_char(temp->box, &k, &nvalue))
				if (value_builder(temp->box, &k, &h, c))
					if (!rgb_fetcher(cub, c, nvalue))
						return (0);
		temp = temp->next;
	}
	//pause();
	return (1);
}

int		split_info(t_node *info, t_cub **cub)
{
	t_node	*temp;
	int		i;

	// (*cub)->graphic_info.texture = list_to_matrixDest(&info, 4);
	temp = info;
	i = 0;
	while (temp && i++ < 4)
		temp = temp->next;
	rgb_builder(cub, temp, &i);
	//pause();
	return (1);
}

int		info_checks(t_node *info, t_fetch *fetched)
{
	if (presence_validator(info, fetched) == 6)
		if (info_adjust(&info, fetched))
		{
			printlist(&info);
			// //pause();
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

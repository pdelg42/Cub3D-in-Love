/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 17:12:33 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	rgb_control(char *box)
{
	int	i;

	i = 1;
	while (box[++i])
		if (!ft_isdigit(box[i]) && box[i] != ',')
			return (0);
	return (1);
}

int	rgb_fetcher(t_cub **cub, char c[4], int nvalue, int i)
{
	if (nvalue == 1)
		(*cub)->coloR.r = a_(c, 10);
	if (nvalue == 2)
		(*cub)->coloR.g = a_(c, 10);
	if (nvalue == 3)
	{
		(*cub)->coloR.b = a_(c, 10);
		if (i == 6)
			(*cub)->floor_color = (*cub)->coloR.r << 16
				| (*cub)->coloR.g << 8 | (*cub)->coloR.b;
		else
			(*cub)->ceil_color = (*cub)->coloR.r << 16
				| (*cub)->coloR.g << 8 | (*cub)->coloR.b;
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

int	skip_char(char *box, int *k, int *nvalue)
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
	int		nvalue;
	char	c[4];

	while (temp && (*i)++ < 7)
	{
		k = -1;
		nvalue = 0;
		while (temp->box[++k] && nvalue < 3)
			if (!rgb_control(temp->box)
				|| !skip_char(temp->box, &k, &nvalue)
				|| !value_builder(temp->box, &k, &h, c)
				|| !rgb_fetcher(cub, c, nvalue, *i))
				return (0);
		temp = temp->next;
	}
	return (1);
}

int		split_info(t_node *info, t_cub **cub)
{
	t_node	*temp;
	int		i;

	(*cub)->fetched->paths_mtx = malloc(sizeof(char *) * 5);
	(*cub)->fetched->paths_mtx[0] = ft_substr(info->box, 3,
			ft_strlen(info->box));
	(*cub)->fetched->paths_mtx[1] = ft_substr(info->next->box, 3,
			ft_strlen(info->box));
	(*cub)->fetched->paths_mtx[2] = ft_substr(info->next->next->box, 3,
			ft_strlen(info->box));
	(*cub)->fetched->paths_mtx[3] = ft_substr(info->next->next->next->box, 3,
			ft_strlen(info->box));
		(*cub)->fetched->paths_mtx[4] = NULL;
	temp = info;
	i = 0;
	while (temp && i++ < 4)
		temp = temp->next;
	if (rgb_builder(cub, temp, &i))
	{
		return (1);
	}
	return (0);
}

int		info_checks(t_node **info, t_fetch *fetched)
{
	if (presence_validator(*info, fetched) == 6)
		if (info_adjust(info, fetched))
			if (relist_information(info, fetched))
				return (1);
	return (0);
}

int	build_information(int fd, t_node **info, t_cub **cub)
{
	char	*line;
	int		i;
	char	*temp;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			temp = ft_strtrim(line, " \t\n");
			if (i < 6)
				add_t(info, new_(temp, ++i));
			else
			{
				add_t(&(*cub)->fetched->map,
					new_(temp, ++i));
				if ((*cub)->fetched->len < (int)ft_strlen(line))
					(*cub)->fetched->len = ft_strlen(line) - 1;
			}
			free(temp);
		}
		free(line);
		line = get_next_line(fd);
	}
	relister(&(*cub)->fetched->map);
	if (wall_line((*cub)->fetched->map->box)
		&& wall_line((*cub)->fetched->map->prev->box))
		if (map_validator(cub))
			if (map_checks(cub))
				{
					if (map_normalizer(cub))
						return (1);
					//pause();
				}
	return (0);
}

int	parser(int fd, t_cub *cub)
{
	t_node	*info;

	info = NULL;
	if (fd > 0)
		if (build_information(fd, &info, &cub))
			if (info_checks(&info, cub->fetched))
				if (split_info(info, &cub))
					return (1);
	freecontent(info);
	freelist(&info);
	return (0);
}

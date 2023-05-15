/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/14 11:41:49 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/map_parsing.h"

void	build_to_compare(char *temp, char *box)
{
	temp[0] = box[0];
	temp[1] = box[1];
	temp[2] = '\0';
}

int	box_compare(int *i, t_node *p_checks, char *temp)
{
	if (!ft_strcmp(temp, p_checks->box))
	{
		if (p_checks->status == 0)
		{
			p_checks->status = 1;
			(*i)++;
		}
		else
			return (0);
	}
	return (1);
}

int	presence_validator(t_node *info, t_fetch *fetched)
{
	t_node	*p_checks;
	int		checks_len;
	char	temp[3];
	int		i;

	fetched->p_t = info;
	fetched->len = 6;
	p_checks = fetched->checks;
	i = 0;
	while (fetched->p_t && fetched->len--)
	{
		build_to_compare(temp, fetched->p_t->box);
		checks_len = 6;
		while (p_checks && checks_len--)
		{
			if (box_compare(&i, p_checks, temp))
				p_checks = p_checks->next;
			else
				return (0);
		}
		fetched->p_t = fetched->p_t->next;
	}
	return (i);
}

int		info_checks(t_node *info, t_fetch *fetched)
{
	if (presence_validator(info, fetched) == 6)
	{
		printf("continua ad eseguire\n");
		return (1);
	}
	else
		printf("Invalid information\n");
	return (0);
}

void	build_information(int fd, t_node **info, t_node **map)
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
				add_t(info, new_(ft_strtrim(line, " '\t'"), ++i));
			else
				add_t(map, new_(line, ++i));
		}
		free(line);
		line = get_next_line(fd);
	}
	relister(map);
}

int	parser(int fd, t_cub *cub)
{
	t_node	*info;

	info = NULL;
	if (fd > 0)
	{
		build_information(fd, &info, &cub->fetched->map);
		info_checks(info, cub->fetched);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 04:48:42 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/15 13:42:47 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

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

void	cpychar(char c, char **out)
{
	char	c_[2];

	c_[0] = c;
	c_[1] = '\0';
	*out = ft_strjoin(*out, c_);
}

char	*line_reparator(char *box)
{
	int		i;
	int		flag;
	char	*out;

	i = 0;
	flag = 0;
	out = malloc(1);
	out[0] = 0;
	while (box[i])
	{
		if (ft_isspace(box[i]) && flag == 0)
		{
			flag = 1;
			cpychar(box[i], &out);
		}
		else if (ft_isspace(box[i]) && flag == 1)
		{
			i++;
			continue ;
		}
		else
			cpychar(box[i], &out);
		i++;
	}
	return (out);
}

void	info_adjust(t_node **info, t_fetch *fetched)
{
	char	*temp;

	fetched->p_t = *info;
	fetched->len = 6;
	while (fetched->p_t && fetched->len--)
	{
		temp = line_reparator(fetched->p_t->box);
		free(fetched->p_t->box);
		fetched->p_t->box = ft_strdup(temp);
		free(temp);
		fetched->p_t = fetched->p_t->next;
	}
}

int		info_checks(t_node *info, t_fetch *fetched)
{
	if (presence_validator(info, fetched) == 6)
	{
		info_adjust(&info, fetched);
		printlist(&info);
		printlist(&fetched->map);
		pause();
		printf("continua ad eseguire\n");
		return (1);
	}
	else
		printf("Invalid information\n");
	return (0);
}

void	map_normalizer(t_fetch **fetched)
{
	char	*to_normalize;
	int		len;
	int		temp;

	(*fetched)->p_t = (*fetched)->map;
	len = (*fetched)->map->prev->id;
	while ((*fetched)->p_t && len--)
	{
		temp = (*fetched)->len - ft_strlen((*fetched)->p_t->box);
		to_normalize = malloc(temp);
		ft_memset(to_normalize, '0', temp);
		to_normalize[temp] = 0;
		(*fetched)->p_t->box = ft_strjoin((*fetched)->p_t->box, to_normalize);
		free(to_normalize);
		(*fetched)->p_t = (*fetched)->p_t->next;
	}
}

int	map_checks(t_fetch **fetched)
{
	int	i;

	(*fetched)->p_t = (*fetched)->map;
	(*fetched)->len = (*fetched)->map->prev->id;
	while ((*fetched)->p_t && (*fetched)->len--)
	{
		i = 0;
	}
}

void	build_information(int fd, t_node **info, t_fetch **fetched)
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
				add_t(info, new_(ft_strtrim(line, " '\t''\n'"), ++i));
			else
			{
				add_t(&(*fetched)->map, new_(ft_strtrim(line, "'\n'"), ++i));
				if ((*fetched)->len < ft_strlen(line))
					(*fetched)->len = ft_strlen(line) - 1;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	relister(&(*fetched)->map);
	map_checks(fetched);
	//map_normalizer(fetched);
}

int	parser(int fd, t_cub *cub)
{
	t_node	*info;

	info = NULL;
	if (fd > 0)
	{
		build_information(fd, &info, &cub->fetched);
		info_checks(info, cub->fetched);
		return (1);
	}
	return (0);
}

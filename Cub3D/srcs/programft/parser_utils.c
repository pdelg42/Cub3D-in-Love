/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:51:15 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 16:51:48 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

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
			ft_cpychar(box[i], &out);
		}
		else if (ft_isspace(box[i]) && flag == 1)
		{
			i++;
			continue ;
		}
		else
			ft_cpychar(box[i], &out);
		i++;
	}
	return (out);
}

int	info_adjust(t_node **info, t_fetch *fetched)
{
	char	*temp;

	fetched->p_t = *info;
	fetched->len = MAX_MAP_PARAMS;
	while (fetched->p_t && fetched->len--)
	{
		temp = line_reparator(fetched->p_t->box);
		free(fetched->p_t->box);
		fetched->p_t->box = NULL;
		fetched->p_t->box = ft_strdup(temp);
		free(temp);
		temp = NULL;
		fetched->p_t = fetched->p_t->next;
	}
	return (1);
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

void	build_to_compare(char *temp, char *box)
{
	temp[0] = box[0];
	temp[1] = box[1];
	temp[2] = '\0';
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

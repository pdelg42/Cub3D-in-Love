/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:45:24 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/05 15:46:55 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

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

int	split_info(t_node *info, t_cub **cub)
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
		return (1);
	return (0);
}

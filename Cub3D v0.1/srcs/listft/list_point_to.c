/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_point_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:14:59 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/03/03 15:13:43 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	list_point_to(t_node **list, int id)
{
	int	len;

	if (!list || !*list)
		return ;
	len = len_list(list);
	while ((*list)->id != id && len--)
		*list = (*list)->next;
}

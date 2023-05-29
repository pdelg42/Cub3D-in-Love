/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:27:46 by aperrone          #+#    #+#             */
/*   Updated: 2023/01/11 14:05:46 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	del_t(t_node **h)
{
	t_node	*tmp;

	if (*h == NULL)
		return ;
	if ((*h)->next == *h)
	{
		free(*h);
		*h = NULL;
	}
	else
	{
		tmp = (*h)->prev;
		tmp->prev->next = *h;
		(*h)->prev = tmp->prev;
		free(tmp);
	}
}

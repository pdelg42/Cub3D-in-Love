/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_h.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:36:19 by aperrone          #+#    #+#             */
/*   Updated: 2023/02/12 14:54:34 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	del_h(t_node **h)
{
	t_node	*temp;
	t_node	*next;

	if (*h == NULL)
		return ;
	if ((*h)->next == *h)
	{
		free (*h);
		*h = NULL;
	}
	else
	{
		temp = *h;
		next = temp->next;
		*h = next;
		next->prev = temp->prev;
		temp->prev->next = next;
		free(temp);
	}
	temp = NULL;
}

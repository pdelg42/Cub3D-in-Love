/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_h.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:35:01 by aperrone          #+#    #+#             */
/*   Updated: 2023/01/11 13:30:26 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	add_h(t_node **h, t_node *node)
{
	if (*h == NULL)
		*h = node;
	else
	{
		(*h)->prev->next = node;
		node->prev = (*h)->prev;
		node->next = (*h);
		(*h)->prev = node;
		(*h) = node;
	}
}

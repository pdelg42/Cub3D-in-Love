/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:35:44 by aperrone          #+#    #+#             */
/*   Updated: 2023/01/06 19:01:43 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	add_t(t_node **h, t_node *node)
{
	if (*h == NULL)
		*h = node;
	else
	{
		(*h)->prev->next = node;
		node->prev = (*h)->prev;
		node->next = (*h);
		(*h)->prev = node;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:39 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/04 22:06:18 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

static void	del_node_null(t_node *current, t_node **stack)
{
	free(current);
	*stack = NULL;
}

static void	del_node_sub(t_node *current)
{
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
}

void	del_node(t_node **stack, int n)
{
	t_node	*current;

	current = *stack;
	if (current->id == n && current->next != *stack)
	{
		*stack = (*stack)->next;
		current->prev->next = *stack;
		(*stack)->prev = current->prev;
		free (current);
	}
	else if (current->id == n && current->next == *stack)
		del_node_null(current, stack);
	else
	{
		while (current)
		{
			if (current->id == n)
			{
				del_node_sub(current);
				break ;
			}
			current = current->next;
		}
	}
}

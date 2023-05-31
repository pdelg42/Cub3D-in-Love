/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_relister.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:47:50 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 10:53:46 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	reverse(t_node **stack)
{
	if ((*stack))
	{
		if ((*stack)->next == (*stack)->prev)
			(*stack) = (*stack)->next;
		else
			(*stack) = (*stack)->next;
	}
}

t_node	*cpyn(t_node *node)
{
	t_node	*temp;

	temp = new_(ft_strdup(node->box), node->id);
	return (temp);
}

void	push(t_node **from, t_node **to)
{
	t_node	*temp;

	if (*from)
	{
		temp = cpyn(*from);
		del_h(from);
		add_h(to, temp);
	}
}

void	skipper(t_node **info, t_node **temp, t_node **fetched, char identifier)
{
	while ((*fetched)->box[0] != identifier)
	{
		reverse(info);
		*fetched = *info;
	}
	push(info, temp);
}

int	relist_information(t_node **info, t_fetch *fetched)
{
	t_node	*temp;

	temp = NULL;
	fetched->p_t = *info;
	skipper(info, &temp, &fetched->p_t, 'N');
	skipper(info, &temp, &fetched->p_t, 'S');
	skipper(info, &temp, &fetched->p_t, 'W');
	skipper(info, &temp, &fetched->p_t, 'E');
	skipper(info, &temp, &fetched->p_t, 'F');
	fetched->p_t = temp;
	fetched->len = 5;
	while (fetched->p_t && fetched->len--)
		push(&temp, info);
	relister(info);
	printf("hererelist\n");
	printlist(info);
	return (1);
}

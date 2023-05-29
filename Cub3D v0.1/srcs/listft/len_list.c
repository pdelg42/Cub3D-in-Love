/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:11:23 by aperrone          #+#    #+#             */
/*   Updated: 2023/02/01 17:15:43 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	len_list(t_node	**stack)
{
	t_node	*tmp;
	int		i;

	i = 1;
	if (*stack)
	{
		tmp = *stack;
		while (tmp->next != *stack && i++)
			tmp = tmp->next;
		return (i++);
	}
	return (0);
}

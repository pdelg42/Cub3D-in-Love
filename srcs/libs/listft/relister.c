/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relister.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:09:14 by aperrone          #+#    #+#             */
/*   Updated: 2023/02/21 06:59:46 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	relister(t_node **h)
{
	t_node	*tmp;
	int		i;

	if (*h)
	{
		i = 0;
		tmp = (*h);
		while (tmp->next != *h && ++i)
		{
			tmp->id = i;
			tmp = tmp->next;
		}
		tmp->id = ++i;
	}
}

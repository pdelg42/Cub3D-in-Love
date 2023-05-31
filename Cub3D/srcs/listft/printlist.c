/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:09:14 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 10:49:34 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	printlist(t_node **h)
{
	t_node	*tmp;

	if (!*h)
	{
		write(1, "emptyList\n", 11);
		return ;
	}
	tmp = *h;
	while (tmp->next != *h)
	{
		printf("[%3d][%s]\n", tmp->id, tmp->box);
		tmp = tmp->next;
	}
	printf("[%3d][%s]\n", tmp->id, tmp->box);
}

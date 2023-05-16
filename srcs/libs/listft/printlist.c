/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:09:14 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/11 18:25:59 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/listft.h"

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
		printf("[%3d][%s][%s][%d]\n", tmp->id, tmp->box, tmp->type, tmp->status);
		tmp = tmp->next;
	}
	printf("[%3d][%s][%s][%d]\n", tmp->id, tmp->box, tmp->type, tmp->status);
}

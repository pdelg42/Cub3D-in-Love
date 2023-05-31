/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freenode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:17:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 21:17:00 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	freenode(t_node	*h)
{
	t_node	*temp;
	int		len;

	len = h->prev->id;
	temp = h;
	while (temp && len--)
	{
		free(temp->box);
		free(temp->type);
		temp->box = NULL;
		temp->type = NULL;
		temp = temp->next;
	}
}

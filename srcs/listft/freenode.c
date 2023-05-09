/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freenode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:17:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/03 15:23:40 by aperrone         ###   ########.fr       */
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

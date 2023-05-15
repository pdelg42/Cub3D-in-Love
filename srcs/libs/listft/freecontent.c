/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freecontent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 08:22:14 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/05 09:58:10 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	freecontent(t_node	*h)
{
	t_node	*temp;
	int		len;

	if (h)
	{
		len = h->prev->id;
		temp = h;
		while (temp && len--)
		{
			free(temp->box);
			temp->box = NULL;
			temp = temp->next;
		}
	}
}

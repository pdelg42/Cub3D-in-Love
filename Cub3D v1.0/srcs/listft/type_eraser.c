/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_eraser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:26:31 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/06 14:46:20 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	type_eraser(t_node *h)
{
	t_node	*skppr;
	int		len;

	if (h)
	{
		skppr = h;
		len = h->prev->id;
		while (skppr && len--)
		{
			free(skppr->type);
			skppr->type = NULL;
			skppr = skppr->next;
		}
	}
}

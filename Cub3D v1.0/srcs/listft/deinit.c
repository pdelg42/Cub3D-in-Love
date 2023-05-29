/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:35:44 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/03 15:27:08 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	deinit(t_node *node)
{
	node->box = NULL;
	node->id = 0;
	node->next = NULL;
	node->prev = NULL;
}

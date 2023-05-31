/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:26:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 15:23:42 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

t_node	*new_(char *content, int id)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	temp->id = id;
	temp->status = 0;
	temp->box = ft_strdup(content);
	temp->type = NULL;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}

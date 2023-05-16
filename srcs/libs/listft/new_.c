/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:26:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/04 22:06:27 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/listft.h"

t_node	*new_(char *content, int id)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	temp->id = id;
	temp->status = 0;
	temp->box = ft_strdup(content);
	temp->type = key_fetcher(content);
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}

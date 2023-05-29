/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_in_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:34:02 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/03/09 23:26:35 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	src_in_list(t_node	**h, char *field)
{
	int	len;

	if (*h)
	{
		len = len_list(h);
		while (len--)
		{
			if (!ft_strcmp((*h)->type, field))
			{
				relister(h);
				return (1);
			}
			(*h) = (*h)->next;
		}
	}
	return (0);
}

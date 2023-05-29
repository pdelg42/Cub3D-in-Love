/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:14:30 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/29 11:22:09 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char	**list_to_matrix(t_node **head)
{
	t_node	*temp;
	char	**matrix;
	int		len;
	int		i;

	len = (*head)->prev->id;
	matrix = malloc(sizeof(char *) * len + 1);
	temp = *head;
	i = 0;
	while (temp && len--)
	{
		matrix[i] = ft_strdup(temp->box);
		i++;
		temp = temp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

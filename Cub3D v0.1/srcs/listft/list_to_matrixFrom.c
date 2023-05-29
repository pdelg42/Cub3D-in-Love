/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrixFrom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:14:30 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/29 11:55:14 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char	**list_to_matrixFrom(t_node **head, int from)
{
	t_node	*temp;
	char	**matrix;
	int		len;
	int		i;

	len = (*head)->prev->id - from;
	matrix = malloc(sizeof(char *) * len + 1);
	temp = *head;
	i = 0;
	while (temp && from--)
		temp = temp->next;
	while (temp && len--)
	{
		matrix[i] = ft_strdup(temp->box);
		i++;
		temp = temp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}
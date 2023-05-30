/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrixFrom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:14:30 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 13:50:07 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char	**list_to_matrix_from(t_node **head, int from)
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

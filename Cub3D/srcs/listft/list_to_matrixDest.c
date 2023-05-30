/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrixDest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:14:30 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 13:46:09 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char	**list_to_matrix_dest(t_node **head, int dest)
{
	t_node	*temp;
	char	**matrix;
	int		i;

	matrix = malloc(sizeof(char *) * dest + 1);
	temp = *head;
	i = 0;
	while (temp && dest--)
	{
		matrix[i] = ft_strdup(temp->box);
		i++;
		temp = temp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

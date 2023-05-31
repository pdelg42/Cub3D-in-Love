/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrixDest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:14:30 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 17:58:31 by gdel-giu         ###   ########.fr       */
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

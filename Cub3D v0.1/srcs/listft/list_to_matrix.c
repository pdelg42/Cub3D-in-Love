/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:14:30 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/24 00:52:33 by gdel-giu         ###   ########.fr       */
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

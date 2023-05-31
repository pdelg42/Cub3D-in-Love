/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:25:24 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 16:38:57 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

t_node	*matrix_to_list(char **matrix)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (matrix[i])
		add_t(&temp, new_((matrix[i++]), 0));
	relister(&temp);
	return (temp);
}

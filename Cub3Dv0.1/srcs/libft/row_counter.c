/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:50:43 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/05 03:11:48 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	row_counter(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

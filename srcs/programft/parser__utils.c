/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:03:55 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/18 18:33:37 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

int	first_last(char *box, int *k)
{
	(*k) = 0;
	if (box[0] == '1' && box[ft_strlen(box) - 1] == '1')
		return (1);
	return (0);
}

int	wall_line(char *box)
{
	int	i;

	i = -1;
	while (box[++i])
		if (box[i] != '1' && box[i] != ' ')
			return (0);
	return (1);
}

int	valid_char(char c)
{
	if (c != '1'
		&& c != '0'
		&& c != ' '
		&& c != 'N'
		&& c != 'S'
		&& c != 'E'
		&& c != 'W')
		return (0);
	return (1);
}

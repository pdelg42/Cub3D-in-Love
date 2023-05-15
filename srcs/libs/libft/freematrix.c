/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freematrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:27:14 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/10 12:53:27 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	freematrix(char **splitted, int i)
{
	int	k;

	if (splitted)
	{
		k = -1;
		while (++k < i)
		{
			free(splitted[k]);
			splitted[k] = ((void *)0);
		}
		free(splitted);
	}
	splitted = ((void *)0);
}

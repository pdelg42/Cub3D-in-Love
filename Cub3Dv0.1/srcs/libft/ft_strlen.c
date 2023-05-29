/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:46:21 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/16 18:13:05 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (*str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

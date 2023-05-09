/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:46:21 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/01 11:32:23 by aperrone         ###   ########.fr       */
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

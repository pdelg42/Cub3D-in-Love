/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:17:01 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 14:11:37 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;

	if (!b)
		return (NULL);
	i = b;
	while (len > 0)
	{
		*i++ = (unsigned char)c;
		len--;
	}
	return (b);
}

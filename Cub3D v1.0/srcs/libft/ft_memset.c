/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:17:01 by aperrone          #+#    #+#             */
/*   Updated: 2022/01/14 15:23:53 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

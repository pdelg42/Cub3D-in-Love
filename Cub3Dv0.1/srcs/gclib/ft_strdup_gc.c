/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:03:42 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/12 22:28:00 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*from;

	dest = dst;
	from = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*dest++ = *from++;
	}
	return (dst);
}

char	*ft_strdup_m(t_garbage **garbage, const char *s1)
{
	size_t	dim;
	char	*stack;

	if (s1 == NULL)
		return (NULL);
	dim = ft_strlen(s1) + 1;
	stack = gc_alloc(garbage, (sizeof(char) * dim), dim);
	if (s1 == NULL)
		return (NULL);
	else
		ft_memcpy(stack, s1, dim);
	return (stack);
}

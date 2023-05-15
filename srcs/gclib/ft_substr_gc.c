/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:06:17 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/12 22:06:43 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/gc.h"

char	*ft_substr_m(t_garbage **garbage, char const *s, t_xsubstr sub)
{
	char	*stack;
	int		i;

	i = 0;
	sub.len--;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= (size_t)sub.i)
		sub.i = ft_strlen(s);
	if (ft_strlen(s) <= (size_t)sub.i + (size_t)sub.len)
	{
		sub.len = ft_strlen(s) - (size_t)sub.i;
	}
	stack = gc_alloc(garbage, (sizeof(char) * sub.len + 2), sub.len + 2);
	if (!stack)
		return (NULL);
	while (1 + sub.len--)
		stack[i++] = s[sub.i++];
	stack[i] = '\0';
	return (stack);
}


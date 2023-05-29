/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:05:59 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/12 22:06:06 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char	*ftm_strjoin_utils(int flag, char const *s1, char const *s2)
{
	if (flag == 1)
	{
		if (!s2)
			return (NULL);
		return ((char *)s2);
	}
	if (flag == 2)
	{
		if (!s1)
			return (NULL);
		return ((char *)s1);
	}
	return (NULL);
}

char	*ftm_strjoin(t_garbage **garb, char const *s1, char const *s2, int flag)
{
	size_t		len1;
	size_t		len2;
	size_t		i;
	char		*stack;

	if (flag == 1 || flag == 2)
		return (ftm_strjoin_utils(flag, s1, s2));
	else
	{
		if (!s1 || !s2)
			return (NULL);
		i = 0;
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		stack = gc_alloc(garb, (sizeof(char) * (len1 + len2 + 1)), 1);
		if (!stack)
			return (NULL);
		while (*s1 != '\0')
			stack[i++] = *s1++;
	}
	while (*s2 != '\0')
		stack[i++] = *s2++;
	stack[i] = '\0';
	return (stack);
}

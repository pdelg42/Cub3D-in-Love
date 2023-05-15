/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_gc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:33:26 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/12 20:34:41 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/gc.h"

static int	ft_inset(int c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_gc(t_garbage** gc, const char *s1, const char *set)
{
	size_t	i;
	size_t	s;
	size_t	e;
	char	*str;

	s = 0;
	while (s1[s] && ft_inset(s1[s], set))
			s++;
	e = ft_strlen(s1);
	while (e > s && ft_inset(s1[e - 1], set))
		e--;
	str = gc_alloc(gc, (sizeof(*s1) * (e - s + 1)), 0);
	// str = (char *)malloc(sizeof(*s1) * (e - s + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s < e)
		str[i++] = s1[s++];
	str[i] = 0;
	free((char *)s1);
	s1 = NULL;
	return (str);
}

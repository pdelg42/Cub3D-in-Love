/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:03:10 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/12 22:27:17 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/gc.h"

static int	wc(const char *s, char c)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 0;
	while (*s)
	{
		if (*s != c && toggle == 0)
		{
			toggle = 1;
			i++;
		}
		else if (*s == c)
			toggle = 0;
		s++;
	}
	return (i);
}

static char	*wd(t_garbage** gc, const char *s, int begin, int end)
{
	char	*word;
	int		i;

	i = 0;
	// word = malloc((end - begin + 1) * sizeof(char));
	word = gc_alloc(gc, (end - begin + 1) * sizeof(char), 0);
	while (begin < end)
		word[i++] = s[begin++];
	word[i] = '\0';
	return (word);
}

char	**ftm_split(t_garbage** gc, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	// split = malloc((wc(s, c) + 1) * sizeof(char *));
	split = gc_alloc(gc, (wc(s, c) + 1) * sizeof(char *), 0);
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = wd(gc, s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

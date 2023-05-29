/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:46:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/15 23:00:12 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

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

static char	*wd(const char *s, int begin, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - begin + 1) * sizeof(char));
	while (begin < end)
		word[i++] = s[begin++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((wc(s, c) + 1) * sizeof(char *));
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
			split[j++] = wd(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

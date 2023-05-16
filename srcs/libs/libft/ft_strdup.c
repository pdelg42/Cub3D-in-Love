/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:02:01 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/10 04:42:23 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;

	if (!s1)
		return ((void *) 0);
	ret = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

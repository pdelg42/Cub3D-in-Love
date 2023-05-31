/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:02:01 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 20:53:39 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;

	if (!s1)
		return ((void *) 0);
	ret = ft_calloc(sizeof(*s1), (ft_strlen(s1) + 1));
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:56:19 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 15:49:08 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*sum;

	sum = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sum)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		sum[i++] = s1[j++];
	j = 0;
	while (s2[j])
		sum[i++] = s2[j++];
	sum[i] = '\0';
	free((char *)s1);
	return (sum);
}

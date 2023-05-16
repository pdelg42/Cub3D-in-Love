/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fetcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:14:13 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/06 23:27:04 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/listft.h"

char	*key_fetcher(char *content)
{
	int		i;
	char	*temp;


	i = -1;
	temp = malloc(sizeof(char) * 256);
	while (content[++i] && content[i] != '=')
		temp[i] = content[i];
	temp[i] = 0;
	return (temp);
}

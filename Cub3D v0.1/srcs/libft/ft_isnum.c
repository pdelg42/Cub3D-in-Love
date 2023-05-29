/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:33:56 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/12 20:08:22 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/libft.h"

int	ft_isnum(char *str)
{
	int i;

	i = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	while (*str && i < 3 && ++i)
	{
		if (!ft_isdigit(*str))
			break ;
		str++ ;
	}
	while (*str != '\0')
		if (!ft_isspace(*str++))
			return (0);
	return (1);
}
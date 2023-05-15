/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:43:27 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/10 21:25:53 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"

int	base(int c, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if (c == "0123456789abcdef"[i] || c == "0123456789ABCDEF"[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_sign(char sign)
{
	if (sign > '9' || sign < '0')
		return(0);
	return (1);
}

long long	a_(char *str, int len_base)
{
	int			i;
	long long	nbr;
	int			sig;

	i = 0;
	nbr = 0;
	sig = 1;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	if (str[i] == '+')
	{
		sig = 1;
		i++;
	}
	// check_sign(str[i]);
	while (base(str[i], len_base) != -1)
	{
		nbr = nbr * len_base;
		nbr = nbr + base(str[i], len_base);
		i++;
	}
	return ((long long)(nbr * sig));
}

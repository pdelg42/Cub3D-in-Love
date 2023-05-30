/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 03:26:20 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 13:48:54 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_clamp(const int val, const int min, const int max)
{
	if (val > max)
		return (max);
	if (val < min)
		return (min);
	return (val);
}

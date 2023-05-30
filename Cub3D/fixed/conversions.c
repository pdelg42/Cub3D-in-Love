/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:36:36 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 16:50:38 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.h"

float	fixed2flo(t_fixed8 fixed)
{
	return ((float)((float)fixed / (1 << 8)));
}

int	fixed2int(t_fixed8 fixed)
{
	return ((int)(fixed / (1 << 8)));
}

t_fixed8	int2fixed(int val)
{
	t_fixed8	fixed;

	fixed = val * (1 << 8);
	return (fixed);
}

t_fixed8	flo2fixed(float val)
{
	t_fixed8	fixed;

	fixed = val * (1 << 8);
	return (fixed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:11:18 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 16:47:11 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.h"

t_fixed8	fixabs(t_fixed8 val)
{
	if ((int) val < 0)
		return (val * -1);
	return (val);
}

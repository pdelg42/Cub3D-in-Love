/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:50:31 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 13:45:44 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/point.h"

t_point	point_delta(t_point p1, t_point p2)
{
	t_point	pdelta;

	pdelta.x = fixabs(fixsub(p1.x, p2.x));
	pdelta.y = fixabs(fixsub(p1.y, p2.y));
	return (pdelta);
}

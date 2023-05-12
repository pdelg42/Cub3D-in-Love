/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:50:31 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/12 22:49:05 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/point.h"

t_point	point_delta(t_point p1, t_point p2)
{
	t_point pdelta;

	pdelta.x = fixabs(fixsub(p1.x, p2.x));
	pdelta.y = fixabs(fixsub(p1.y, p2.y));
	return (pdelta);
}

// t_point	set_point(t_fixed8 x, t_fixed8 y)
// {
// 	t_point p;

	
// 	return ()
// }
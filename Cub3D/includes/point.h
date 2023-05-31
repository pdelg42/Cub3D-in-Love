/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:30:31 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 16:45:33 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "../fixed/fixed.h"
# include "libft.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
}	t_point;

t_point	point_delta(t_point p1, t_point p2);
// t_point	set_point(t_fixed8 x, t_fixed8 y);

#endif
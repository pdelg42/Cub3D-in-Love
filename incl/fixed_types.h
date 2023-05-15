#ifndef FIXED_TYPES_H
# define FIXED_TYPES_H
# include "cub.h"

typedef unsigned int t_fixed8;

typedef struct s_point
{
	t_fixed8 x;
	t_fixed8 y;
} t_point;

t_point	point_delta(t_point p1, t_point p2);
// t_point	set_point(t_fixed8 x, t_fixed8 y);
#endif //FIXED_TYPES_H

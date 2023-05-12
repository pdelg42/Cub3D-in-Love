#include "fixed.h"

float	fixed2flo(t_fixed8 fixed)
{
	return ((float) ((float) fixed / (1 << 8)));
}

int	fixed2int(t_fixed8 fixed)
{
	return ((int) (fixed / (1 << 8)));
}

t_fixed8	int2fixed(int val)
{
	t_fixed8 fixed;
	fixed = val * (1 << 8);
	return (fixed);
}

t_fixed8	flo2fixed(float val)
{
	t_fixed8 fixed;
	fixed = val * (1 << 8);
	return (fixed);	
}
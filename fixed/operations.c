#include "fixed.h"

t_fixed8    fixsum(t_fixed8 a, t_fixed8 b)
{
    return (a + b);
}

t_fixed8    fixsub(t_fixed8 a, t_fixed8 b)
{
    return (a - b);
}

t_fixed8    fixmul(t_fixed8 a, t_fixed8 b)
{
    return (a * b >> 8);
}

t_fixed8    fixdiv(t_fixed8 a, t_fixed8 b)
{
    return (((a << 8) / b));
}

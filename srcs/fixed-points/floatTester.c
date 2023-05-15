#include "_incl/fixed.h"
#include <stdio.h>

int main() {
    t_fixed8 f1;
    t_fixed8 f2;

    f1 = flo2fixed(2.5);
    f2 = flo2fixed(14.5);
    printf("%f\n", fixed2flo(fixdiv(f2, f1)));
    return (0);
}

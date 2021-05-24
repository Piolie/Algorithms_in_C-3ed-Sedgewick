/* ---------------------------------------------------------------------
                              EXERCISE 2.13
------------------------------------------------------------------------
Write an efficient C function that computes ceil[lg lg N]. Do not use a
library function.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
If
    n = ceil[lg lg N]
then
    n >= lg lg N
so, we need to find the smallest integer n such that
    2^(2^n) >= N.
--------------------------------------------------------------------- */

#include <stdio.h>

unsigned long long int power(unsigned int base, unsigned char exponent)
{
    /* warning: 0^0 is undefined; however, we still return 1 */
    if (exponent == 0)
        return 1;
    else
        return base*power(base, exponent-1);
}

unsigned long long int ceil_lg_lg(unsigned int n)
{
    unsigned long long int ceil;
    for (ceil = 0; power(2, power(2, ceil)) < n; ceil++);
    return ceil;
}

int main(void)
{
    unsigned int N;
    for (N = 2; N <= 257; N++)
        printf("ceil[lg lg %u] = %llu\n", N, ceil_lg_lg(N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
ceil[lg lg 2] = 0
ceil[lg lg 3] = 1
ceil[lg lg 4] = 1
ceil[lg lg 5] = 2
        .
        .
        .
ceil[lg lg 16] = 2
ceil[lg lg 17] = 3
        .
        .
        .
ceil[lg lg 256] = 3
ceil[lg lg 257] = 4
        .
        .
        .
ceil[lg lg 65536] = 4
ceil[lg lg 65537] = 5
        .
        .
        .
ceil[lg lg 4294967296] = 5
ceil[lg lg 4294967297] = 6

--------------------------------------------------------------------- */

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

unsigned long long power(unsigned int base, unsigned char exponent)
{
    /* warning: 0^0 is undefined; however, we will still return 1 */
    if (exponent == 0)
        return 1;
    else
        return base*power(base, exponent-1);
}

unsigned long long ceil_lg_lg(unsigned int n)
{
    unsigned long long ceil;
    for (ceil = 0; power(2, power(2, ceil)) < n; ceil++);
    return ceil;
}

int main(void)
{
    unsigned int N;
    for (N = 2; N > 1; N*=2)
        printf("ceil[lg lg %u] = %llu\n", N, ceil_lg_lg(N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Note: the condition that ends the for loop, N > 1, works because N,
being an unsigned int, wraps around when assigned a value greater than
2^32 - 1 (= 4294967295). In this case, we try to assign it 2^32, and the
result ends up being 0, breaking the loop.

Note that this might not happen if N was a signed int: strictly
speaking, overflow of signed integers is undefined behavior.

------------------------------------------------------------------------

ceil[lg lg 2] = 0
ceil[lg lg 4] = 1
ceil[lg lg 8] = 2
ceil[lg lg 16] = 2
ceil[lg lg 32] = 3
ceil[lg lg 64] = 3
ceil[lg lg 128] = 3
ceil[lg lg 256] = 3
ceil[lg lg 512] = 4
ceil[lg lg 1024] = 4
ceil[lg lg 2048] = 4
ceil[lg lg 4096] = 4
ceil[lg lg 8192] = 4
ceil[lg lg 16384] = 4
ceil[lg lg 32768] = 4
ceil[lg lg 65536] = 4
ceil[lg lg 131072] = 5
ceil[lg lg 262144] = 5
ceil[lg lg 524288] = 5
ceil[lg lg 1048576] = 5
ceil[lg lg 2097152] = 5
ceil[lg lg 4194304] = 5
ceil[lg lg 8388608] = 5
ceil[lg lg 16777216] = 5
ceil[lg lg 33554432] = 5
ceil[lg lg 67108864] = 5
ceil[lg lg 134217728] = 5
ceil[lg lg 268435456] = 5
ceil[lg lg 536870912] = 5
ceil[lg lg 1073741824] = 5
ceil[lg lg 2147483648] = 5

--------------------------------------------------------------------- */

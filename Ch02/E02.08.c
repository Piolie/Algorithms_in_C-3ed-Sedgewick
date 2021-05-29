/* ---------------------------------------------------------------------
                              EXERCISE 2.8
------------------------------------------------------------------------
What is the smallest value of N for which log_10 (log_10 (N)) > 8?
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
log_10 (log_10 (N)) > 8
log_10 (N) > 10^8
N > 10^(10^8)

This is, like, a big number. See: https://en.wikipedia.org/wiki/Orders_of_magnitude_(numbers)#101000_to_1010100_(one_googolplex)
for some numbers in this order of magnitude.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(void)
{
    unsigned long long N;
    double f;
    for (N = 1; N < ULLONG_MAX; N++)
    {
        f = log(log(N));
        if (f > 8)
        {
            printf("Bingo!: %llu\n", N);
            break;
        }
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Bingo!: (LIES! ;-))

--------------------------------------------------------------------- */

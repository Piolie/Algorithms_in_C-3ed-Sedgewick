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
    unsigned long long n;
    double f;
    for (n = 1; n < ULLONG_MAX; n++)
    {
        f = log(log(n));
        if (f > 8)
        {
            printf("Bingo!: %llu\n", n);
            break;
        }
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Bingo!: (LIES!)

--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                              EXERCISE 2.6
------------------------------------------------------------------------
For what values of N is N^(3/2) between N(lg N)^2/2 and 2N(lg N)^2?
--------------------------------------------------------------------- */

#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(void)
{
    unsigned long long n;
    double f, g, h;
    const double log2 = log(2);
    for (n = 1; n < ULLONG_MAX; n++)
    {
        HN = log(n)/log2
        f = pow(sqrt(n), 3);        /* N^(3/2)      */
        g = n*pow(log(n)/log2,2)/2; /* N(lg N)^2/2  */
        h = 2*n*pow(log(n)/log2,2); /* 2N(lg N)^2   */
        if ((g < f) && (f < h))
            printf("In range: %llu\n", n);
        if ((h < f) && (f < g))
            printf("In range: %llu\n", n);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
In range: 2
In range: 3
In range: 6381
    .
    .
    .
In range: 519978

--------------------------------------------------------------------- */

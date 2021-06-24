/* ---------------------------------------------------------------------
                              EXERCISE 3.3
------------------------------------------------------------------------
Test the random-number generator on your system by generating N random
numbers of type double between 0 and 1, transforming them to integers
between 0 and r - 1 by multiplying by r and truncating the result, and
computing the average and standard deviation for r = 10, 100, and 1000
and N = 10^3, 10^4, 10^5, and 10^6.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* There is no double random number generator in the standard library.
I got the following one from https://stackoverflow.com/a/33059025.
It relies on rand(), so it's very low quality. */
double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main(void)
{
    for (int r = 10; r <= 1000; r *= 10)
    {
        printf("r = %d:\n", r);
        for (int N = 1000; N <= 1000000; N *= 10)
        {
            float m1 = 0, m2 = 0;
            printf("\tN = %d:\n", N);
            for (int i = 0; i < N; i++)
            {
                double d = randfrom(0, 1);
                int x = (int)(d*r);
                m1 += ((float)x)/N;
                m2 += ((float)x*x)/N;
            }
            printf("\t\t     Avg.: %f\n", m1);
            printf("\t\tStd. dev.: %f\n", sqrt(m2 - m1*m1));
        }
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
r = 10:
        N = 1000:
                     Avg.: 4.501000
                Std. dev.: 2.870175
        N = 10000:
                     Avg.: 4.543756
                Std. dev.: 2.869494
        N = 100000:
                     Avg.: 4.510306
                Std. dev.: 2.868591
        N = 1000000:
                     Avg.: 4.498960
                Std. dev.: 2.875373
r = 100:
        N = 1000:
                     Avg.: 51.259007
                Std. dev.: 28.724513
        N = 10000:
                     Avg.: 49.101334
                Std. dev.: 28.924382
        N = 100000:
                     Avg.: 49.517731
                Std. dev.: 28.881882
        N = 1000000:
                     Avg.: 49.555664
                Std. dev.: 28.820045
r = 1000:
        N = 1000:
                     Avg.: 489.583862
                Std. dev.: 286.982551
        N = 10000:
                     Avg.: 501.992798
                Std. dev.: 289.517298
        N = 100000:
                     Avg.: 498.855316
                Std. dev.: 288.977724
        N = 1000000:
                     Avg.: 499.639801
                Std. dev.: 288.386189

--------------------------------------------------------------------- */

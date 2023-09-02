/* ---------------------------------------------------------------------
                              EXERCISE 3.2
------------------------------------------------------------------------
Test the random-number generator on your system by generating N random
integers between 0 and r - 1 with rand() % r and computing the average
and standard deviation for r = 10, 100, and 1000 and N = 10^3 , 10^4,
10^5, and 10^6.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  for (int r = 10; r <= 1000; r *= 10) {
    printf("r = %d:\n", r);
    for (int N = 1000; N <= 1000000; N *= 10) {
      float m1 = 0, m2 = 0;
      printf("\tN = %d:\n", N);
      for (int i = 0; i < N; i++) {
        int x = rand() % r;
        m1 += ((float)x) / N;
        m2 += ((float)x * x) / N;
      }
      printf("\t\t     Avg.: %f\n", m1);
      printf("\t\tStd. dev.: %f\n", sqrt(m2 - m1 * m1));
    }
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
r = 10:
        N = 1000:
                     Avg.: 4.444999
                Std. dev.: 2.849016
        N = 10000:
                     Avg.: 4.497745
                Std. dev.: 2.879851
        N = 100000:
                     Avg.: 4.496019
                Std. dev.: 2.871670
        N = 1000000:
                     Avg.: 4.501384
                Std. dev.: 2.875611
r = 100:
        N = 1000:
                     Avg.: 50.268970
                Std. dev.: 29.685621
        N = 10000:
                     Avg.: 49.905460
                Std. dev.: 28.830619
        N = 100000:
                     Avg.: 49.545715
                Std. dev.: 28.841888
        N = 1000000:
                     Avg.: 49.505642
                Std. dev.: 28.804318
r = 1000:
        N = 1000:
                     Avg.: 489.627960
                Std. dev.: 282.060582
        N = 10000:
                     Avg.: 500.123566
                Std. dev.: 287.464155
        N = 100000:
                     Avg.: 497.733154
                Std. dev.: 288.208068
        N = 1000000:
                     Avg.: 497.298157
                Std. dev.: 287.621034
------------------------------------------------------------------------
If the distribution of rand is uniform in the interval [0, r-1], then
the theoretical values are:
        avg = (r-1)/2
    std_dev = sqrt((r^2-1)/12)

This results in:
r = 10:
         Avg.: 4.5
    Std. dev.: 2.872

r = 100:
         Avg.: 49.5
    Std. dev.: 28.87

r = 100:
         Avg.: 499.5
    Std. dev.: 288.7

stdlib's rand() is famous for actually not being very random.
--------------------------------------------------------------------- */

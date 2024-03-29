/* ---------------------------------------------------------------------
                              EXERCISE 3.4
------------------------------------------------------------------------
Do Exercise 3.2 for r = 2, 4, and 16.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  for (int r = 2; r <= 16; r *= 2) {
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
r = 2:
        N = 1000:
                     Avg.: 0.507997
                Std. dev.: 0.499936
        N = 10000:
                     Avg.: 0.491872
                Std. dev.: 0.499934
        N = 100000:
                     Avg.: 0.501373
                Std. dev.: 0.499998
        N = 1000000:
                     Avg.: 0.502754
                Std. dev.: 0.499992
r = 4:
        N = 1000:
                     Avg.: 1.477001
                Std. dev.: 1.126702
        N = 10000:
                     Avg.: 1.514664
                Std. dev.: 1.113097
        N = 100000:
                     Avg.: 1.501555
                Std. dev.: 1.119003
        N = 1000000:
                     Avg.: 1.499208
                Std. dev.: 1.120852
r = 8:
        N = 1000:
                     Avg.: 3.597004
                Std. dev.: 2.299241
        N = 10000:
                     Avg.: 3.491988
                Std. dev.: 2.291108
        N = 100000:
                     Avg.: 3.499931
                Std. dev.: 2.285418
        N = 1000000:
                     Avg.: 3.495273
                Std. dev.: 2.290547
r = 16:
        N = 1000:
                     Avg.: 7.548999
                Std. dev.: 4.636114
        N = 10000:
                     Avg.: 7.479397
                Std. dev.: 4.629451
        N = 100000:
                     Avg.: 7.526628
                Std. dev.: 4.599140
        N = 1000000:
                     Avg.: 7.478677
                Std. dev.: 4.627225
------------------------------------------------------------------------
If the distribution of rand is uniform in the interval [0, r-1], then
the theoretical values are:
        avg = (r-1)/2
    std_dev = sqrt((r^2-1)/12)

This results in:
r = 2:
         Avg.: 0.5
    Std. dev.: 0.5

r = 4:
         Avg.: 1.5
    Std. dev.: 1.118

r = 8:
         Avg.: 3.5
    Std. dev.: 2.291

r = 16:
         Avg.: 7.5
    Std. dev.: 4.610
--------------------------------------------------------------------- */

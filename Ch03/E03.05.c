/* ---------------------------------------------------------------------
                              EXERCISE 3.5
------------------------------------------------------------------------
Implement the necessary functions to allow Program 3.2 to be used for
random bits (numbers that can take only the values 0 or 1).
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  for (int r = 2; r < 3; r++) {
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
                     Avg.: 0.497997
                Std. dev.: 0.499996
        N = 10000:
                     Avg.: 0.494371
                Std. dev.: 0.499968
        N = 100000:
                     Avg.: 0.501323
                Std. dev.: 0.499998
        N = 1000000:
                     Avg.: 0.503007
                Std. dev.: 0.499991
------------------------------------------------------------------------
If the distribution of rand is uniform in the interval [0, r-1], then
the theoretical values are:
        avg = (r-1)/2
    std_dev = sqrt((r^2-1)/12)

This results in:
r = 2:
         Avg.: 0.5
    Std. dev.: 0.5
--------------------------------------------------------------------- */

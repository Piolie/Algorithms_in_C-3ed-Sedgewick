/* ---------------------------------------------------------------------
                              EXERCISE 2.7
------------------------------------------------------------------------
For what values of N is 2*N*H_N - N < N lg N + 10N?
--------------------------------------------------------------------- */

#include <limits.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  unsigned long long n;
  double HN, f, g;
  const double log2 = log(2);
  const double gamma = 0.57721;
  for (n = 1; n < ULLONG_MAX; n++) {
    HN = log(n) / log2 + gamma + 1 / (12 * n);
    f = 2 * n * HN - n;
    g = n * log(n) / log2 + 10 * n;
    if (f < g)
      printf("In range: %llu\n", n);
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
In range: 1
In range: 2
    .
    .
    .
In range: 920
--------------------------------------------------------------------- */

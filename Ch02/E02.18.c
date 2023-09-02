/* ---------------------------------------------------------------------
                             EXERCISE 2.18
------------------------------------------------------------------------
Give the smallest values of N for which floor[H_N] = i for 1 <= i <= 10.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>

/* We're not using H_N from exercise 2.12 because that is the
implementation for an approximation that performs poorly for small n */
double H_N(unsigned int n) {
  double sum = 0;
  for (; n > 0; sum += 1.0 / n, n--)
    ;
  return sum;
}

int main(void) {
  unsigned int N = 1, i;
  for (i = 1; i < 11; i++) {
    for (; (unsigned int)floor(H_N(N)) != i; N++)
      ;
    printf("i = %-2u -> N = %d\n", i, N);
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
i = 1  -> N = 1
i = 2  -> N = 4
i = 3  -> N = 11
i = 4  -> N = 31
i = 5  -> N = 83
i = 6  -> N = 227
i = 7  -> N = 616
i = 8  -> N = 1674
i = 9  -> N = 4550
i = 10 -> N = 12367
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 5.38
------------------------------------------------------------------------
What is the largest N for which F_N can be represented as a 64-bit
integer?
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Is it a 64-bit signed or unsigned integer? Let's do both!
--------------------------------------------------------------------- */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t fib_less_than(uint64_t max) {
  if (max == 0)
    return 0;
  uint64_t N;
  uint64_t x2 = 0;
  uint64_t x1 = 1;
  uint64_t xN = 0;
  for (N = 2;; N++) {
    if (x1 > (max - x2))
      return N - 1;
    xN = x1 + x2;
    x2 = x1;
    x1 = xN;
  }
}
int main(void) {
  printf("INT64_WIDTH = %zu\n", sizeof(int64_t) * CHAR_BIT);
  printf("INT64_MAX = %lld\n", INT64_MAX);

  printf("UINT64_WIDTH = %zu\n", sizeof(uint64_t) * CHAR_BIT);
  printf("UINT64_MAX = %llu\n", UINT64_MAX);

  printf("F_N <= INT64_MAX for all N <= %llu\n", fib_less_than(INT64_MAX));
  printf("F_N <= UINT64_MAX for all N <= %llu\n", fib_less_than(UINT64_MAX));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.38.exe
INT64_WIDTH = 64
INT64_MAX = 9223372036854775807
UINT64_WIDTH = 64
UINT64_MAX = 18446744073709551615
F_N <= INT64_MAX for all N <= 92
F_N <= UINT64_MAX for all N <= 93
--------------------------------------------------------------------- */

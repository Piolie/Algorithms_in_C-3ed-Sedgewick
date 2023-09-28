/* ---------------------------------------------------------------------
                              EXERCISE 5.4
------------------------------------------------------------------------
Find the value of N < 10^6 for which Program 5.2 makes the maximum
number of recursive calls.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This program counts the number of times puzzle() is called. I guess the
number of "recursive calls" is one less than this.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int depth;

int puzzle(unsigned int N) {
  depth++;
  if (N == 1)
    return 1;
  if (N % 2 == 0)
    return puzzle(N / 2);
  else
    return puzzle(3 * N + 1);
}

int main(void) {
  int max_depth = 0;
  int N = 0;
  for (int i = 1; i < 1000000; i++) {
    depth = 0;
    puzzle(i);
    if (depth > max_depth) {
      max_depth = depth;
      N = i;
    }
  }
  printf("max_depth = %d for N = %d", max_depth, N);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.04.exe
max_depth = 525 for N = 837799
--------------------------------------------------------------------- */

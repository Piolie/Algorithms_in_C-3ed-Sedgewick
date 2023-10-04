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

#include <stdio.h>
#include <stdlib.h>

static int calls;

#define MAXN 1000000

int puzzle(unsigned int N) {
  calls++;
  if (N == 1)
    return 1;
  if (N % 2 == 0)
    return puzzle(N / 2);
  else
    return puzzle(3 * N + 1);
}

int main(void) {
  int max_calls = 0;
  int N = 0;
  for (int i = 1; i < MAXN; i++) {
    calls = 0;
    puzzle(i);
    if (calls > max_calls) {
      max_calls = calls;
      N = i;
    }
  }
  printf("max_calls = %d for N = %d", max_calls, N);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.04.exe
max_calls = 525 for N = 837799
--------------------------------------------------------------------- */

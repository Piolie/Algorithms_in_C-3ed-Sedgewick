/* ---------------------------------------------------------------------
                             EXERCISE 3.12
------------------------------------------------------------------------
Modify our implementation of the sieve of Eratosthenes (Program 3.5) to
use an array of (i) chars; and (ii) bits. Determine the effects of these
changes on the amount of space and time used by the program.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Since the array only stores 0 or 1, chars are more than enough. In my
system sizeof(int) == 4, while sizeof(char) == 1 (this one is set by the
C standard). This means that the size needed for the array is reduced
by a factor of 4 if using chars instead of ints.
--------------------------------------------------------------------- */

#include <stdio.h>

#define N 10000
int main(void) {
  int i, j;
  char a[N];
  for (i = 2; i < N; i++)
    a[i] = 1;
  for (i = 2; i < N; i++)
    if (a[i])
      for (j = i; i * j < N; j++)
        a[i * j] = 0;
  for (i = 2; i < N; i++)
    if (a[i])
      printf("%4d ", i);
  printf("\n");
}

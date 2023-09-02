/* ---------------------------------------------------------------------
                             EXERCISE 3.15
------------------------------------------------------------------------
Empirically determine the effect of removing the test if (a[i]) that
guards the inner loop of Program 3.5, for N = 10^3, 10^4, 10^5 and 10^6.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The problem doesn't tell where to look for the effects.
Printing to the console is very slow, compared to the rest of
operations. If there is a difference in performance by removing the
if guard it's difficult to notice. I've modified the program a little
further, so that it only prints the last prime and still couldn't see
anything different. Increasing N to 10^8 makes the speed difference
really noticeable.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define N 100000000
int main(void) {
  unsigned long i, j;
  int *a = malloc(N * sizeof(*a));
  for (i = 2; i < N; i++)
    a[i] = 1;
  for (i = 2; i < N; i++)
    if (a[i])
      for (j = i; i * j < N; j++)
        a[i * j] = 0;
  for (i = 2; i < N; i++)
    if (a[i])
      j = i;
  printf("Last prime = %lu\n", j);
}

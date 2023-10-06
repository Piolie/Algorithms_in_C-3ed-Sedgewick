/* ---------------------------------------------------------------------
                             EXERCISE 5.54
------------------------------------------------------------------------
Use dynamic programming to solve Exercise 5.4. Keep track of the total
number of function calls that you save.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This is called the [Collatz
sequence](https://en.wikipedia.org/wiki/Collatz_conjecture) and, as far
as we are concerned, it always returns 1. So we could simply return that
number, but it would feel like cheating.

We can then modify the puzzle function to return the length of the
sequence, and apply memoization to that.

We have to add an extra guard to the function, because not every
recursive call uses an argument smaller than the one given and so we
have to avoid accessing our array out of bounds.

Also, we cannot do
  return known[N] = puzzle()
inside the function, for the same reasons. One solution to apply
memoization to the inside-bounds elements is to do it inside the loop
that calls the function to find the maximum.

I have not kept track of the total number of function calls saved.

Adapted from an answer to [Longest collatz sequence using dynamic
programming](https://codereview.stackexchange.com/questions/63550/).
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

static int *known;

int collatz(unsigned int N) {
  if (N < MAXN && known[N] != -1)
    return known[N];

  if (N % 2 == 0)
    return 1 + collatz(N / 2);
  else
    return 1 + collatz(3 * N + 1);
}

int main(void) {
  known = malloc(MAXN * sizeof *known);
  known[1] = 1;
  for (int i = 2; i < MAXN; i++)
    known[i] = -1;

  int max_calls = 0;
  int N = 0;
  int c = 0;
  for (int i = 1; i < MAXN; i++) {
    c = known[i] = collatz(i);
    if (c > max_calls) {
      max_calls = c;
      N = i;
    }
  }

  printf("max_calls = %d for N = %d", max_calls, N);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.54.exe
max_calls = 525 for N = 837799
--------------------------------------------------------------------- */

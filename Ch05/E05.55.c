/* ---------------------------------------------------------------------
                             EXERCISE 5.55
------------------------------------------------------------------------
Write a program that uses top-down dynamic programming to compute the
binomial coefficient (N, k), based on the recursive rule
  (N, k) = (N - 1, k) + (N - 1, k - 1)
with (N, 0) = (N, N) = 1.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Since the coefficients present a symmetry, we could use that fact to
halve the array size.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int binomial(int N, int k, int MAXN, int knownB[MAXN + 1][MAXN + 1]) {
  if (knownB[N][k] != -1)
    return knownB[N][k];
  if ((k == 0) || (N == k))
    return (knownB[N][k] = 1);

  return (knownB[N][k] = binomial(N - 1, k, MAXN, knownB) +
                         binomial(N - 1, k - 1, MAXN, knownB));
}

int main(int argc, char *argv[]) {
  (void)argc;
  int MAXN = atoi(argv[1]);
  int(*knownB)[MAXN + 1] = malloc(sizeof(int[MAXN + 1][MAXN + 1]));
  for (int N = 0; N <= MAXN; N++)
    for (int k = 0; k <= MAXN; k++)
      knownB[N][k] = -1;

  for (int N = 0; N <= MAXN; N++) {
    printf("%*s", 2 * (MAXN - N), "");
    for (int k = 0; k <= N; k++) {
      printf("%4d", binomial(N, k, MAXN, knownB));
    }
    printf("\n");
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.55.exe 10
                       1
                     1   1
                   1   2   1
                 1   3   3   1
               1   4   6   4   1
             1   5  10  10   5   1
           1   6  15  20  15   6   1
         1   7  21  35  35  21   7   1
       1   8  28  56  70  56  28   8   1
     1   9  36  84 126 126  84  36   9   1
   1  10  45 120 210 252 210 120  45  10   1
--------------------------------------------------------------------- */

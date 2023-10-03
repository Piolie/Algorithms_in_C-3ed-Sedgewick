/* ---------------------------------------------------------------------
                             EXERCISE 5.41
------------------------------------------------------------------------
Write a function that uses top-down dynamic programming to solve
Exercise 5.40.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This function needs an array of double the size of the one in E05.40,
and never gets to populate the upper half.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int *knownF;

int P(unsigned int N) {
  if (knownF[N] != -1)
    return knownF[N];
  if (N == 0)
    return 0;
  if (N == 1)
    return 1;

  int f = floor(N / 2.0);
  int c = ceil(N / 2.0);
  int Pf = P(f);
  int Pc = P(c);
  return (knownF[N] = f + Pf + Pc);
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  knownF = malloc((N + 1) * sizeof *knownF);
  for (int i = 0; i < N + 1; i++)
    knownF[i] = -1;

  printf("P_%d = %d\n", N, P(N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.41.exe 20
P_20 = 60

./E05.41.exe 99
P_99 = 411

./E05.41.exe 1001
P_1001 = 5939
--------------------------------------------------------------------- */

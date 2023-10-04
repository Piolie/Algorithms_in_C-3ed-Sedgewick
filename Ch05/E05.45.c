/* ---------------------------------------------------------------------
                             EXERCISE 5.45
------------------------------------------------------------------------
Write a function that uses top-down dynamic programming to solve
Exercise 5.44.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

static float *knownC;

float C(unsigned int N) {
  if (knownC[N] != -1)
    return knownC[N];
  if (N == 0)
    return (knownC[N] = 0);

  float sum = 0;
  for (unsigned int k = 1; k <= N; k++)
    sum += C(k - 1) + C(N - k);
  return (knownC[N] = N + sum / N);
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  knownC = malloc((N + 1) * sizeof *knownC);
  for (int i = 0; i < N + 1; i++)
    knownC[i] = -1;
  printf("C_%d = %f\n", N, C(N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.45.exe 20
C_20 = 91.105064

./E05.45.exe 99
C_99 = 738.475403

./E05.45.exe 1001
C_1001 = 11999.892578
--------------------------------------------------------------------- */

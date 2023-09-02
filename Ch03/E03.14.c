/* ---------------------------------------------------------------------
                             EXERCISE 3.14
------------------------------------------------------------------------
Use the sieve of Eratosthenes to draw a plot of N versus the number of
primes less than N for N between 1 and 1000.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int sieve_e(unsigned int N) {
  unsigned long long i, j;
  int count = 0;
  char *a = malloc(N * sizeof(*a));
  for (i = 2; i < N; i++)
    a[i] = 1;
  for (i = 2; i < N; i++)
    if (a[i])
      for (j = i; i * j < N; j++)
        a[i * j] = 0;
  for (i = 2; i < N; i++)
    if (a[i])
      count++;
  free(a);
  return count;
}

int main(void) {
  for (unsigned int N = 0; N <= 1000; N++) {
    printf("%4d ", N);
    for (int i = 0; i < sieve_e(N); i += 10)
      printf("*");
    printf("\n");
  }
}

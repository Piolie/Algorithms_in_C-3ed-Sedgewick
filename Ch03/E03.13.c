/* ---------------------------------------------------------------------
                             EXERCISE 3.13
------------------------------------------------------------------------
Use the sieve of Eratosthenes to determine the number of primes less
than N, for N 10^3, 1^04, 10^5, and 10^6.
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
  for (unsigned int N = 10; N <= 1000000000; N *= 10)
    printf("Number of primes less than %d = %d\n", N, sieve_e(N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Number of primes less than 10 = 4
Number of primes less than 100 = 25
Number of primes less than 1000 = 168
Number of primes less than 10000 = 1229
Number of primes less than 100000 = 9592
Number of primes less than 1000000 = 78498
Number of primes less than 10000000 = 664579
Number of primes less than 100000000 = 5761455
Number of primes less than 1000000000 = 50847534

This took about 1 GB of RAM on my system.
------------------------------------------------------------------------
The results can be checked at:
  https://en.wikipedia.org/wiki/Prime-counting_function
--------------------------------------------------------------------- */

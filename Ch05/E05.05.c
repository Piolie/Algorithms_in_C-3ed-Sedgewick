/* ---------------------------------------------------------------------
                              EXERCISE 5.5
------------------------------------------------------------------------
Provide a nonrecursive implementation of Euclid's algorithm.
--------------------------------------------------------------------- */
/* ---------------------------------------------------------------------
Adapted from the
[Wikipedia](https://en.wikipedia.org/wiki/Euclidean_algorithm#Implementations)
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int gcd_rec(int m, int n) {
  if (n == 0)
    return m;
  return gcd_rec(n, m % n);
}

int gcd_iter(int m, int n) {
  int t;
  while (n) {
    t = n;
    n = m % n;
    m = t;
  }
  return m;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int M = atoi(argv[1]);
  int N = atoi(argv[2]);
  printf("gcd_rec(%d, %d) = %d\n", M, N, gcd_rec(M, N));
  printf("gcd_iter(%d, %d) = %d\n", M, N, gcd_iter(M, N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.05.exe 1071 462
gcd_rec(1071, 462) = 21
gcd_iter(1071, 462) = 21
--------------------------------------------------------------------- */

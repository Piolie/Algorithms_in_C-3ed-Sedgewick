/* ---------------------------------------------------------------------
                              EXERCISE 5.6
------------------------------------------------------------------------
Give the figure corresponding to Figure 5.2 for the result of running
Euclid's algorithm for the inputs 89 and 55.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

static int depth = 0;

int gcd(int m, int n) {
  printf("%*sgcd(%d, %d)\n", depth, "", m, n);
  depth++;
  if (n == 0)
    return m;
  return gcd(n, m % n);
}

int main(int argc, char *argv[]) {
  (void)argc;
  int M = atoi(argv[1]);
  int N = atoi(argv[2]);
  gcd(M, N);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.06.exe 89 55
gcd(89, 55)
 gcd(55, 34)
  gcd(34, 21)
   gcd(21, 13)
    gcd(13, 8)
     gcd(8, 5)
      gcd(5, 3)
       gcd(3, 2)
        gcd(2, 1)
         gcd(1, 0)
--------------------------------------------------------------------- */

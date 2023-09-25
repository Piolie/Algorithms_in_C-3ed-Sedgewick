/* ---------------------------------------------------------------------
                              EXERCISE 5.2
------------------------------------------------------------------------
Modify Program 5.1 to compute N! mod M, such that overflow is no longer
an issue. Try running your program for M = 997 and N = 10^3, 10^4, 10^5,
and 10^6, to get an indication of how your programming system handles
deeply nested recursive calls.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
N! mod M =?  (N        * (N - 1)!) mod M; or
         =?  (N mod M) * ((N - 1)  mod M)!; or
         =? ((N mod M) * ((N - 1)  mod M)!) mod M?
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fact_mod(int N, int M) {
  if (N == 0)
    return 1;
  return (N * fact_mod((N - 1), M)) % M;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);
  printf("%d! mod %d = %d\n", N, M, fact_mod(N, M));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.02.exe 100 997
1000! mod 997 = 172

./E05.02.exe 1000 997
10000! mod 997 = 0

./E05.02.exe 10000 997
100000! mod 997 = 0

./E05.02.exe 100000 997
STACK OVERFLOW!

 ./E05.02.exe 43325 997
43325! mod 997 = 0
--------------------------------------------------------------------- */

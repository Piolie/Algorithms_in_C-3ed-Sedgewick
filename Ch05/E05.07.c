/* ---------------------------------------------------------------------
                              EXERCISE 5.7
------------------------------------------------------------------------
Give the recursive depth of Euclid's algorithm when the input values
are two consecutive Fibonacci numbers (F_N and F_(N+1)).
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
  if (n == 0)
    return 0;

  int a = 0;
  int b = 1;
  int c;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

static int depth;

int gcd(int m, int n) {
  depth++;
  if (n == 0)
    return m;
  return gcd(n, m % n);
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  for (int i = 0; i < N; i++) {
    depth = 0;
    gcd(fib(i), fib(i + 1));
    printf("Recursion depth for gcd(F_%d, F_%d) is %d\n", i, i + 1, depth);
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.07.exe 10
Recursion depth for gcd(F_0, F_1) is 2
Recursion depth for gcd(F_1, F_2) is 2
Recursion depth for gcd(F_2, F_3) is 3
Recursion depth for gcd(F_3, F_4) is 4
Recursion depth for gcd(F_4, F_5) is 5
Recursion depth for gcd(F_5, F_6) is 6
Recursion depth for gcd(F_6, F_7) is 7
Recursion depth for gcd(F_7, F_8) is 8
Recursion depth for gcd(F_8, F_9) is 9
Recursion depth for gcd(F_9, F_10) is 10
--------------------------------------------------------------------- */

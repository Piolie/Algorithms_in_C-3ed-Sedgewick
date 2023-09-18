/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.13
                Complex numbers driver (roots of unity)
------------------------------------------------------------------------
This client program performs a computation on complex numbers using an
ADT that allows it to compute directly with the abstraction of interest
by declaring variables of type Complex and using them as arguments and
return values of functions. This program checks the ADT implementation
by computing the powers of the roots of unity. It prints the table shown
in Figure 4.12.
--------------------------------------------------------------------- */

#include "COMPLEX.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592625

int main(int argc, char *argv[]) {
  (void)argc;
  int i, j, N = atoi(argv[1]);
  Complex t, x;
  printf("%dth complex roots of unity\n", N);
  for (i = 0; i < N; i++) {
    float r = 2.0 * PI * i / N;
    t = COMPLEXinit(cos(r), sin(r));
    printf("%2d %6.3f %6.3f ", i, Re(t), Im(t));
    for (x = t, j = 0; j < N - 1; j++)
      x = COMPLEXmult(t, x);
    printf("%6.3f %6.3f\n", Re(x), Im(x));
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
 ./P04.13.exe 8
8th complex roots of unity
 0  1.000  0.000  1.000  0.000
 1  0.707  0.707  1.000  0.000
 2 -0.000  1.000  1.000  0.000
 3 -0.707  0.707  1.000  0.000
 4 -1.000 -0.000  1.000  0.000
 5 -0.707 -0.707  1.000 -0.000
 6  0.000 -1.000  1.000  0.000
 7  0.707 -0.707  1.000 -0.000
--------------------------------------------------------------------- */

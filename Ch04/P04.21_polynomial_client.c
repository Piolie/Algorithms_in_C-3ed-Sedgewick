/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.21
               Polynomial client (binomial coefficients)
------------------------------------------------------------------------
This client program uses the polynomial ADT that is defined in the
interface Program 4.22 to perform algebraic manipulations with
polynomials. It takes an integer N and a floating-point number p from
the command line, computes (x + 1)^N, and checks the result by
evaluating the resulting polynomial at x = p.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The author forgot to include an implementation of showPOLY. There was
also an unused int j variable, which I removed.
--------------------------------------------------------------------- */

#include "POLY.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  float p = atof(argv[2]);
  Poly t, x;
  int i;
  printf("Binomial coefficients:\n");
  t = POLYadd(POLYterm(1, 1), POLYterm(1, 0));
  for (i = 0, x = t; i < N; i++) {
    x = POLYmult(t, x);
    showPOLY(x);
  }
  printf("%f\n", POLYeval(x, p));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./P04.21.exe 10 0.5
Binomial coefficients:
   1   2   1
   1   3   3   1
   1   4   6   4   1
   1   5  10  10   5   1
   1   6  15  20  15   6   1
   1   7  21  35  35  21   7   1
   1   8  28  56  70  56  28   8   1
   1   9  36  84 126 126  84  36   9   1
   1  10  45 120 210 252 210 120  45  10   1
   1  11  55 165 330 462 462 330 165  55  11   1
86.497559
--------------------------------------------------------------------- */

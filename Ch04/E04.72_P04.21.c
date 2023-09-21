/* ---------------------------------------------------------------------
                             EXERCISE 4.72
------------------------------------------------------------------------
Modify the polynomial ADT interface, implementation, and client in the
text (Programs 4.21 through 4.23) such that there are no memory leaks.
To do so, define new operations POLYdestroy and POLYcopy, which should
free the memory for an object and copy one object's values to another,
respectively; and modify POLYadd and POLYmult to destroy their arguments
and return a newly created object, by convention.
--------------------------------------------------------------------- */

#include "POLY.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  float p = atof(argv[2]);
  printf("Binomial coefficients:\n");
  Poly t1 = POLYadd(POLYterm(1, 1), POLYterm(1, 0));
  Poly x = POLYcopy(t1);
  for (int i = 0; i < N; i++) {
    Poly t2 = POLYcopy(t1);
    x = POLYmult(t2, x);
    showPOLY(x);
  }
  printf("%f\n", POLYeval(x, p));
  POLYdestroy(t1);
  POLYdestroy(x);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.72.exe 10 0.5
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

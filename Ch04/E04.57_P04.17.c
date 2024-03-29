/* ---------------------------------------------------------------------
                             EXERCISE 4.57
------------------------------------------------------------------------
Add a function CDMPLEXadd to the ADT for complex numbers in the
text (Programs 4.16 and 4.17).
--------------------------------------------------------------------- */

#include "COMPLEX.h"
#include <stdlib.h>

struct complex {
  float Re;
  float Im;
};

Complex COMPLEXinit(float Re, float Im) {
  Complex t = malloc(sizeof *t);
  t->Re = Re;
  t->Im = Im;
  return t;
}

float Re(Complex z) { return z->Re; }

float Im(Complex z) { return z->Im; }

Complex COMPLEXadd(Complex a, Complex b) {
  return COMPLEXinit(Re(a) + Re(b), Im(a) + Im(b));
}

Complex COMPLEXmult(Complex a, Complex b) {
  return COMPLEXinit(Re(a) * Re(b) - Im(a) * Im(b),
                     Re(a) * Im(b) + Im(a) * Re(b));
}

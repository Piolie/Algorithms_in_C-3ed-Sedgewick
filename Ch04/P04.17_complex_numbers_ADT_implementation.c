/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.17
                   Complex-numbers ADT implementation
------------------------------------------------------------------------
By contrast with Program 4.15, this implementation of the
complex­numbers ADT includes the structure definition (which is hidden
from the client), as well as the function implementations. Objects are
pointers to structures, so we dereference the pointer to refer to the
fields.
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

Complex COMPLEXmult(Complex a, Complex b) {
  return COMPLEXinit(Re(a) * Re(b) - Im(a) * Im(b),
                     Re(a) * Im(b) + Im(a) * Re(b));
}

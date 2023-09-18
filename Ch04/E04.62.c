/* ---------------------------------------------------------------------
                             EXERCISE 4.62
------------------------------------------------------------------------
Develop an implementation for the complex-number ADT that is based
on representing complex numbers in polar coordinates (that is, in the
form re^(iθ)).
--------------------------------------------------------------------- */

#include "COMPLEX.h"
#include <math.h>
#include <stdlib.h>

struct complex {
  float r;
  float theta;
};

Complex COMPLEXinit(float re, float im) {
  Complex t = malloc(sizeof *t);
  t->r = sqrt(re * re + im * im);
  t->theta = atan2(im, re);
  return t;
}

float Re(Complex z) { return z->r * cos(z->theta); }

float Im(Complex z) { return z->r * sin(z->theta); }

Complex CDMPLEXadd(Complex a, Complex b) {
  return COMPLEXinit(Re(a) + Re(b), Im(a) + Im(b));
}

Complex COMPLEXmult(Complex a, Complex b) {
  return COMPLEXinit(a->r * b->r, a->theta + b->theta);
}

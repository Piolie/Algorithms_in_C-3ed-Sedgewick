/* ---------------------------------------------------------------------
                             EXERCISE 6.50
------------------------------------------------------------------------
Write an interface and implementation for the generic item data type to
support having the sorting methods sort complex numbers x + iy using the
magnitude sqrt(x^2 + y^2) for the key. Note: Ignoring the square root is
likely to improve efficiency.
--------------------------------------------------------------------- */

#include "Item.h" // #include "E06.50.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

double complex ITEMrand(void) {
  return 2.0 * (rand() - RAND_MAX / 2) / RAND_MAX * DBL_MAX;
}

int ITEMscan(double complex *x) {
  double re, im;
  int res = scanf("%lf %lf", &re, &im);
  *x = re + I * im;
  return res;
}

void ITEMshow(double complex x) {
  printf("%7.5f + i%7.5f ", creal(x), cimag(x));
}

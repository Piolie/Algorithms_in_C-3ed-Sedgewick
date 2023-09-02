/* ---------------------------------------------------------------------
                             EXERCISE 3.10
------------------------------------------------------------------------
Define a data type for triangles in the unit square, including a
function that computes the area of a triangle. Then write a client
program that generates random triples of pairs of floats between 0 and 1
and computes empirically the average area of the triangles generated.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The first step is to calculate the length of each side. For that we use
the distance function provided in Program 3.4. With those values, the
area calculation is done with Heron's formula:
    https://en.wikipedia.org/wiki/Heron's_formula

Notice that the form of the formula used is not numerically stable for
triangles with a very small angle when using floating-point arithmetic.
(See the Numerical stability section in the Wikipedia article.)
--------------------------------------------------------------------- */

#include <math.h>
#include "Point.h"
#include "E03.10_triangle.h"

float area(triangle T) {
  float a = distance(T.A, T.B);
  float b = distance(T.B, T.C);
  float c = distance(T.C, T.A);

  return sqrt(4 * pow(a, 2) * pow(b, 2) -
              pow((pow(a, 2) + pow(b, 2) - pow(c, 2)), 2)) /
         4;
}

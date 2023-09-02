/* ---------------------------------------------------------------------
                             EXERCISE 3.10
------------------------------------------------------------------------
Define a data type for triangles in the unit square, including a
function that computes the area of a triangle. Then write a client
program that generates random triples of pairs of floats between 0 and 1
and computes empirically the average area of the triangles generated.
--------------------------------------------------------------------- */

#include "E03.10_triangle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// from E03.03
float randfrom(float min, float max) {
  float range = (max - min);
  float div = RAND_MAX / range;
  return min + (rand() / div);
}

int main(void) {
  point A = {.x = randfrom(0, 1), .y = randfrom(0, 1)};
  point B = {.x = randfrom(0, 1), .y = randfrom(0, 1)};
  point C = {.x = randfrom(0, 1), .y = randfrom(0, 1)};
  printf("A = (%f, %f); B = (%f, %f); C = (%f, %f)\n", A.x, A.y, B.x, B.y, C.x,
         C.y);
  triangle t = {.A = A, .B = B, .C = C};
  printf("area = %f\n", area(t));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
A = (0.001251, 0.563585); B = (0.193304, 0.808740); C = (0.585009, 0.479873)
area = 0.079594
--------------------------------------------------------------------- */

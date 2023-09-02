/* ---------------------------------------------------------------------
                             EXERCISE 3.10
------------------------------------------------------------------------
Define a data type for triangles in the unit square, including a
function that computes the area of a triangle. Then write a client
program that generates random triples of pairs of floats between 0 and 1
and computes empirically the average area of the triangles generated.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The data type is just a struct containing three points corresponding to
the three vertices of the triangle.
--------------------------------------------------------------------- */

typedef struct {
  point A;
  point B;
  point C;
} triangle;

float area(triangle T);

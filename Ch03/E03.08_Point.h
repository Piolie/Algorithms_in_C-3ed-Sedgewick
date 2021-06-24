/* ---------------------------------------------------------------------
                              EXERCISE 3.8
------------------------------------------------------------------------
Add a function to the point data type (Programs 3.3 and 3.4) that
determines whether or not three points are collinear, to within a
numerical tolerance of 10^-4. Assume that the points are all in the unit
square.
--------------------------------------------------------------------- */

typedef struct {
    float x;
    float y;
} point;

float distance(point A, point B);
int collinear(point A, point B, point C);

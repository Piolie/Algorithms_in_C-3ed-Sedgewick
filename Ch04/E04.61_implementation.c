/* ---------------------------------------------------------------------
                             EXERCISE 4.61
------------------------------------------------------------------------
Create an ADT for points in the plane, and change the closest-point
program in Chapter 3 Program 3.16 to a client program that uses your
ADT.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------

--------------------------------------------------------------------- */

#include "Point.h" // E04.61_interface.h
#include <stdlib.h>
#include <math.h>

struct point {
  float x;
  float y;
};

Point POINTinit(float x, float y) {
  Point p = malloc(sizeof(*p));
  p->x = x;
  p->y = y;
  return p;
}

float POINTdistance(Point a, Point b) {
  float dx = a->x - b->x;
  float dy = a->y - b->y;
  return sqrt(dx * dx + dy * dy);
}

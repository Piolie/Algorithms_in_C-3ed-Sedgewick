/* ---------------------------------------------------------------------
                             EXERCISE 4.61
------------------------------------------------------------------------
Create an ADT for points in the plane, and change the closest-point
program in Chapter 3 Program 3.16 to a client program that uses your
ADT.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
In the current edition, P03.16 is Two-dimensional array allocation. The
exercise probably refers to P03.08: Closest-point computation.
--------------------------------------------------------------------- */

typedef struct point *Point;
Point POINTinit(float, float);
float POINTdistance(Point, Point);

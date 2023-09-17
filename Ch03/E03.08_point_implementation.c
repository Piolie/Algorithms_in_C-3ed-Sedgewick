/* ---------------------------------------------------------------------
                              EXERCISE 3.8
------------------------------------------------------------------------
Add a function to the point data type (Programs 3.3 and 3.4) that
determines whether or not three points are collinear, to within a
numerical tolerance of 10^-4. Assume that the points are all in the unit
square.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
First of all, I think the tolerance in the statement is not well
defined. How should we measure the deviation from collinearity?

I've chosen the difference in the slopes compared to the greatest one,
but this approach fails if the slopes are very large (see last output),
because minimal differences in collinearity yield enormous differences
in the slopes.

Another way I can think of is finding the least-squares linear
approximation of the three points and comparing the sum of squared
residuals against the given tolerance. There might also be other
reasonable approaches.

This solution is based on comparing the slope of lines AB and AC. If
slope(a, b) is the same as slope(a, c) then A, B and C are collinear.
Easy, right? Well, not so much. It turns out that floating-point math is
exceptionally hard. See the following article from _Random ASCII – tech
blog of Bruce Dawson_ for an in-depth analysis of the issue:
https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
(The whole series is worth a read.)

I'll implement a function similar to his AlmostEqualRelative, but using
the given tolerance of 10^-4. Basically, if the two slopes are s1 and
s2, I'll calculate |s1 - s2| and see if it is within tolerance of
max(|s1|, |s2|).

The slope function returns INFINITY if the two points have the same
x-coordinate. Note that if A and B are the same point, then the slope is
undefined, but our function still returns INFINITY. This makes sense in
this case, because if two points are the same then they are on the same
line and are thus collinear.

I don't know what the assumption that the points are all in the unit
square would be used for.
--------------------------------------------------------------------- */

#include "Point.h" // #include "E03.08_Point.h"
#include <math.h>
#include <stdio.h>

float distance(point a, point b) {
  float dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

float slope(point A, point B) {
  float dx = B.x - A.x;
  if (dx == 0)
    return INFINITY;
  float dy = B.y - A.y;
  return dy / dx;
}

int collinear(point A, point B, point C) {
  float slope_ab = slope(A, B);
  float abs_slope_ab = fabs(slope_ab);
  float slope_ac = slope(A, C);
  float abs_slope_ac = fabs(slope_ac);
  printf("slope_ab = %f\n", slope_ab);
  printf("slope_ac = %f\n", slope_ac);

  if ((slope_ab == INFINITY) && (slope_ab == INFINITY))
    return 1;

  float diff = fabs(slope_ab - slope_ac);
  float max = (abs_slope_ab > abs_slope_ac) ? abs_slope_ab : abs_slope_ac;
  printf("diff = %f; max = %f; diff/max = %f\n", diff, max, diff / max);
  return (diff / max) <= 0.0001;
}

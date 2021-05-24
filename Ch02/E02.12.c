/* ---------------------------------------------------------------------
                              EXERCISE 2.12
------------------------------------------------------------------------
Write a C function that computes H_N, using the log function from
the standard math library.
--------------------------------------------------------------------- */

#include <math.h>

double H_N(unsigned int n)
{
    const double log2 = log(2);
    const double gamma = 0.57721;

    return log(n)/log2 + gamma + 1.0/(12*n);
}

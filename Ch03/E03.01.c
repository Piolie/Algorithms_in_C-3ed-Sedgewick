/* ---------------------------------------------------------------------
                              EXERCISE 3.1
------------------------------------------------------------------------
Find the largest and smallest numbers that you can represent with
types int, long int, short int, float, and double in your programming
environment.
--------------------------------------------------------------------- */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("%d\t<= int\t\t<= %d\n", INT_MIN, INT_MAX);
  printf("%ld\t<= long int\t<= %ld\n", LONG_MIN, LONG_MAX);
  printf("%d\t\t<= short int\t<= %d\n", SHRT_MIN, SHRT_MAX);
  printf("%e\t<= float\t\t<= %e\n", FLT_MIN, FLT_MAX);
  printf("%e\t<= double\t\t<= %e\n", DBL_MIN, DBL_MAX);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
-2147483648    <= int        <= 2147483647
-2147483648    <= long int   <= 2147483647
-32768         <= short int  <= 32767
1.175494e-38   <= float      <= 3.402823e+38
2.225074e-308  <= double     <= 1.797693e+308
--------------------------------------------------------------------- */

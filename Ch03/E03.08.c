/* ---------------------------------------------------------------------
                              EXERCISE 3.8
------------------------------------------------------------------------
Add a function to the point data type (Programs 3.3 and 3.4) that
determines whether or not three points are collinear, to within a
numerical tolerance of 10^-4. Assume that the points are all in the unit
square.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This client program reads a sequence of three points (pairs of
floating-point numbers) from the standard input and finds whether they
are collinear using the added collinear() function.

Some internal information is printed for clarity.
--------------------------------------------------------------------- */

#include "Point.h" // #include "E03.08_Point.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 7)
    return EXIT_FAILURE;

  point A;
  A.x = atof(argv[1]);
  A.y = atof(argv[2]);

  point B;
  B.x = atof(argv[3]);
  B.y = atof(argv[4]);

  point C;
  C.x = atof(argv[5]);
  C.y = atof(argv[6]);

  printf("A = (%f, %f); B = (%f, %f); C = (%f, %f)\n", A.x, A.y, B.x, B.y, C.x,
         C.y);
  printf("Collinear? %s\n", collinear(A, B, C) ? "TRUE" : "FALSE");
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.08.exe 0.1 0.2 0.2 0.4 0.3 0.6
A = (0.100000, 0.200000); B = (0.200000, 0.400000); C = (0.300000, 0.600000)
slope_ab = 2.000000
slope_ac = 2.000000
diff = 0.000000; max = 2.000000; diff/max = 0.000000
Collinear? TRUE

./E03.08.exe 0.09 0.2 0.2 0.41 0.3 0.61
A = (0.090000, 0.200000); B = (0.200000, 0.410000); C = (0.300000, 0.610000)
slope_ab = 1.909091
slope_ac = 1.952381
diff = 0.043290; max = 1.952381; diff/max = 0.022173
Collinear? FALSE

./E03.08.exe 0.099 0.2 0.2 0.401 0.3 0.601
A = (0.099000, 0.200000); B = (0.200000, 0.401000); C = (0.300000, 0.601000)
slope_ab = 1.990099
slope_ac = 1.995025
diff = 0.004926; max = 1.995025; diff/max = 0.002469
Collinear? FALSE

./E03.08.exe 0.0999 0.2 0.2 0.4001 0.3 0.6001
A = (0.099900, 0.200000); B = (0.200000, 0.400100); C = (0.300000, 0.600100)
slope_ab = 1.999001
slope_ac = 1.999500
diff = 0.000499; max = 1.999500; diff/max = 0.000250
Collinear? FALSE

./E03.08.exe 0.09999 0.2 0.2 0.40001 0.3 0.60001
A = (0.099990, 0.200000); B = (0.200000, 0.400010); C = (0.300000, 0.600010)
slope_ab = 1.999900
slope_ac = 1.999950
diff = 0.000050; max = 1.999950; diff/max = 0.000025
Collinear? TRUE

./E03.08.exe 0 1 0 2 0 3
A = (0.000000, 1.000000); B = (0.000000, 2.000000); C = (0.000000, 3.000000)
slope_ab = inf
slope_ac = inf
Collinear? TRUE

./E03.08.exe 0.0000000000000001 1 0 2 0 3
A = (0.000000, 1.000000); B = (0.000000, 2.000000); C = (0.000000, 3.000000)
slope_ab = -10000000272564224.000000
slope_ac = -20000000545128448.000000
diff = 10000000272564224.000000; max = 20000000545128448.000000; diff/max =
0.500000 Collinear? FALSE
--------------------------------------------------------------------- */

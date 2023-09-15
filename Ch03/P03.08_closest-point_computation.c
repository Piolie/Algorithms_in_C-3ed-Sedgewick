/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 3.8
                       Closest-point computation
------------------------------------------------------------------------
This program illustrates the use of an array of structures, and is
representative of the typical situation where we save items in an array
to process them later, during some computation. It counts the number of
pairs of N randomly generated points in the unit square that can be
connected by a straight line of length less than d, using the data type
for points described in Section 3.1. The running time is O(N^2), so this
program cannot be used for huge N. Program 3.20 provides a faster
solution.
--------------------------------------------------------------------- */

#include "Point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float randFloat(void) { return 1.0 * rand() / RAND_MAX; }

int main(int argc, char *argv[]) {
  (void)argc;
  float d = atof(argv[2]);
  int i, j, cnt = 0, N = atoi(argv[1]);
  point *a = malloc(N * (sizeof(*a)));
  for (i = 0; i < N; i++) {
    a[i].x = randFloat();
    a[i].y = randFloat();
  }
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (distance(a[i], a[j]) < d)
        cnt++;
  printf("%d edges shorter than %f\n", cnt, d);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./P03.08_closest-point_computation.exe 1000 1
488477 edges shorter than 1.000000

./P03.08_closest-point_computation.exe 1000 0.1
14293 edges shorter than 0.100000

./P03.08_closest-point_computation.exe 1000 0.01
130 edges shorter than 0.010000

./P03.08_closest-point_computation.exe 1000 0.001
2 edges shorter than 0.001000

./P03.08_closest-point_computation.exe 1000 0.0001
0 edges shorter than 0.000100

./P03.08_closest-point_computation.exe 10000 0.0001
3 edges shorter than 0.000100

./P03.08_closest-point_computation.exe 100000 0.0001
171 edges shorter than 0.000100
--------------------------------------------------------------------- */

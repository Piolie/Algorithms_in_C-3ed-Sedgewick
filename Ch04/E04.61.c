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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float randFloat(void) { return 1.0 * rand() / RAND_MAX; }

int main(int argc, char *argv[]) {
  (void)argc;
  float d = atof(argv[2]);
  int i, j, cnt = 0, N = atoi(argv[1]);
  Point *a = malloc(N * (sizeof(*a)));
  for (i = 0; i < N; i++)
    a[i] = POINTinit(randFloat(), randFloat());
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (POINTdistance(a[i], a[j]) < d)
        cnt++;
  printf("%d edges shorter than %f\n", cnt, d);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.61.exe 1000 1
488477 edges shorter than 1.000000

./E04.61.exe 1000 0.1
14293 edges shorter than 0.100000

./E04.61.exe 1000 0.01
130 edges shorter than 0.010000

./E04.61.exe 1000 0.001
2 edges shorter than 0.001000

./E04.61.exe 1000 0.0001
0 edges shorter than 0.000100

./E04.61.exe 10000 0.0001
3 edges shorter than 0.000100

./E04.61.exe 100000 0.0001
171 edges shorter than 0.000100
--------------------------------------------------------------------- */

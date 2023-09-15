/* ---------------------------------------------------------------------
                              EXERCISE 3.7
------------------------------------------------------------------------
Write a client program that uses the data type in Programs 3.3 and 3.4
for the following task: Read a sequence of points (pairs of
floating-point numbers) from standard input, and find the one that is
closest to the first.
--------------------------------------------------------------------- */

#include "Point.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 5)
    return EXIT_FAILURE;

  point first;
  first.x = atof(argv[1]);
  first.y = atof(argv[2]);

  point closest;
  closest.x = atof(argv[3]);
  closest.y = atof(argv[4]);

  for (int i = 5; i < argc - 1; i += 2) {
    point next;
    next.x = atof(argv[i]);
    next.y = atof(argv[i + 1]);
    if (distance(first, next) < distance(first, closest))
      closest = next;
  }

  printf("The first point is: (%f, %f)\n", first.x, first.y);
  printf("The closest point to the first is: (%f, %f)\n", closest.x, closest.y);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.07.exe 0 0 1 1 0.5 0.5 2 3 5 6 -1 -1 -0.3 0.3 -5 -100
The first point is: (0.000000, 0.000000)
The closest point to the first is: (-0.300000, 0.300000)
--------------------------------------------------------------------- */

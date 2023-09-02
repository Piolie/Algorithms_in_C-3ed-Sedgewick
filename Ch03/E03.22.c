/* ---------------------------------------------------------------------
                             EXERCISE 3.22
------------------------------------------------------------------------
Modify Program 3.8 to print out the coordinates of the closest pair of
points.
--------------------------------------------------------------------- */

#include "Point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float randFloat(void) { return 1.0 * rand() / RAND_MAX; }

int main(int argc, char *argv[]) {
  float d = atof(argv[2]);
  (void)argc;
  int i, j, cnt = 0, N = atoi(argv[1]);
  float current_d, shortest_d = INFINITY;
  int shortest_i, shortest_j;
  point *a = malloc(N * (sizeof(*a)));
  for (i = 0; i < N; i++) {
    a[i].x = randFloat();
    a[i].y = randFloat();
  }
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if ((current_d = distance(a[i], a[j])) < d) {
        if (current_d < shortest_d) {
          shortest_d = current_d;
          shortest_i = i;
          shortest_j = j;
        }
        cnt++;
      }
  printf("%d edges shorter than %f\n", cnt, d);
  printf("The shortest distance is: %f, "
         "from point A = (%f, %f) to point B = (%f, %f)\n",
         shortest_d, a[shortest_i].x, a[shortest_i].y, a[shortest_j].x,
         a[shortest_j].y);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.22.exe 1000 0.5
240981 edges shorter than 0.500000
The shortest distance is: 0.000850, from point A = (0.049440, 0.656056)
to point B = (0.048647, 0.655751)
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 5.36
------------------------------------------------------------------------
Write a recursive divide-and-conquer function to draw an approximation
to a line segment in an integer coordinate space, given the endpoints.
Assume that all coordinates are between 0 and M. Hint: First plot a
point close to the middle.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The program works if x1 < x2 and y1 < y2.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

void draw_line(int x1, int x2, int y1, int y2) {
  int mx = (x1 + x2) / 2;
  int my = (y1 + y2) / 2;
  if ((x1 == mx) && (y1 == my)) {
    printf("(%2d, %2d)\n", mx, my);
  } else {
    draw_line(mx, x2, my, y2);
    draw_line(x1, mx, y1, my);
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  int x1 = atoi(argv[1]);
  int x2 = atoi(argv[2]);
  int y1 = atoi(argv[3]);
  int y2 = atoi(argv[4]);

  printf("Line segment from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
  draw_line(x1, x2, y1, y2);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.36.exe 0 10 0 10
Line segment from (0, 0) to (10, 10)
( 9,  9)
( 8,  8)
( 7,  7)
( 6,  6)
( 5,  5)
( 4,  4)
( 3,  3)
( 2,  2)
( 1,  1)
( 0,  0)

./E05.36.exe 0 5 0 10
Line segment from (0, 0) to (5, 10)
( 4,  9)
( 4,  8)
( 3,  7)
( 2,  6)
( 2,  5)
( 1,  4)
( 1,  3)
( 1,  2)
( 0,  1)
( 0,  0)

./E05.36.exe 0 10 0 5
Line segment from (0, 0) to (10, 5)
( 9,  4)
( 8,  4)
( 7,  3)
( 6,  2)
( 5,  2)
( 4,  1)
( 3,  1)
( 2,  1)
( 1,  0)
( 0,  0)
--------------------------------------------------------------------- */

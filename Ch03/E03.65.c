/* ---------------------------------------------------------------------
                             EXERCISE 3.65
------------------------------------------------------------------------
Write a program to fill in a two-dimensional array of 0-1 values by
setting a[i][j] to 1 if the greatest common divisor of i and j is 1, and
to 0 otherwise.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Since the two-dimensional array will be symmetrical, we don't have to
iterate from 0 to COLUMNS, it's enough to do it from the current column
number and set the two symmetrical values at the same time.

I've adapted the euclidean algorithm pseudocode implementation from
Wikipedia: https://en.wikipedia.org/wiki/Euclidean_algorithm
--------------------------------------------------------------------- */

#include <stdio.h>
#define ROWS 10
#define COLUMNS 10

void print_array(char a[][COLUMNS], int rows, int columns) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++)
      printf(" %d", a[r][c]);
    printf("\n");
  }
}

int gcd(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main(void) {
  char a[ROWS][COLUMNS];
  int r, c;
  for (r = 0; r < ROWS; r++)
    for (c = r; c < COLUMNS; c++)
      if (gcd(r, c) == 1)
        a[r][c] = a[c][r] = 1;
      else
        a[r][c] = a[c][r] = 0;
  print_array(a, ROWS, COLUMNS);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.65.exe
 0 1 0 0 0 0 0 0 0 0
 1 1 1 1 1 1 1 1 1 1
 0 1 0 1 0 1 0 1 0 1
 0 1 1 0 1 1 0 1 1 0
 0 1 0 1 0 1 0 1 0 1
 0 1 1 1 1 0 1 1 1 1
 0 1 0 0 0 1 0 1 0 0
 0 1 1 1 1 1 1 0 1 1
 0 1 0 1 0 1 0 1 0 1
 0 1 1 0 1 1 0 1 1 0
--------------------------------------------------------------------- */

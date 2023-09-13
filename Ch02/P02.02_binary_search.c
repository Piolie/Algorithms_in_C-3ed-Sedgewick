/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 2.2
                             Binary search
------------------------------------------------------------------------
This program has the same functionality as Program 2.1, but it is much
more efficient.
--------------------------------------------------------------------- */

#include <stdio.h>

int search(int a[], int v, int l, int r) {
  while (r >= l) {
    int m = (l + r) / 2;
    if (v == a[m])
      return m;
    if (v < a[m])
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}

#define N 10

int main(void) {
  int a[N] = {0, 3, 5, 6, 7, 8}, v, l, r;

  printf("a[] = ");
  for (int i = 0; i < N; i++)
    printf("%d, ", a[i]);
  printf("\n");
  v = 2;
  l = 0;
  r = 9;
  printf("v = %d, l = %d, r = %d, index = %d\n", v, l, r, search(a, v, l, r));
  v = 3;
  l = 0;
  r = 9;
  printf("v = %d, l = %d, r = %d, index = %d\n", v, l, r, search(a, v, l, r));
  v = 3;
  l = 2;
  r = 9;
  printf("v = %d, l = %d, r = %d, index = %d\n", v, l, r, search(a, v, l, r));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
a[] = 0, 3, 5, 6, 7, 8, 0, 0, 0, 0,
v = 2, l = 0, r = 9, index = -1
v = 3, l = 0, r = 9, index = 1
v = 3, l = 2, r = 9, index = -1
--------------------------------------------------------------------- */

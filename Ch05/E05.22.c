/* ---------------------------------------------------------------------
                             EXERCISE 5.22
------------------------------------------------------------------------
Write a recursive program that computes the length of the ith mark in
a ruler with 2^N - 1 marks.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int rule(int l, int r, int h, int ith) {
  int h_l = 0;
  int h_r = 0;
  int m = (l + r) / 2;
  if (h > 0) {
    h_l = rule(l, m, h - 1, ith);
    if (m == ith)
      return h;
    // mark(m, h);
    h_r = rule(m, r, h - 1, ith);
  }
  return h_l | h_r;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  int ith = atoi(argv[2]);
  int l = 0;
  int r = 1 << N;
  int h = N;
  printf("N = %d, 2^N - 1 = %d marks\n", N, r - 1);
  printf("%d-th mark height = %d", ith, rule(l, r, h, ith));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.22.exe 3 4
N = 3, 2^N - 1 = 7 marks
4-th mark height = 3

./E05.22.exe 3 1
N = 3, 2^N - 1 = 7 marks
1-th mark height = 1

./E05.22.exe 8 128
N = 8, 2^N - 1 = 255 marks
128-th mark height = 8

./E05.22.exe 8 255
N = 8, 2^N - 1 = 255 marks
255-th mark height = 1
--------------------------------------------------------------------- */

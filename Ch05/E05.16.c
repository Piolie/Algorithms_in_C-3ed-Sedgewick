/* ---------------------------------------------------------------------
                             EXERCISE 5.16
------------------------------------------------------------------------
Write a recursive program that finds the maximum element in an array,
based on comparing the first element in the array against the maximum
element in the rest of the array (computed recursively).
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int max(int a[], int l, int N) {
  if (l == N - 1)
    return a[l];

  int m = max(a, l + 1, N);

  if (a[l] >= m)
    return a[l];

  return m;
}

void fill_array(int a[], int N) {
  for (int i = 0; i < N; i++)
    a[i] = rand();
}

void print_array(int a[], int N) {
  for (int i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);

  int a[N];
  fill_array(a, N);
  print_array(a, N);
  printf("Max = %d\n", max(a, 0, N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.16.exe 5
41 18467 6334 26500 19169
Max = 26500

./E05.16.exe 10
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
Max = 29358

./E05.16.exe 15
41 18467 6334 26500 19169 15724 11478 29358 26962 24464 5705 28145 23281 16827 9961
Max = 29358
--------------------------------------------------------------------- */

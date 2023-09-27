/* ---------------------------------------------------------------------
                             EXERCISE 5.18
------------------------------------------------------------------------
Modify the divide-and-conquer program for finding the maximum element in
an array (Program 5.6) to divide an array of size N into one part of
size k = 2^(ceil[lg N] - 1) and another of size N - k (so that the size
of at least one of the parts is a power of 2).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Let's see:
N =   3 => k = 2^1 = 2
N =   5 => k = 2^2 = 4
N =  10 => k = 2^3 = 8
N =  20 => k = 2^4 = 16
N =  30 => k = 2^5 = 16
N =  80 => k = 2^6 = 64
N = 100 => k = 2^6 = 64
N = 130 => k = 2^7 = 128

k is always the largest power of two that's less than N. Instead of
using the pow2, log2 and ceil functions from the math.h standard
library, I'll resort to a simple auxiliary function to calculate k.
--------------------------------------------------------------------- */

// #define DEBUG_E05_18

#ifdef DEBUG_E05_18
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#endif // #ifdef DEBUG_E05_18

int k(int N) {
  int k = 1;
  while (2 * k < N)
    k *= 2;
  return k;
}

Item max(Item a[], int l, int r) {
  Item u, v;
  int m = l + k(r - l + 1) - 1;
  if (l == r)
    return a[l];
  u = max(a, l, m);
  v = max(a, m + 1, r);
  if (u > v)
    return u;
  else
    return v;
}

#ifdef DEBUG_E05_18
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
  printf("Max = %d\n", max(a, 0, N - 1));
}
#endif // #ifdef DEBUG_E05_18

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.18.exe 5
41 18467 6334 26500 19169
Max = 26500

./E05.18.exe 10
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
Max = 29358

./E05.18.exe 15
41 18467 6334 26500 19169 15724 11478 29358 26962 24464 5705 28145 23281 16827 9961
Max = 29358
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 6.36
------------------------------------------------------------------------
Find the running time when you use shellsort with the increments 1 2 4 8
16 32 64 128 256 512 1024 2048 ... to sort a file consisting of the
integers 1, 2, ..., N in the odd positions and N + 1, N + 2, ..., 2N in
the even positions.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)                                                             \
  {                                                                            \
    Item t = A;                                                                \
    A = B;                                                                     \
    B = t;                                                                     \
  }
#define compexch(A, B)                                                         \
  if (less(B, A))                                                              \
  exch(A, B)

void shellsort(Item a[], int l, int r) {
  int i, j, k, h = 2;
  for (k = 0; (1 << k) < (r - l); k++)
    ;
  k--;
  for (; h > 0; h = 1 << k--) {
    for (i = l + h; i <= r; i++) {
      j = i;
      Item v = a[i];
      while (j >= l + h && less(v, a[j - h])) {
        a[j] = a[j - h];
        j -= h;
      }
      a[j] = v;
    }
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  int RUNS = 10000 / N + 1;
  Item *a = malloc(2 * N * sizeof(int));

  time_t time, total_time = 0;
  for (int r = 0; r < RUNS; r++) {
    for (int i = 0; i < 2 * N; i = i + 2) {
      a[i] = N + i / 2 + 1;
      a[i + 1] = i / 2 + 1;
    }

    time = clock();
    shellsort(a, 0, 2 * N - 1);
    total_time += clock() - time;
  }

  printf("Time for N = %d: %1.1e seconds\n", N,
         (double)total_time / RUNS / CLOCKS_PER_SEC);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E06.36.exe 10
Time for N = 10: 5.0e-06 seconds

./E06.36.exe 100
Time for N = 100: 5.0e-05 seconds

./E06.36.exe 1000
Time for N = 1000: 1.4e-03 seconds

./E06.36.exe 10000
Time for N = 10000: 2.2e-01 seconds

./E06.36.exe 100000
Time for N = 100000: 2.1e+01 seconds

./E06.36.exe 1000000
Time for N = 1000000: 2.7e+03 seconds
--------------------------------------------------------------------- */

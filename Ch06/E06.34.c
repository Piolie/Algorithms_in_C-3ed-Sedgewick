/* ---------------------------------------------------------------------
                             EXERCISE 6.34
------------------------------------------------------------------------
Show how to implement a shellsort with the increments 1 8 23 77 281 1073
4193 16577 ..., with direct calculations to get successive increments in
a manner similar to the code given for Knuth's increments.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
4^(i + 1) + 3 * 2^i + 1
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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

int gap(int i) {
  if (i < 1)
    return 1;
  return pow(4, i) + 3 * exp2(i - 1) + 1;
}

void shellsort(Item a[], int l, int r) {
  int k, h;
  for (k = 0; (h = gap(k)) < (r - l); k++)
    ;
  k--;

  for (; k >= 0; k--) {
    h = gap(k);

    for (int i = l + h; i <= r; i++) {
      int j = i;
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
  Item *a = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
    printf("%3d ", a[i]);
  }
  printf("\n");

  shellsort(a, 0, N - 1);

  for (int i = 0; i < N; i++)
    printf("%3d ", a[i]);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E06.34.exe 10
  1 563 193 808 585 479 350 895 822 746
  1 193 350 479 563 585 746 808 822 895
--------------------------------------------------------------------- */

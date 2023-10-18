/* ---------------------------------------------------------------------
                             EXERCISE 6.30
------------------------------------------------------------------------
Implement a version of bubble sort that alternates left-to-right and
right-to-left passes through the data. This (faster but more
complicated) algorithm is called shaker sort (see Figure 6.7).
--------------------------------------------------------------------- */

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

void shaker_sort(Item a[], int l, int r) {
  while (l < r) {
    for (int j = r; j > l; j--)
      compexch(a[j - 1], a[j]);
    l += 1;

    for (int j = l; j < r; j++)
      compexch(a[j], a[j + 1]);
    r -= 1;
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  Item *a = malloc(N * sizeof(int));

  for (int i = 0; i < N; i++)
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);

  for (int i = 0; i < N; i++)
    printf("%3d ", a[i]);
  printf("\n");

  shaker_sort(a, 0, N - 1);

  for (int i = 0; i < N; i++)
    printf("%3d ", a[i]);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E06.30.exe 10
  1 563 193 808 585 479 350 895 822 746
  1 193 350 479 563 585 746 808 822 895
--------------------------------------------------------------------- */

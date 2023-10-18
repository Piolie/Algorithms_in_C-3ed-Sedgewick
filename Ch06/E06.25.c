/* ---------------------------------------------------------------------
                             EXERCISE 6.25
------------------------------------------------------------------------
Develop an efficient implementation of bubble sort, with as few
instructions as possible in the inner loop. Make sure that your
"improvements" do not slow down the program!
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Adapted from the
[Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort#Optimizing_bubble_sort)
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

void bubble_improved(Item a[], int l, int r) {
  int i = l;
  do {
    int k = r;
    for (int j = r; j > i; j--)
      if less (a[j], a[j - 1]) {
        exch(a[j], a[j - 1]);
        k = j;
      }
    i = k - 1;
  } while (i < r - 1);
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

  bubble_improved(a, 0, N - 1);

  for (int i = 0; i < N; i++)
    printf("%3d ", a[i]);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E06.25.exe 10
  1 563 193 808 585 479 350 895 822 746
  1 193 350 479 563 585 746 808 822 895
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 6.24
------------------------------------------------------------------------
Do experiments to determine how many passes are saved, for random files
of N elements, when you add to bubble sort a test to terminate when the
file is sorted.
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

static int passesa = 0;
static int passesb = 0;

void bubble(Item a[], int l, int r) {
  for (int i = l; i < r; i++) {
    passesa++;
    for (int j = r; j > i; j--)
      compexch(a[j - 1], a[j]);
  }
}

void bubble_mod(Item a[], int l, int r) {
  int i, j, swapped;
  for (i = l; i < r; i++) {
    passesb++;
    swapped = 0;
    for (j = r; j > i; j--)
      if (less(a[j], a[j - 1])) {
        swapped = 1;
        exch(a[j], a[j - 1]);
      }
    if (!swapped)
      break;
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  Item *a = malloc(N * sizeof(int));
  Item *b = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++)
    a[i] = b[i] = 1000 * (1.0 * rand() / RAND_MAX);

  bubble(a, 0, N - 1);
  bubble_mod(b, 0, N - 1);

  printf("passesa = %d\n", passesa);
  printf("passesb = %d\n", passesb);
  printf("Saved passes = %d", passesa - passesb);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E06.24.exe 10
Saved passes = 4

./E06.24.exe 100
Saved passes = 14

./E06.24.exe 1000
Saved passes = 32

./E06.24.exe 10000
Saved passes = 62

./E06.24.exe 100000
Saved passes = 152
--------------------------------------------------------------------- */

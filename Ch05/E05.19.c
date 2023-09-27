/* ---------------------------------------------------------------------
                             EXERCISE 5.19
------------------------------------------------------------------------
Draw the tree corresponding to the recursive calls that your program
from Exercise 5.18 makes when the array size is 11.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
max(0, 10)
  max(0, 7)
    max(0, 3)
      max(0, 1)
        max(0, 0)
        max(1, 1)
      max(2, 3)
        max(2, 2)
        max(3, 3)
    max(4, 7)
      max(4, 5)
        max(4, 4)
        max(5, 5)
      max(6, 7)
        max(6, 6)
        max(7, 7)
  max(8, 10)
    max(8, 9)
      max(8, 8)
      max(9, 9)
    max(10, 10)
                      11
                       |
              /--------+-------\
             8                  3
             |                  |
        /--- + ---\            / \
       4           4          2   1
     /   \       /   \       / \
    2     2     2     2     1   1
   / \   / \   / \   / \
  1   1 1   1 1   1 1   1
--------------------------------------------------------------------- */

// #define DEBUG_E05_19

#ifdef DEBUG_E05_19
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#endif // #ifdef DEBUG_E05_19

int k(int N) {
  int k = 1;
  while (2 * k < N)
    k *= 2;
  return k;
}

Item max(Item a[], int l, int r) {
  static int depth = -1;
  depth++;
  printf("%*s", 2 * depth, "");
  printf("max(%d, %d)\n", l, r);
  Item u, v;
  int m = l + k(r - l + 1) - 1;
  if (l == r) {
    depth--;
    return a[l];
  }
  u = max(a, l, m);
  v = max(a, m + 1, r);
  if (u > v) {
    depth--;
    return u;
  } else {
    depth--;
    return v;
  }
}

#ifdef DEBUG_E05_19
void fill_array(int a[], int N) {
  for (int i = 0; i < N; i++)
    a[i] = rand();
}

void print_array(int a[], int N) {
  for (int i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(void) {
  int N = 11;
  int a[N];
  fill_array(a, N);
  print_array(a, N);
  printf("Max = %d\n", max(a, 0, N - 1));
}
#endif // #ifdef DEBUG_E05_19

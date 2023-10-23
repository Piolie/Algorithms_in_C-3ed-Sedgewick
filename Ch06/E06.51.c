/* ---------------------------------------------------------------------
                             EXERCISE 6.51
------------------------------------------------------------------------
Write an interface that defines a first-class abstract data type for
generic items (see Section 4.8), and provide an implementation where the
items are floating point numbers. Test your program with Programs 6.3
and 6.6.
--------------------------------------------------------------------- */

#include "Item.h" // #include "E06.51.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

struct item {
  double f;
};

double key(Item A) { return (A->f); }

int less(Item A, Item B) { return (A->f < B->f); }

void exch(Item A, Item B) {
  struct item t = *A;
  *A = *B;
  *B = t;
}

void compexch(Item A, Item B) {
  if (less(B, A))
    exch(A, B);
}

Item ITEMrand(void) {
  Item res = malloc(sizeof *res);
  res->f = ((double)rand() / RAND_MAX - 1.0 / 2) * 1000;
  return res;
}

int ITEMscan(Item *item) {
  int res = scanf("%lf", &((*item)->f));
  return res;
}

void ITEMshow(Item item) { printf("%.1e ", item->f); }

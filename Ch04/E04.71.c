/* ---------------------------------------------------------------------
                             EXERCISE 4.71
------------------------------------------------------------------------
Modify the implementation of POLYadd in Program 4.23 such that it
operates in a manner similar to POLYmult (and does not modify either of
its arguments).
--------------------------------------------------------------------- */

#include "POLY.h"
#include <stdio.h>
#include <stdlib.h>

struct poly {
  int N;
  int *a;
};

void showPOLY(Poly p) {
  for (int i = 0; i < p->N; i++)
    printf("%4d", p->a[i]);
  printf("\n");
}

Poly POLYterm(int coeff, int exp) {
  int i;
  Poly t = malloc(sizeof *t);
  t->a = malloc((exp + 1) * sizeof(int));
  t->N = exp + 1;
  t->a[exp] = coeff;
  for (i = 0; i < exp; i++)
    t->a[i] = 0;
  return t;
}

Poly POLYadd(Poly p, Poly q) {
  int i;
  Poly t;
  if (p->N < q->N) {
    t = p;
    p = q;
    q = t;
  }
  t = POLYterm(0, p->N - 1);
  for (i = 0; i < q->N; i++)
    t->a[i] = p->a[i] + q->a[i];
  for (i = q->N; i < p->N; i++)
    t->a[i] = p->a[i];
  return t;
}

Poly POLYmult(Poly p, Poly q) {
  int i, j;
  Poly t = POLYterm(0, (p->N - 1) + (q->N - 1));
  for (i = 0; i < p->N; i++)
    for (j = 0; j < q->N; j++)
      t->a[i + j] += p->a[i] * q->a[j];
  return t;
}

float POLYeval(Poly p, float x) {
  int i;
  double t = 0.0;
  for (i = p->N - 1; i >= 0; i--)
    t = t * x + p->a[i];
  return t;
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.71.exe 10 0.5
Binomial coefficients:
   1   2   1
   1   3   3   1
   1   4   6   4   1
   1   5  10  10   5   1
   1   6  15  20  15   6   1
   1   7  21  35  35  21   7   1
   1   8  28  56  70  56  28   8   1
   1   9  36  84 126 126  84  36   9   1
   1  10  45 120 210 252 210 120  45  10   1
   1  11  55 165 330 462 462 330 165  55  11   1
86.497559
--------------------------------------------------------------------- */

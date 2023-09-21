/* ---------------------------------------------------------------------
                             EXERCISE 4.72
------------------------------------------------------------------------
Modify the polynomial ADT interface, implementation, and client in the
text (Programs 4.21 through 4.23) such that there are no memory leaks.
To do so, define new operations POLYdestroy and POLYcopy, which should
free the memory for an object and copy one object's values to another,
respectively; and modify POLYadd and POLYmult to destroy their arguments
and return a newly created object, by convention.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Since the POLYadd function modifies its first argument, I'll return it
and only destroy the second. To the client there's no difference,
since they are not supposed to use any of the arguments after POLYadd.
--------------------------------------------------------------------- */

#include "POLY.h" // #include "E04.72_P04.22.h"
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
  t->a = malloc((exp + 1) * sizeof(*t->a));
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
  for (i = 0; i < q->N; i++)
    p->a[i] += q->a[i];
  POLYdestroy(q);
  return p;
}

Poly POLYmult(Poly p, Poly q) {
  int i, j;
  Poly t = POLYterm(0, (p->N - 1) + (q->N - 1));
  for (i = 0; i < p->N; i++)
    for (j = 0; j < q->N; j++)
      t->a[i + j] += p->a[i] * q->a[j];
  POLYdestroy(p);
  POLYdestroy(q);
  return t;
}

float POLYeval(Poly p, float x) {
  int i;
  double t = 0.0;
  for (i = p->N - 1; i >= 0; i--)
    t = t * x + p->a[i];
  return t;
}

void POLYdestroy(Poly p) {
  free(p->a);
  free(p);
}

Poly POLYcopy(Poly p) {
  Poly t = POLYterm(0, p->N - 1);
  for (int i = 0; i < p->N; i++)
    t->a[i] = p->a[i];
  return t;
}

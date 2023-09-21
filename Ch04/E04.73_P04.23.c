/* ---------------------------------------------------------------------
                             EXERCISE 4.73
------------------------------------------------------------------------
Extend the polynomial ADT given in the text to include integration and
differentiation of polynomials.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'll base this solution on E04.72.

The difference is now that the coefficients are floats, since the
integration operation introduces fractions. For convenience, I'll set
the integration constant to 0.
--------------------------------------------------------------------- */

// #define DEBUG_E04_73

#include "POLY.h" // #include "E04.73_P04.22.h"
#include <stdio.h>
#include <stdlib.h>

struct poly {
  int N;
  float *a;
};

void showPOLY(Poly p) {
  for (int i = 0; i < p->N; i++)
    printf("%+8.1f", p->a[i]);
  printf("\n");
}

Poly POLYterm(float coeff, int exp) {
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
  float t = 0.0;
  for (int i = p->N - 1; i >= 0; i--)
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

Poly POLYintegrate(Poly p) {
  Poly t = POLYterm(0, p->N);
  for (int i = p->N; i > 0; i--)
    t->a[i] = p->a[i - 1] / i;
  t->a[0] = 0;
  POLYdestroy(p);
  return t;
}

Poly POLYdifferentiate(Poly p) {
  Poly t = POLYterm(0, p->N - 2);
  for (int i = 0; i < p->N - 1; i++)
    t->a[i] = (i + 1) * p->a[i + 1];
  POLYdestroy(p);
  return t;
}

#ifdef DEBUG_E04_73
int main(void) {
  Poly p0 = POLYterm(0, 0);
  Poly p1 = POLYterm(1, 1);
  Poly p2 = POLYterm(2, 2);
  Poly p3 = POLYterm(3, 3);
  Poly p4 = POLYterm(4, 4);
  Poly p5 = POLYterm(5, 5);
  Poly p420 = POLYadd(p4, POLYadd(p2, p0));
  Poly p531 = POLYadd(p5, POLYadd(p3, p1));
  Poly p543210 = POLYmult(p420, p531);

  showPOLY(p543210);
  showPOLY(POLYdifferentiate(POLYcopy(p543210)));
  showPOLY(POLYintegrate(POLYcopy(p543210)));

  showPOLY(POLYdifferentiate(POLYintegrate(POLYcopy(p543210))));
  showPOLY(POLYintegrate(POLYdifferentiate(POLYcopy(p543210))));
}
#endif // #ifdef DEBUG_E04_73

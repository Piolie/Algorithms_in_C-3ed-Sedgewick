/* ---------------------------------------------------------------------
                             EXERCISE 4.75
------------------------------------------------------------------------
Extend your polynomial ADT from Exercise 4.73 to include polynomial
division and composition.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'll base this solution on E04.72.

The difference is now that the coefficients are floats, since the
integration operation introduces fractions. For convenience, I'll set
the integration constant to 0.
--------------------------------------------------------------------- */

// #define DEBUG_E04_75

#include "POLY.h" // #include "E04.75_P04.22.h"
#include <stdio.h>
#include <stdlib.h>

struct poly {
  int N;
  float *a;
};

void showPOLY(Poly p) {
  for (int i = 0; i < p->N; i++)
    printf("%+10.2f", p->a[i]);
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

Poly POLYbyscalar(Poly p, float k) {
  for (int i = 0; i < p->N; i++)
    p->a[i] *= k;
  return p;
}

int POLYdeg(Poly p) {
  int i;
  for (i = p->N - 1; i >= 0; i--)
    if (p->a[i] != 0.0)
      break;
  return i;
}

int POLYisnull(Poly p) { return POLYdeg(p) == -1; }

Poly POLYdivide(Poly n, Poly d) {
  Poly q = POLYterm(0, 0);
  Poly r = n;

  int deg_d = POLYdeg(d);
  int deg_r = POLYdeg(r);
  float lead_d = d->a[deg_d];
  while (!POLYisnull(r) && (deg_r >= deg_d)) {
    float lead_r = r->a[deg_r];
    Poly t = POLYterm(lead_r / lead_d, deg_r - deg_d);
    q = POLYadd(q, POLYcopy(t));
    r = POLYadd(r, POLYbyscalar(POLYmult(t, POLYcopy(d)), -1));
    deg_r = POLYdeg(r);
  }
  POLYdestroy(d);
  POLYdestroy(r);
  return q;
}

Poly POLYcompose(Poly p, Poly q) {
  Poly t = POLYterm(0, 0);
  for (int i = 1; i < p->N; i++) {
    Poly m = POLYcopy(q);
    for (int j = 1; j < i; j++)
      m = POLYmult(m, POLYcopy(q));
    t = POLYadd(t, POLYbyscalar(m, p->a[i]));
  }
  int pa0 = p->a[0];
  POLYdestroy(p);
  POLYdestroy(q);
  return POLYadd(t, POLYterm(pa0, 0));
}

#ifdef DEBUG_E04_75
int main(void) {
  Poly p0 = POLYterm(0, 0);
  Poly p1 = POLYterm(1, 1);
  Poly p2 = POLYterm(2, 2);
  Poly p3 = POLYterm(3, 3);
  Poly p4 = POLYterm(4, 4);
  Poly p5 = POLYterm(5, 5);
  Poly p420 = POLYadd(p4, POLYadd(p2, p0));
  Poly p531 = POLYadd(p5, POLYadd(p3, p1));

  for (float f = 0; f < 21; f++)
    printf("%10d", (int)f);
  printf("\n");

  showPOLY(p531);
  showPOLY(p420);

  showPOLY(POLYcompose(POLYcopy(p420), POLYcopy(p531)));
  showPOLY(POLYcompose(POLYcopy(p531), POLYcopy(p420)));

  showPOLY(POLYdivide(POLYcopy(p531), POLYcopy(p420)));
  showPOLY(POLYdivide(p420, p531));
}
#endif // #ifdef DEBUG_E04_75

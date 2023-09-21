/* ---------------------------------------------------------------------
                             EXERCISE 4.74
------------------------------------------------------------------------
Modify your polynomial ADT from Exercise 4.73 to ignore all terms with
exponents greater than or equal to an integer M, which is provided by
the client at initialization.
--------------------------------------------------------------------- */

// #define DEBUG_E04_74

#include "POLY.h" // #include "E04.74_P04.22.h"
#include <stdio.h>
#include <stdlib.h>

struct poly {
  int N;
  float *a;
};

static int MAX_EXP = -1;

void POLYinit(int M) {
  if (MAX_EXP == -1)
    MAX_EXP = M;
}

Poly POLYtrunc(Poly p) {
  if (p->N > MAX_EXP) {
    Poly t = POLYterm(0, MAX_EXP - 1);
    for (int i = 0; i < MAX_EXP; i++)
      t->a[i] = p->a[i];
    POLYdestroy(p);
    return t;
  } else
    return p;
}

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
  return POLYtrunc(t);
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
  return POLYtrunc(t);
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
  return POLYtrunc(t);
}

Poly POLYdifferentiate(Poly p) {
  Poly t = POLYterm(0, p->N - 2);
  for (int i = 0; i < p->N - 1; i++)
    t->a[i] = (i + 1) * p->a[i + 1];
  POLYdestroy(p);
  return t;
}

#ifdef DEBUG_E04_74
int main(void) {
  POLYinit(5);
  printf("MAX_EXP = %d\n", MAX_EXP);
  Poly p0 = POLYterm(0, 0);
  Poly p1 = POLYterm(1, 1);
  Poly p2 = POLYterm(2, 2);
  Poly p3 = POLYterm(3, 3);
  Poly p4 = POLYterm(4, 4);
  Poly p5 = POLYterm(5, 5);

  POLYinit(20);
  printf("MAX_EXP = %d\n", MAX_EXP);

  Poly p420 = POLYadd(p4, POLYadd(p2, p0));
  showPOLY(p420);

  Poly p531 = POLYadd(p5, POLYadd(p3, p1));
  showPOLY(p531);

  Poly p543210 = POLYmult(p420, p531);
  showPOLY(p543210);
}
#endif // #ifdef DEBUG_E04_74

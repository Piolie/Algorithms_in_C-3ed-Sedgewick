/* ---------------------------------------------------------------------
                             EXERCISE 4.70
------------------------------------------------------------------------
Provide an implementation for the polynomial ADT given in the text
(Program 4.22) that uses linked lists as the underlying data structure.
Your lists should not contain any nodes corresponding to terms with
coefficient value 0.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
In this implementation, the terms are kept in order, from highest to
lowest degree, so as to facilitate the application of Horner's rule for
evaluation.

I've included a couple of auxiliary functions:
- NEW: creates a new POLYnode, in the style used in the book;
- POLYcopy: returns a copy of the polynomial argument; and
- POLYbymonomial: multiplies its polynomial argument by a monomial with
  given coefficient and exponent.

Like in P04.23, the first operand is modified during the add operation,
unless p->head == NULL, in which case it returns a copy of the second
operand. The multiply operation does not modify the arguments, but is
very leaky, because it uses many copies of the first argument that it
never frees.

If POLYterm is invoked with a coefficient equal to 0, that term is kept
and propagated, no precautions are taken to avoid it. The same happens
when the addition of two polynomials yields zero terms.

For the application of Horner's method to the evaluation of polynomials,
see: [Polynomial evaluation and long
division](https://en.wikipedia.org/wiki/Horner%27s_method#Polynomial_evaluation_and_long_division)

The makefile compiles P04.21 with this implementation. The output is the
same.
--------------------------------------------------------------------- */

// #define DEBUG_E04_70

#include "POLY.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct POLYnode *link;
struct POLYnode {
  int coeff;
  int exp;
  link next;
};

struct poly {
  link head;
};

link NEW(int coeff, int exp, link next) {
  link x = malloc(sizeof *x);
  x->coeff = coeff;
  x->exp = exp;
  x->next = next;
  return x;
}

Poly POLYcopy(Poly p) {
  Poly q = malloc(sizeof(*q));

  link tp = p->head;
  q->head = NEW(tp->coeff, tp->exp, NULL);

  link tq = q->head;
  for (tp = tp->next; tp; tp = tp->next) {
    tq->next = NEW(tp->coeff, tp->exp, NULL);
    tq = tq->next;
  }
  return q;
}

Poly POLYbymonomial(Poly p, int coeff, int exp) {
  for (link tp = p->head; tp; tp = tp->next) {
    tp->coeff *= coeff;
    tp->exp += exp;
  }
  return p;
}

#ifdef DEBUG_E04_70
void showPOLY(Poly p) { // DEBUG
  for (link t = p->head; t; t = t->next) {
    printf("%2d*x^%d", t->coeff, t->exp);
    printf(" --> ");
  }
  printf("*\n");
}

#else  // #ifdef DEBUG_E04_70

void showPOLY(Poly p) {
  link tp = p->head;
  int d = tp->exp;
  printf("%4d", tp->coeff);
  for (tp = tp->next; tp; tp = tp->next) {
    for (int i = 1; i < d - tp->exp; i++)
      printf("%4d", 0);
    printf("%4d", tp->coeff);
    d = tp->exp;
  }
  for (int i = 0; i < d; i++)
    printf("%4d", 0);
  printf("\n");
}
#endif // #ifdef DEBUG_E04_70

Poly POLYterm(int coeff, int exp) {
  Poly p = malloc(sizeof *p);
  p->head = NEW(coeff, exp, NULL);
  return p;
}

Poly POLYadd(Poly p, Poly q) {
  if (p->head) {
    link tp = p->head;
    link tq = q->head;
    while (tq) {
      if (tp->exp == tq->exp) { // same degree, add coeffs
        tp->coeff += tq->coeff;
        tq = tq->next;
        if (tp->next)
          tp = tp->next;
      } else if (tp->exp < tq->exp) {
        tp->next = NEW(tp->coeff, tp->exp, tp->next);
        tp->coeff = tq->coeff;
        tp->exp = tq->exp;
        tq = tq->next;
      } else { // (tp->exp > tq->exp)
        if (tp->next)
          tp = tp->next;
        else {
          tp->next = NEW(tq->coeff, tq->exp, NULL);
          tq = tq->next;
        }
      }
    }
    return p;
  } else
    return POLYcopy(q);
}

Poly POLYmult(Poly p, Poly q) {
  Poly r = malloc(sizeof(*r));
  r->head = NULL;
  for (link tq = q->head; tq; tq = tq->next) {
    r = POLYadd(r, POLYbymonomial(POLYcopy(p), tq->coeff, tq->exp));
  }
  return r;
}

float POLYeval(Poly p, float x0) {
  link tp = p->head;
  double t = tp->coeff;
  int d = tp->exp;
  for (tp = tp->next; tp; tp = tp->next) {
    for (int i = 1; i < d - tp->exp; i++)
      t *= x0;
    t = tp->coeff + t * x0;
    d = tp->exp;
  }
  for (int i = 0; i < d; i++)
    t *= x0;
  return t;
}

#ifdef DEBUG_E04_70
int main(void) {
  Poly p0 = POLYterm(0, 0);
  Poly p1 = POLYterm(1, 1);
  Poly p2 = POLYterm(2, 2);
  Poly p3 = POLYterm(3, 3);
  Poly p4 = POLYterm(4, 4);
  Poly p5 = POLYterm(5, 5);
  Poly p420 = POLYadd(p4, POLYadd(p2, p0));
  showPOLY(p420);
  Poly p531 = POLYadd(p5, POLYadd(p3, p1));
  showPOLY(p531);
  Poly p543210 = POLYmult(p420, p531);
  showPOLY(p543210);
  float where = 3.0;
  printf("POLYeval(p420, %f) = %f\n", where, POLYeval(p420, where));
  printf("POLYeval(p531, %f) = %f\n", where, POLYeval(p531, where));
  printf("POLYeval(p543210, %f) = %f\n", where, POLYeval(p543210, where));
}
#endif // #ifdef DEBUG_E04_70

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.70.exe 10 0.5
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

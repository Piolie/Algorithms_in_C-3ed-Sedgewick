/* ---------------------------------------------------------------------
                             EXERCISE 6.50
------------------------------------------------------------------------
Write an interface and implementation for the generic item data type to
support having the sorting methods sort complex numbers x + iy using the
magnitude sqrt(x^2 + y^2) for the key. Note: Ignoring the square root is
likely to improve efficiency.
--------------------------------------------------------------------- */

#include "complex.h"

typedef double complex Item;
#define key(A) (creal(A) * creal(A) + cimag(A) * cimag(A))
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

Item ITEMrand(void);
int ITEMscan(Item *);
void ITEMshow(Item);

/* ---------------------------------------------------------------------
                             EXERCISE 4.79
------------------------------------------------------------------------
Develop an ADT that provides clients with the ability to perform
algebraic operations on vectors of floating-point numbers.
--------------------------------------------------------------------- */

// #define DEBUG_E04_79

#include "FLOATVEC.h" // #include "E04.79_interface.h"
#include <stdio.h>
#include <stdlib.h>

struct fvec {
  int N;
  float *vec;
};

void FVECshow(Fvec v) {
  for (int i = 0; i < v->N; i++)
    printf("%10.2f", v->vec[i]);
  printf("\n");
}

Fvec FVECinit(int len) {
  Fvec v = malloc(sizeof(*v));
  v->N = len;
  v->vec = malloc(len * sizeof(*v->vec));
  for (int i = 0; i < len; i++)
    v->vec[i] = 0;
  return v;
}

void FVECset(Fvec v, int pos, float val) { v->vec[pos] = val; }

Fvec FVECadd(Fvec u, Fvec v) {
  for (int i = 0; i < u->N; i++) {
    u->vec[i] += v->vec[i];
  }
  return u;
}

Fvec FVECmult(Fvec u, Fvec v) {
  for (int i = 0; i < u->N; i++) {
    u->vec[i] *= v->vec[i];
  }
  return u;
}

#ifdef DEBUG_E04_79
int main(void) {
  int len = 5;
  Fvec v1 = FVECinit(len);
  Fvec v2 = FVECinit(len);
  for (int i = 0; i < len; i++) {
    FVECset(v1, i, i);
    FVECset(v2, i, i);
  }
  FVECshow(v1);
  FVECshow(v2);
  FVECshow(FVECadd(v1, v2));
  FVECshow(FVECmult(v1, v2));
}
#endif // #ifdef DEBUG_E04_79

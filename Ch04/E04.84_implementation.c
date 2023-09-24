/* ---------------------------------------------------------------------
                             EXERCISE 4.84
------------------------------------------------------------------------
Write an interface and an implementation for an index set ADT, which
processes sets of integers in the range 0 to M - 1 (where M is a defined
constant) and includes operations for creating a set, computing the
union of two sets, computing the intersection of two sets, computing the
complement of a set, computing the difference of two sets, and printing
out the contents of a set. In your implementation, use an array of M - 1
0-1 values to represent each set.
--------------------------------------------------------------------- */

#include "SET.h" // #include "E04.84_interface.h"
#include <stdio.h>
#include <stdlib.h>

struct set {
  int M;
  unsigned char *elems;
};

Set SETcreate(int M) {
  Set set = malloc(sizeof(*set));
  set->M = M;
  set->elems = malloc(M * sizeof(*set->elems));
  for (int i = 0; i < M; i++)
    set->elems[i] = 0;

  return set;
}

int SETaddelement(Set set, int e) {
  if (set->elems[e])
    return 0;

  set->elems[e] = 1;
  return 1;
}

int SETremelement(Set set, int e) {
  if (!set->elems[e])
    return 0;

  set->elems[e] = 0;
  return 1;
}

Set SETunion(Set s1, Set s2) {
  int M = s1->M;
  Set sunion = SETcreate(M);
  for (int i = 0; i < M; i++)
    sunion->elems[i] = s1->elems[i] || s2->elems[i];
  return sunion;
}

Set SETinter(Set s1, Set s2) {
  int M = s1->M;
  Set sinter = SETcreate(M);
  for (int i = 0; i < M; i++)
    sinter->elems[i] = s1->elems[i] && s2->elems[i];
  return sinter;
}

Set SETcompl(Set s) {
  int M = s->M;
  Set scompl = SETcreate(M);
  for (int i = 0; i < M; i++)
    scompl->elems[i] = !s->elems[i];
  return scompl;
}

Set SETdiff(Set s1, Set s2) {
  int M = s1->M;
  Set sdiff = SETcreate(M);
  for (int i = 0; i < M; i++)
    sdiff->elems[i] = s1->elems[i] * (1 - s2->elems[i]);
    // sdiff->elems[i] = s1->elems[i] - (s1->elems[i] && s2->elems[i]);
  return sdiff;
}

void SETprint(Set s) {
  int M = s->M;
  for (int i = 0; i < M; i++)
    printf("%3d ", s->elems[i]);
}

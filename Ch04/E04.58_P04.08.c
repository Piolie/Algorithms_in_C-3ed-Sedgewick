/* ---------------------------------------------------------------------
                             EXERCISE 4.58
------------------------------------------------------------------------
Convert the equivalence-relations ADT in Section 4.5 to a first-class
type.
--------------------------------------------------------------------- */

#include "UF.h"
#include <stdlib.h>

struct uf {
  int *id;
  int *sz;
};

Uf UFinit(int N) {
  int i;
  Uf uf = malloc(sizeof(*uf));
  uf->id = malloc(N * sizeof(int));
  uf->sz = malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    uf->id[i] = i;
    uf->sz[i] = 1;
  }
  return uf;
}

int find(Uf uf, int x) {
  int i = x;
  while (i != uf->id[i])
    i = uf->id[i];
  return i;
}

int UFfind(Uf uf, int p, int q) { return (find(uf, p) == find(uf, q)); }

void UFunion(Uf uf, int p, int q) {
  int i = find(uf, p), j = find(uf, q);
  if (i == j)
    return;
  if (uf->sz[i] < uf->sz[j]) {
    uf->id[i] = j;
    uf->sz[j] += uf->sz[i];
  } else {
    uf->id[j] = i;
    uf->sz[i] += uf->sz[j];
  }
}

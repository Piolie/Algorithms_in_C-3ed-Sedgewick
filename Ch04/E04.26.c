/* ---------------------------------------------------------------------
                             EXERCISE 4.26
------------------------------------------------------------------------
Modify Program 4.8 to use path compression by halving.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The only modification is in the find function, where we make each link
skip to the next node in the path on the way up the tree.
--------------------------------------------------------------------- */

#include "UF.h"
#include <stdlib.h>

static int *id, *sz;

void UFinit(int N) {
  id = malloc(N * sizeof(*id));
  sz = malloc(N * sizeof(*sz));
  for (int i = 0; i < N; i++) {
    id[i] = i;
    sz[i] = 1;
  }
}

int find(int x) {
  int i;
  for (i = x; i != id[i]; i = id[i])
    id[i] = id[id[i]];
  return i;
}

int UFfind(int p, int q) { return find(p) == find(q); }

void UFunion(int p, int q) {
  int i = find(p), j = find(q);
  if (i == j)
    return;
  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
}

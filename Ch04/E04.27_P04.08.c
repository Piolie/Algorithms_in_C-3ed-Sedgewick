/* ---------------------------------------------------------------------
                             EXERCISE 4.27
------------------------------------------------------------------------
Remove the inefficiency mentioned in the text by adding an operation to
Program 4.6 that combines union and find, providing an implementation in
Program 4.8, and modifying Program 4.7 accordingly.
--------------------------------------------------------------------- */

#include "UF.h"
#include <stdlib.h>

static int *id, *sz;

void UFinit(int N) {
  int i;
  id = malloc(N * sizeof(int));
  sz = malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    id[i] = i;
    sz[i] = 1;
  }
}

int find(int x) {
  int i = x;
  while (i != id[i])
    i = id[i];
  return i;
}

int UFfind(int p, int q) { return (find(p) == find(q)); }

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

int UFfind_union(int p, int q) {
  int i = UFfind(p, q);
  UFunion(p, q);
  return i;
}

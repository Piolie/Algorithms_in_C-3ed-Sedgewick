/* ---------------------------------------------------------------------
                             EXERCISE 4.28
------------------------------------------------------------------------
Modify the interface (Program 4.6) and implementation (Program 4.8) to
provide a function that will return the number of nodes known to be
connected to a given node.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Remember, from Program 1.3, that we keep:
  an additional array sz for the purpose of maintaining, for each object
  with id [i] == i, the number of nodes in the associated tree, so that
  the union operation can link the smaller of the two specified trees to
  the larger, thus preventing the growth of long paths in the trees.
Thus, we only need to find the root of the node and retrieve the
associated size from the sz array. Since each node is at least
connected with itself, UFconnected_nodes always returns >= 1.
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

int UFconnected_nodes(int p) {
  return sz[find(p)];
}

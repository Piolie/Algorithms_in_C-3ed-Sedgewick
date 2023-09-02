/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 1.4
                      Path compression by halving
------------------------------------------------------------------------
        (Weighted quick-union with path compression by halving)
------------------------------------------------------------------------
If we replace the for loops in Program 1.3 by this code, we halve the
length of any path that we traverse. The net result of this change is
that the trees become almost completely flat after a long sequence of
operations.
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10000

int main(void) {
  int i, j, p, q, id[N], sz[N];
  for (i = 0; i < N; i++) {
    id[i] = i;
    sz[i] = 1;
  }
  while (scanf("%d %d", &p, &q) == 2) {
    for (i = p; i != id[i]; i = id[i]) {
      int t = i;
      i = id[id[t]];
      id[t] = i;
    }
    for (j = q; j != id[j]; j = id[j]) {
      int t = j;
      j = id[id[t]];
      id[t] = j;
    }
    if (i == j)
      continue;
    if (sz[i] < sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
    } else {
      id[j] = i;
      sz[i] += sz[j];
    }
    printf(" %d %d\n", p, q);
  }
}

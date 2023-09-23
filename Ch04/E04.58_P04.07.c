/* ---------------------------------------------------------------------
                             EXERCISE 4.58
------------------------------------------------------------------------
Convert the equivalence-relations ADT in Section 4.5 to a first-class
type.
--------------------------------------------------------------------- */

#include "UF.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  int p, q, N = atoi(argv[1]);
  Uf uf = UFinit(N);
  while (scanf("%d %d", &p, &q) == 2)
    if (!UFfind(uf, p, q)) {
      UFunion(uf, p, q);
      printf(" %d %d\n", p, q);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.58.exe 10
0 2
 0 2
1 4
 1 4
2 5
 2 5
3 6
 3 6
0 4
 0 4
6 0
 6 0
1 3
^Z
--------------------------------------------------------------------- */
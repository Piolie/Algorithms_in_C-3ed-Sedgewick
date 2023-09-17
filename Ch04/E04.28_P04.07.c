/* ---------------------------------------------------------------------
                             EXERCISE 4.28
------------------------------------------------------------------------
Modify the interface (Program 4.6) and implementation (Program 4.8) to
provide a function that will return the number of nodes known to be
connected to a given node.
--------------------------------------------------------------------- */

#include "UF.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  int p, q, N = atoi(argv[1]);
  int M = atoi(argv[2]);
  UFinit(N);
  while (scanf("%d %d", &p, &q) == 2)
    if (!UFfind(p, q)) {
      UFunion(p, q);
      printf(" %d %d\n", p, q);
    }

  printf("Nodes connected to %d = %d\n", M, UFconnected_nodes(M));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Figure 1.6:
./E04.28.exe 100 6
3 4
 3 4
4 9
 4 9
8 0
 8 0
2 3
 2 3
5 6
 5 6
2 9
5 9
 5 9
7 3
 7 3
4 8
 4 8
5 6
0 2
6 1
 6 1
^Z
Nodes connected to 6 = 10

Figure 1.8:
./E04.28.exe 100 0
0 1
 0 1
2 3
 2 3
4 5
 4 5
6 7
 6 7
8 9
 8 9
0 2
 0 2
4 6
 4 6
0 4
 0 4
0 8
 0 8
^Z
Nodes connected to 0 = 10
--------------------------------------------------------------------- */
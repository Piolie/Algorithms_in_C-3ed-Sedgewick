/* ---------------------------------------------------------------------
                             EXERCISE 4.27
------------------------------------------------------------------------
Remove the inefficiency mentioned in the text by adding an operation to
Program 4.6 that combines union and find, providing an implementation in
Program 4.8, and modifying Program 4.7 accordingly.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The relevant section of the book states:
  This ADT leads to programs that are slightly less efficient than those
  in Chapter 1 for the connectivity application, because it does not
  take advantage of the property of that client that every union
  operation is immediately preceded by a find operation.
I guess the inefficiency lies in that P04.07 calls UFfind and then
UFunion, which results in the local function find being called twice for
each node. We can avoid this double call by providing another function
that does both things at the same time.
--------------------------------------------------------------------- */

#include "UF.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  int p, q, N = atoi(argv[1]);
  UFinit(N);
  while (scanf("%d %d", &p, &q) == 2)
    if (!UFfind_union(p, q)) {
      printf(" %d %d\n", p, q);
    }
}

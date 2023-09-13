/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 1.2
              Quick-union solution to connectivity problem
------------------------------------------------------------------------
If we replace the body of the while loop in Program 1.1 by this code, we
have a program that meets the same specifications as Program 1.1, but
does less computation for the union operation at the expense of more
computation for the find operation. The for loops and sub-subsequent if
statement in this code specify the necessary and sufficient conditions
on the id array for p and q to be connected. The assignment statement
id[i] = j implements the union operation.
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10000

int main(void) {
  int i, j, p, q, id[N];
  for (i = 0; i < N; i++)
    id[i] = i;
  while (scanf("%d %d", &p, &q) == 2) {
    for (i = p; i != id[i]; i = id[i])
      ;
    for (j = q; j != id[j]; j = id[j])
      ;
    if (i == j)
      continue;

    id[i] = j;

    printf(" %d %d\n", p, q);
  }
}

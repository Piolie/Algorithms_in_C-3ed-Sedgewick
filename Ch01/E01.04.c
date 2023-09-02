/* ---------------------------------------------------------------------
                              EXERCISE 1.4
------------------------------------------------------------------------
Show the contents of the id array after each union operation when you
use the quick-find algorithm (Program 1.1) to solve the connectivity
problem for the sequence 0-2, 1-4, 2-5, 3-6, 0-4, 6-0, and 1-3. Also
give the number of times the program accesses the id array for each
input pair.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Notes:
  - only shows first 10 entries of id;
  - the access counter ignores the initialization and print_id steps;
  - lvalue assignments are _not_ considered accesses:
      id[i] = id[q] -> 1 access;
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10

void print_id(int id[]) {
  printf("id = ");
  for (int i = 0; i < 10; i++)
    printf("%d ", id[i]);
  printf("...\n");
}

int main(void) {
  int i, p, q, t, id[N], access_count;
  for (i = 0; i < N; i++)
    id[i] = i;
  while (scanf("%d %d", &p, &q) == 2) {
    access_count = 2;
    if (id[p] == id[q])
      continue;
    for (access_count++, t = id[p], i = 0; i < N; i++) {
      access_count++;
      if (id[i] == t) {
        access_count += 1;
        id[i] = id[q];
      }
    }
    print_id(id);
    printf(" %d %d\n", p, q);
    printf("Number of accesses = %d\n", access_count);
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
0 2
id = 2 1 2 3 4 5 6 7 8 9 ...
 0 2
Number of accesses = 10004
1 4
id = 2 4 2 3 4 5 6 7 8 9 ...
 1 4
Number of accesses = 10004
2 5
id = 5 4 5 3 4 5 6 7 8 9 ...
 2 5
Number of accesses = 10005
3 6
id = 5 4 5 6 4 5 6 7 8 9 ...
 3 6
Number of accesses = 10004
0 4
id = 4 4 4 6 4 4 6 7 8 9 ...
 0 4
Number of accesses = 10006
6 0
id = 4 4 4 4 4 4 4 7 8 9 ...
 6 0
Number of accesses = 10005
1 3
--------------------------------------------------------------------- */

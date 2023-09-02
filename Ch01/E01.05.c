/* ---------------------------------------------------------------------
                              EXERCISE 1.5
------------------------------------------------------------------------
Do Exercise 1.4, but use the quick-union algorithm (Program 1.2).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Notes:
  - only shows first 10 entries of id;
  - the access counter ignores the initialization and print_id steps;
  - lvalue assignments are _not_ considered accesses:
      id[i] = id[q] -> 1 access;
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10000

void print_id(int id[]) {
  printf("id = ");
  for (int i = 0; i < 10; i++)
    printf("%d ", id[i]);
  printf("...\n");
}

int main(void) {
  int i, p, q, j, id[N], access_count;
  for (i = 0; i < N; i++)
    id[i] = i;
  while (scanf("%d %d", &p, &q) == 2) {
    for (i = p, access_count++; i != id[i]; access_count += 2, i = id[i])
      ;
    for (j = q, access_count++; j != id[j]; access_count += 2, j = id[j])
      ;
    if (i == j)
      continue;

    id[i] = j;

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
Number of accesses = 2
1 4
id = 2 4 2 3 4 5 6 7 8 9 ...
 1 4
Number of accesses = 4
2 5
id = 2 4 5 3 4 5 6 7 8 9 ...
 2 5
Number of accesses = 6
3 6
id = 2 4 5 6 4 5 6 7 8 9 ...
 3 6
Number of accesses = 8
0 4
id = 2 4 5 6 4 4 6 7 8 9 ...
 0 4
Number of accesses = 14
6 0
id = 2 4 5 6 4 4 4 7 8 9 ...
 6 0
Number of accesses = 22
1 3
--------------------------------------------------------------------- */

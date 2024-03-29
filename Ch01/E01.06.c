/* ---------------------------------------------------------------------
                              EXERCISE 1.6
------------------------------------------------------------------------
Give the contents of the id array after each union operation for the
weighted quick-union algorithm running on the examples corresponding to
Figure 1.7 and Figure 1.8.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Notes:
  - only shows first 10 entries of id.
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
  int i, j, p, q, id[N], sz[N];
  for (i = 0; i < N; i++) {
    id[i] = i;
    sz[i] = 1;
  }
  while (scanf("%d %d", &p, &q) == 2) {
    for (i = p; i != id[i]; i = id[i])
      ;
    for (j = q; j != id[j]; j = id[j])
      ;
    if (i == j)
      continue;
    if (sz[i] < sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
    } else {
      id[j] = i;
      sz[i] += sz[j];
    }
    print_id(id);
    printf(" %d %d\n", p, q);
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Figure 1.7:
    3-4, 4-9, 8-0, 2-3, 5-6, 2-9, 5-9, 7-3, 4-8, 5-6, 0-2, 6-1
------------------------------------------------------------------------
3 4
id = 0 1 2 3 3 5 6 7 8 9 ...
 3 4
4 9
id = 0 1 2 3 3 5 6 7 8 3 ...
 4 9
8 0
id = 8 1 2 3 3 5 6 7 8 3 ...
 8 0
2 3
id = 8 1 3 3 3 5 6 7 8 3 ...
 2 3
5 6
id = 8 1 3 3 3 5 5 7 8 3 ...
 5 6
2 9
5 9
id = 8 1 3 3 3 3 5 7 8 3 ...
 5 9
7 3
id = 8 1 3 3 3 3 5 3 8 3 ...
 7 3
4 8
id = 8 1 3 3 3 3 5 3 3 3 ...
 4 8
5 6
0 2
6 1
id = 8 3 3 3 3 3 5 3 3 3 ...
 6 1
------------------------------------------------------------------------
Figure 1.8:
    0-1, 2-3, 4-5, 6-7, 8-9, 0-2, 4-6, 0-4
------------------------------------------------------------------------
0 1
id = 0 0 2 3 4 5 6 7 8 9 ...
 0 1
2 3
id = 0 0 2 2 4 5 6 7 8 9 ...
 2 3
4 5
id = 0 0 2 2 4 4 6 7 8 9 ...
 4 5
6 7
id = 0 0 2 2 4 4 6 6 8 9 ...
 6 7
8 9
id = 0 0 2 2 4 4 6 6 8 8 ...
 8 9
0 2
id = 0 0 0 2 4 4 6 6 8 8 ...
 0 2
4 6
id = 0 0 0 2 4 4 4 6 8 8 ...
 4 6
0 4
id = 0 0 0 2 0 4 4 6 8 8 ...
 0 4
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 1.19
------------------------------------------------------------------------
Give an example showing that modifying quick union (Program 1.2) to
implement full path compression (see Exercise 1.16) is not sufficient to
ensure that the trees have no long paths.
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10000

void print_id(int id[]) {
  printf("id = ");
  for (int i = 0; i < 10; i++)
    printf("%d ", id[i]);
  printf("...\n");
}

int find(int id[], int i) {
  if (i == id[i])
    return i;
  return id[i] = find(id, id[i]);
}

int main(void) {
  int i, p, q, j, id[N];
  for (i = 0; i < N; i++)
    id[i] = i;
  while (scanf("%d %d", &p, &q) == 2) {
    i = find(id, p);
    j = find(id, q);
    if (i == j)
      continue;

    id[i] = j;

    print_id(id);
    printf(" %d %d\n", p, q);
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
The sequence 0-1, 1-2, 2-3, ... produces the longest path, because the
new single-node tree is always added as a root, so the compression never
kicks in.
------------------------------------------------------------------------
0 1
id = 1 1 2 3 4 5 6 7 8 9
 0 1
1 2
id = 1 2 2 3 4 5 6 7 8 9 ...
 1 2
2 3
id = 1 2 3 3 4 5 6 7 8 9 ...
 2 3
3 4
id = 1 2 3 4 4 5 6 7 8 9 ...
 3 4
4 5
id = 1 2 3 4 5 5 6 7 8 9 ...
 4 5
5 6
id = 1 2 3 4 5 6 6 7 8 9 ...
 5 6
6 7
id = 1 2 3 4 5 6 7 7 8 9 ...
 6 7
7 8
id = 1 2 3 4 5 6 7 8 8 9 ...
 7 8
8 9
id = 1 2 3 4 5 6 7 8 9 9 ...
 8 9
--------------------------------------------------------------------- */

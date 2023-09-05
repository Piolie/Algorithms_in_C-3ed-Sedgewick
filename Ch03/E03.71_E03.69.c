/* ---------------------------------------------------------------------
                             EXERCISE 3.71
------------------------------------------------------------------------
A directed graph is one where vertex connections have orientations:
edges go from one vertex to another. Do Exercises 3.69 and 3.70 under
the assumption that the input pairs represent a directed graph, with
i-j signifying that there is an edge from i to j. Also, draw the graph,
using arrows to indicate edge orientations.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Retake of E03.69.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define V 10

void print_2D_matrix(int rows, int cols, int matrix[rows][cols]) {
  const int digits = 4;
  printf("%*s", digits + 2, " ");
  for (int c = 0; c < cols; c++)
    printf("%*d", digits, c);
  printf("\n");
  printf("%*s", digits + 2, " ");
  for (int r = 0; r < digits * cols + 1; r++)
    printf("-");
  printf("\n");

  for (int r = 0; r < rows; r++) {
    printf("%*d |", digits, r);
    for (int c = 0; c < cols; c++)
      printf("%*d", digits, matrix[r][c]);
    printf("\n");
  }
}

int main(void) {
  int i, j, adj[V][V];
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      adj[i][j] = 0;
  for (i = 0; i < V; i++)
    adj[i][i] = 1;
  while (scanf("%d %d\n", &i, &j) == 2)
    adj[i][j] = 1;

  printf("Adjacency matrix:\n");
  print_2D_matrix(V, V, adj);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.71_E03.69.exe
0 2
1 4
2 5
3 6
0 4
6 0
1 3
^Z
Adjacency matrix:
         0   1   2   3   4   5   6   7   8   9
      -----------------------------------------
   0 |   1   0   1   0   1   0   0   0   0   0
   1 |   0   1   0   1   1   0   0   0   0   0
   2 |   0   0   1   0   0   1   0   0   0   0
   3 |   0   0   0   1   0   0   1   0   0   0
   4 |   0   0   0   0   1   0   0   0   0   0
   5 |   0   0   0   0   0   1   0   0   0   0
   6 |   1   0   0   0   0   0   1   0   0   0
   7 |   0   0   0   0   0   0   0   1   0   0
   8 |   0   0   0   0   0   0   0   0   1   0
   9 |   0   0   0   0   0   0   0   0   0   1

The graph is as follows:
 2 <-- 0 ----> 4
 |     ^        ^
 |     |         \
 v     |          \
 5     6 <-- 3 <-- 1
--------------------------------------------------------------------- */

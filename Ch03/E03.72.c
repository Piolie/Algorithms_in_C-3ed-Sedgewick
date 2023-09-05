/* ---------------------------------------------------------------------
                             EXERCISE 3.72
------------------------------------------------------------------------
Modify Program 3.18 to take the number of vertices as a command-line
argument, then dynamically allocate the adjacency matrix.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
In this simple program, it would be better to simply allocate a VLA.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  int V = atoi(argv[1]);
  int(*adj)[V] = malloc(sizeof(int[V][V]));

  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      adj[i][j] = 0;
  for (i = 0; i < V; i++)
    adj[i][i] = 1;
  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[i][j] = 1;
    adj[j][i] = 1;
  }
}

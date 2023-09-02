/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 3.18
                      Sorting an array of strings
------------------------------------------------------------------------
This program reads a set of edges that define an undirected graph and
builds an adjacency-matrix representation for the graph, setting a[i][j]
and a[j][i] to 1 if there is an edge from i to j or j to i in the graph,
or to 0 if there is no such edge. The program assumes that the number of
vertices V is a compile-time constant. Otherwise, it would need to
dynamically allocate the array that represents the adjacency matrix (see
Exercise 3.72).
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int i, j, adj[V][V];
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      adj[i][j] = 0;
  for (i = 0; i < V; i++)
    adj[i][i] = 1;
  while (scanf("%d%d\n", &i, &j) == 2) {
    adj[i][j] = 1;
    adj[j][i] = 1;
  }
}

/* ---------------------------------------------------------------------
                             EXERCISE 3.74
------------------------------------------------------------------------
Write a function that uses the adjacency matrix of a graph to calculate,
given vertices a and b, the number of vertices c with the property that
there is an edge from a to c and from c to b.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
We have to search the respective rows (or columns) of a and b for common
elements. It could be argued that if a and b are connected, then there
are at least two nodes that connect to both a and b (a and b
themselves). I won't count those.

I'll be using the sequence of nodes that generates the graph in
figure 3.15, to make it easier to visually verify the result.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int count_common_nodes(int node_a, int node_b, int V, int matrix[V][V]) {
  int count = 0;
  for (int i = 0; i < V; i++)
    if (matrix[node_a][i] && matrix[node_b][i])
      if (node_a != i && node_b != i)
        count++;

  return count;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int node_a = atoi(argv[1]);
  int node_b = atoi(argv[2]);
  int V = atoi(argv[3]);

  int i, j, adj[V][V];
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      adj[i][j] = 0;
  for (i = 0; i < V; i++)
    adj[i][i] = 1;
  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[i][j] = 1;
    adj[j][i] = 1;
  }
  printf("Nodes a and b: %d, %d\n", node_a, node_b);
  printf("There are %d nodes that connect to both a and b.",
         count_common_nodes(node_a, node_b, V, adj));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.74.exe 0 7 8
0 6
0 1
0 2
3 4
4 7
3 5
4 5
0 5
0 7
2 7
1 7
4 6
^Z
^Z
Nodes a and b: 0, 7
There are 2 nodes that connect to both a and b.

./E03.74.exe 0 4 8
0 6
0 1
0 2
3 4
4 7
3 5
4 5
0 5
0 7
2 7
1 7
4 6
^Z
^Z
Nodes a and b: 0, 4
There are 3 nodes that connect to both a and b.

./E03.74.exe 4 7 8
0 6
0 1
0 2
3 4
4 7
3 5
4 5
0 5
0 7
2 7
1 7
4 6
^Z
^Z
Nodes a and b: 4, 7
There are 0 nodes that connect to both a and b.
--------------------------------------------------------------------- */

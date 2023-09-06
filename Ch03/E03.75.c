/* ---------------------------------------------------------------------
                             EXERCISE 3.75
------------------------------------------------------------------------
Answer Exercise 3.74, but use adjacency lists.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
We have to search the respective lists of a and b for common elements.
It could be argued that if a and b are connected, then there are at
least two nodes that connect to both a and b (a and b themselves). I
won't count those.

I'll be using the sequence of nodes that generates the graph in
figure 3.15, to make it easier to visually verify the result.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
  int v;
  link next;
};

link NEW(int v, link next) {
  link x = malloc(sizeof *x);
  x->v = v;
  x->next = next;
  return x;
}

int count_common_nodes(int node_a, int node_b, link *adj) {
  int count = 0;
  for (link ta = adj[node_a]; ta; ta = ta->next)
    for (link tb = adj[node_b]; tb; tb = tb->next)
      if (ta->v == tb->v)
        if (ta->v != node_b && tb->v != node_a)
          count++;

  return count;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int node_a = atoi(argv[1]);
  int node_b = atoi(argv[2]);
  int V = atoi(argv[3]);

  int i, j;
  link *adj = malloc(V * sizeof(*adj));
  for (i = 0; i < V; i++)
    adj[i] = NULL;
  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[j] = NEW(i, adj[j]);
    adj[i] = NEW(j, adj[i]);
  }
  printf("Nodes a and b: %d, %d\n", node_a, node_b);
  printf("There are %d nodes that connect to both a and b.",
         count_common_nodes(node_a, node_b, adj));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.75.exe 0 7 8
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

E03.75.exe 0 4 8
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

E03.75.exe 4 7 8
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

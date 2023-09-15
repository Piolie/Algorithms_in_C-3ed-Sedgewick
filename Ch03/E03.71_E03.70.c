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
Retake of E03.70.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define V 10

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

void print_2D_multilist(int idx, link multi[]) {
  const int digits = 4;

  printf("index %d: ", idx);
  for (link t = multi[idx]; t; t = t->next)
    printf("%*d -> ", digits, t->v);
  printf("*\n");
}

int main(void) {
  int i, j;
  link adj[V];
  for (i = 0; i < V; i++)
    adj[i] = NULL;
  while (scanf("%d %d\n", &i, &j) == 2)
    adj[i] = NEW(j, adj[i]);

  printf("Adjacency list:\n");
  for (i = 0; i < V; i++)
    print_2D_multilist(i, adj);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.71_E03.70.exe
0 2
1 4
2 5
3 6
0 4
6 0
1 3
^Z
Adjacency list:
index 0:    4 ->    2 -> *
index 1:    3 ->    4 -> *
index 2:    5 -> *
index 3:    6 -> *
index 4: *
index 5: *
index 6:    0 -> *
index 7: *
index 8: *
index 9: *

The graph is as follows:
 2 <-- 0 ----> 4
 |     ^        ^
 |     |         \
 v     |          \
 5     6 <-- 3 <-- 1
--------------------------------------------------------------------- */

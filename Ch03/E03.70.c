/* ---------------------------------------------------------------------
                             EXERCISE 3.70
------------------------------------------------------------------------
Show the adjacency lists that are built by Program 3.19 given the input
pairs 0-2, 1-4, 2-5, 3-6, 0-4, 6-0, and 1-3.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'm adapting print_2D_multilist from E03.67.
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
  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[j] = NEW(i, adj[j]);
    adj[i] = NEW(j, adj[i]);
  }

  printf("Adjacency list:\n");
  for (i = 0; i < V; i++)
    print_2D_multilist(i, adj);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.70.exe
0 2
1 4
2 5
3 6
0 4
6 0
1 3
^Z
Adjacency list:
index 0:    6 ->    4 ->    2 -> *
index 1:    3 ->    4 -> *
index 2:    5 ->    0 -> *
index 3:    1 ->    6 -> *
index 4:    0 ->    1 -> *
index 5:    2 -> *
index 6:    0 ->    3 -> *
index 7: *
index 8: *
index 9: *

With the following run we can reproduce figure 3.15:
E03.70.exe
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
Adjacency list:
index 0:    7 ->    5 ->    2 ->    1 ->    6 -> *
index 1:    7 ->    0 -> *
index 2:    7 ->    0 -> *
index 3:    5 ->    4 -> *
index 4:    6 ->    5 ->    7 ->    3 -> *
index 5:    0 ->    4 ->    3 -> *
index 6:    4 ->    0 -> *
index 7:    1 ->    2 ->    0 ->    4 -> *
index 8: *
index 9: *
--------------------------------------------------------------------- */

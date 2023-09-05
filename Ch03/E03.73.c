/* ---------------------------------------------------------------------
                             EXERCISE 3.73
------------------------------------------------------------------------
Modify Program 3.19 to take the number of vertices as a command-line
argument, then dynamically allocate the array of lists.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
In this simple program, it would be better to simply allocate a VLA.
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

int main(int argc, char *argv[]) {
  (void)argc;
  int V = atoi(argv[1]);
  link *adj = malloc(V * sizeof(*adj));

  int i, j;
  for (i = 0; i < V; i++)
    adj[i] = NULL;
  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[j] = NEW(i, adj[j]);
    adj[i] = NEW(j, adj[i]);
  }
}

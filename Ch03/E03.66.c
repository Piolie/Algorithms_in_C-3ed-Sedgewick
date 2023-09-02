/* ---------------------------------------------------------------------
                             EXERCISE 3.66
------------------------------------------------------------------------
Use Program 3.20 in conjunction with Program 1.4 to develop an efficient
program that can determine whether a set of N points can be connected
with edges of length less than d.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The only way I could think of making this work without changing things
too much was by adding a node_id field to the node struct, to allow us
to identify each individual node. That way, program 1.4 handles the
connections, while program 3.20 deals with the insertions in the grid
and the calculations of the distances.

P01.4 is split into the init_arrays() and connect_nodes() functions,
while P03.20 into the init_grid() and stuff_floats(). The latter calls
gridinsert(), which was lightly modified to set the node_id and call
connect_nodes() (instead of incrementing cnt).

Apart from that, I fixed the bug in randFloat() that is mentioned in
P03.20 and added the logic to verify that all nodes are connected.
--------------------------------------------------------------------- */

#include "Point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
  point p;
  int node_id;
  link next;
};

int *id, *sz;
link **grid;
int N, G;
float d;

void init_arrays(void) {
  for (int i = 0; i < N; i++) {
    id[i] = i;
    sz[i] = 1;
  }
}

void connect_nodes(int p, int q) {
  int i, j;
  for (i = p; i != id[i]; i = id[i]) {
    int t = i;
    i = id[id[t]];
    id[t] = i;
  }
  for (j = q; j != id[j]; j = id[j]) {
    int t = j;
    j = id[id[t]];
    id[t] = j;
  }
  if (i == j)
    return;
  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
}

link **malloc2d(int r, int c) {
  int i;
  link **t = malloc(r * sizeof(link *));
  for (i = 0; i < r; i++)
    t[i] = malloc(c * sizeof(link));
  return t;
}

void init_grid(void) {
  grid = malloc2d(G + 2, G + 2);
  for (int i = 0; i < G + 2; i++)
    for (int j = 0; j < G + 2; j++)
      grid[i][j] = NULL;
}

void gridinsert(float x, float y, int node_id) {
  int X = x * G + 1;
  int Y = y * G + 1;
  link t = malloc(sizeof *t);
  t->p.x = x;
  t->p.y = y;
  t->node_id = node_id;

  for (int i = X - 1; i <= X + 1; i++)
    for (int j = Y - 1; j <= Y + 1; j++)
      for (link s = grid[i][j]; s != NULL; s = s->next)
        if (distance(s->p, t->p) < d)
          connect_nodes(s->node_id, t->node_id);

  t->next = grid[X][Y];
  grid[X][Y] = t;
}

float randFloat(void) { return 1.0 * rand() / (RAND_MAX + 1); }

void stuff_floats(void) {
  for (int i = 0; i < N; i++)
    gridinsert(randFloat(), randFloat(), i);
}

float distance(point a, point b) {
  float dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

int main(int argc, char *argv[]) {
  (void)argc;
  N = atoi(argv[1]);
  d = atof(argv[2]);
  G = 1 / d;

  id = malloc(N * sizeof(*id));
  sz = malloc(N * sizeof(*sz));

  init_arrays();
  init_grid();
  stuff_floats();

  int val = id[0];
  int can_connect = 1;
  for (int i = 1; i < N; i++)
    if (val != id[i]) {
      can_connect = 0;
      break;
    }

  printf("Can connect this set of %d points with edges less "
         "than %.3f? %s",
         N, d, can_connect ? "YES!" : "NO!");
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.66.exe 1000 1
Can connect this set of 1000 points with edges less than 1.000? YES!

E03.66.exe 1000 0.1
Can connect this set of 1000 points with edges less than 0.100? YES!

E03.66.exe 1000 0.01
Can connect this set of 1000 points with edges less than 0.010? NO!

E03.66.exe 10000 0.01
Can connect this set of 10000 points with edges less than 0.010? NO!

E03.66.exe 100000 0.01
Can connect this set of 100000 points with edges less than 0.010? YES!

E03.66.exe 100000 0.001
Can connect this set of 100000 points with edges less than 0.001? NO!

E03.66.exe 1000000 0.001
Can connect this set of 1000000 points with edges less than 0.001? NO!

E03.66.exe 10000000 0.001
Can connect this set of 10000000 points with edges less than 0.001? YES!
--------------------------------------------------------------------- */

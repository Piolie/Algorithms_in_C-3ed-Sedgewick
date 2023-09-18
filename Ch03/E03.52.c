/* ---------------------------------------------------------------------
                             EXERCISE 3.52
------------------------------------------------------------------------
Implement the interface in Program 3.12 using array indices (and no head
node) rather than pointers, in such a way that Figure 3.11 is a trace of
the operation of your program.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Notes:
  - "Your program" is Program 3.13. This is stated in p. 103:
      We consider one implementation for the operations defined in
      Program 3.12 in Section 3.5 (see Program 3.14), but we could
      also try other alternatives without changing Program 3.13 at all
      (see Exercise 3.52).
  - Implementing the same interface using no pointers is somewhat
    artificial because list.h has pointers everywhere. I'll use an array
    of int to keep track of the next node, use the `item` fields and
    ignore the `next` fields.
  - The original implementation uses a head node, so I'll have to
    ignore the part that asks not to use a head node. Using only a "head
    pointer" makes it cumbersome to insert/delete nodes at the beginning
    of a list, since the interface only provides insertNext and
    deleteNext (not Before).
  - The program trace can be shown by uncommenting the line #define
    TRACE. I created some auxiliary functions to print it.
  - For reference, check exercise 3.33. Figure 3.11 is also included
    below.
------------------------------------------------------------------------
Figure 3.11
Array representation of a linked list, with free list

This version of Figure 3.6 shows the result of maintaining a free list
with the nodes deleted from the circular list, with the index of first
node on the free list given at the left. At the end of the process, the
free list is a linked list containing all the items that were deleted.
Following the links, starting at 1, we see the items in the order 2 9 6
3 4 7 1 5, which is the reverse of the order in which they were deleted.

          0   1   2   3   4   5   6   7   8
        -------------------------------------
  item  | 1   2   3   4   5   6   7   8   9
  next  | 1   2   3   4   5   6   7   8   0

          1   2   3   4   5   6   7   8   9
  4       1   2   3   5   -   6   7   8   0

          1   2   3   4   5   6   7   8   9
  0       4   2   3   5   -   6   7   8   1

          1   2   3   4   5   6   7   8   9
  6       4   2   3   5   -   7   0   8   1

          1   2   3   4   5   6   7   8   9
  3       4   2   5   6   -   7   0   8   1

          1   2   3   4   5   6   7   8   9
  2       4   5   3   6   -   7   0   8   1

          1   2   3   4   5   6   7   8   9
  5       4   7   3   6   -   2   0   8   1

          1   2   3   4   5   6   7   8   9
  8       4   7   3   6   -   2   0   1   5

          1   2   3   4   5   6   7   8   9
  1       4   8   3   6   -   2   0   7   5
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// #define TRACE

link nodes;
int *next;
int total_nodes;

void print_array(int *arr) {
  for (int i = 0; i <= total_nodes; i++)
    printf(" %2d", arr[i]);
  printf("\n");
}

void print_state(void) {
  printf("nodes[] = ");
  for (int i = 0; i <= total_nodes; i++)
    printf(" %2d", nodes[i].item);
  printf("\n");

  printf("next[]  = ");
  print_array(next);
  printf("---\n");
}

static int index(link x) {
  for (int i = 0; i < total_nodes + 1; i++)
    if (x == &nodes[i])
      return i;
  return -1;
}

void initNodes(int N) {
  total_nodes = N;
  nodes = calloc((N + 1), sizeof(*nodes));
  nodes[0].item = 0;
  next = malloc((N + 1) * sizeof(*next));

  for (int i = 0; i < N + 1; i++)
    next[i] = i + 1;
  next[N] = N;
}

link newNode(int i) {
  link x = deleteNext(&nodes[0]);
  int x_index = index(x);

  x->item = i;
  next[x_index] = x_index;
  return x;
}

void freeNode(link x) {
  insertNext(nodes, x);
#ifdef TRACE
  printf("first free: %d\n", next[0] - 1);
  printf("deleted: %d\n", index(x));
  print_state();
#endif
}

void insertNext(link x, link t) {
  int x_index = index(x);
  int t_index = index(t);
  next[t_index] = next[x_index];
  next[x_index] = t_index;
}

link deleteNext(link x) {
  int x_index = index(x);
  int t_index = next[x_index];
  next[x_index] = next[t_index];
  return &nodes[t_index];
}

link Next(link x) { return &nodes[next[index(x)]]; }

int Item(link x) { return nodes[index(x)].item; }

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
#define TRACE

./E03.52.exe 9 5
first free: 4
deleted: 5
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   5  2  3  4  6  9  7  8  9  1
---
first free: 0
deleted: 1
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   1  5  3  4  6  9  7  8  9  2
---
first free: 6
deleted: 7
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   7  5  3  4  6  9  8  1  9  2
---
first free: 3
deleted: 4
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   4  5  3  6  7  9  8  1  9  2
---
first free: 2
deleted: 3
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   3  5  6  4  7  9  8  1  9  2
---
first free: 5
deleted: 6
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   6  5  8  4  7  9  3  1  9  2
---
first free: 8
deleted: 9
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   9  5  8  4  7  9  3  1  2  6
---
first free: 1
deleted: 2
nodes[] =   0  1  2  3  4  5  6  7  8  9
next[]  =   2  5  9  4  7  9  3  1  8  6
---
8
--------------------------------------------------------------------- */

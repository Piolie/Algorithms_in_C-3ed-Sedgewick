/* ---------------------------------------------------------------------
                             EXERCISE 3.54
------------------------------------------------------------------------
Under the conditions of Exercise 3.53, write a code fragment that, given
a pointer to a node, finds the number of different nodes that it
ultimately reaches by following links from that node, without modifying
any nodes. Do not use more than a constant amount of extra memory space.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I assume that the exercise wants us to find the length of the cycle we
end up in.

We have to follow the links until we are inside the cycle, and then
count. The second part is easy. Figuring out when we have entered the
cycle requires some ingenuity. Fortunately, this problem has already
been solved. See:
- [Cycle detection](https://en.wikipedia.org/wiki/Cycle_detection)
- [How does finding a cycle start node in a cycle linked list
work?](https://stackoverflow.com/questions/2936213/)

I'll be copying Floyd's cycle-finding algorithm (also known as Floyd's
tortoise and hare) implementation from the wikipedia, adapting it to C.
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

link f(link x) { return x->next; }

int main(int argc, char *argv[]) {
  int N = atoi(argv[1]);
  int loop_start = 2 * N / 3; // starting node for the cycle
  link x0 = malloc(N * sizeof(*x0));
  for (int i = 0; i < N - 1; i++)
    x0[i].next = &x0[i + 1];
  x0[N - 1].next = &x0[loop_start];

  link tortoise = f(x0);
  link hare = f(f(x0));

  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(f(hare));
  }

  int mu = 0;
  tortoise = x0;
  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(hare);
    mu += 1;
  }

  int lam = 1;
  hare = f(tortoise);
  while (tortoise != hare) {
    hare = f(hare);
    lam += 1;
  }

  printf("The cycle starts at node %d and has length %d.\n", mu, lam);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.54.exe N
The cycle starts at node 2*N/3 and has length N/3.
--------------------------------------------------------------------- */

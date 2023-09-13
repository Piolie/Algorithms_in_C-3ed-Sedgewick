/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.11
                    FIFO queue array implementation
------------------------------------------------------------------------
The contents of the queue are all the elements in the array between head
and tail, taking into account the wraparound back to 0 when the end of
the array is encountered. If head and tail are equal, then we consider
the queue to be empty; but if put would make them equal, then we
consider it to be full. As usual, we do not check such error conditions,
but we make the size of the array 1 greater than the maximum number
of elements that the client expects to see in the queue, so that we
could augment this program to make such checks.
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdlib.h>

static Item *q;
static int N, head, tail;
void QUEUEinit(int maxN) {
  q = malloc((maxN + 1) * sizeof(Item));
  N = maxN + 1;
  head = N;
  tail = 0;
}
int QUEUEempty(void) { return head % N == tail; }
void QUEUEput(Item item) {
  q[tail++] = item;
  tail = tail % N;
}
Item QUEUEget(void) {
  head = head % N;
  return q[head++];
}

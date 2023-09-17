/* ---------------------------------------------------------------------
                             EXERCISE 4.42
------------------------------------------------------------------------
Build a random-queue ADT by writing an interface and an implementation
that uses an array as the underlying data structure. Make sure that each
operation takes constant time.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
From the book:
  A simple but powerful alternative is the random queue, where the rule
  is to "remove a random item," and the client can expect to get any of
  the items on the queue with equal probability. We can implement the
  operations of a random queue in constant time using an array
  representation (see Exercise 4.42).

The 4th edition of the book gives a hint to implement it:
  Use an array representation (with resizing). To remove an item, swap
  one at a random position (indexed 0 through N-1) with the one at the
  last position (index N-1). Then delete and return the last object.

The following is a modification of P04.11 to accommodate this behavior.
I'll be reusing the interface from QUEUE.h (P04.09), since a new ADT
would only change the names of the functions.
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdlib.h>

static Item *q;
static int N, head, tail, count;

void QUEUEinit(int maxN) {
  q = malloc((maxN + 1) * sizeof(Item));
  N = maxN + 1;
  head = N;
  tail = 0;
  count = 0;
}

int QUEUEempty(void) { return head % N == tail; }

void QUEUEput(Item item) {
  q[tail++] = item;
  tail = tail % N;
  count++;
}

void swap(void) {
  int ihead = head % N;
  int irand = (rand() % count + head) % N;
  Item tmp = q[ihead];
  q[ihead] = q[irand];
  q[irand] = tmp;
}

Item QUEUEget(void) {
  swap();
  head = head % N;
  count--;
  return q[head++];
}

/* ---------------------------------------------------------------------
                             EXERCISE 4.32
------------------------------------------------------------------------
Modify the array-based FIFO queue implementation in the text
(Program 4.11) to call a function QUEUEerror if the client attempts to
get when the queue is empty or to put when the queue is full.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This exercise is analogous to E04.20. I've followed similar strategies.
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

int QUEUEfull(void) { return tail + 1 == head; }

void QUEUEput(Item item) {
  if (QUEUEfull())
    QUEUEerror();
  else {
    q[tail++] = item;
    tail = tail % N;
  }
}

Item QUEUEget(void) {
  if (QUEUEempty()) {
    QUEUEerror();
    return q[0];
  }
  head = head % N;
  return q[head++];
}

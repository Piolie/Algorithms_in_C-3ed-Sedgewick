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

/* ---------------------------------------------------------------------
Notice that even without implementing the error-condition checks
mentioned above, the logic of the program already requires q to allocate
(maxN + 1) elements, because it needs to index q from 0 to maxN.

Refer to the figure below for an example. If we initialize with maxN = 3
and push 3 ints (0, 1 and 2), the queue is filled and tail "points" to
q[3]. If we now get one item, head wraps around and then increments,
pointing to q[1]. Putting 3 now sets q[3] to 3 and makes tail wrap
around to 0. The queue is full again, since tail + 1 == heads, but we
have written to q[maxN]. Following with a series of 3 gets, the queue is
emptied, which means we read from q[3]. Head and tail end at the same
values we started with.

      q[0]  q[1]  q[2]  q[3]  maxN = 3; N = 4
                                       head = 4; tail = 0
0       0                              head = 4; tail = 1
1       0     1                        head = 4; tail = 2
2       0     1     2                  head = 4; tail = 3
*   0         1     2                  head = 1; tail = 3
3             1     2     3            head = 1; tail = 0
*   1               2     3            head = 2; tail = 0
*   2                     3            head = 3; tail = 0
*   3                                  head = 4; tail = 0

Conclusion: as it is now, we cannot simply do
  q = malloc(maxN * sizeof(Item));
and expect our program to work, even if the client keeps track of the
state of the queue.

Notice also that, as correctly coded in QUEUEempty and in contrast with
what the exercise states, the queue is empty not when head == tail, but
when head % N == tail.
--------------------------------------------------------------------- */

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

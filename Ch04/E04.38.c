/* ---------------------------------------------------------------------
                             EXERCISE 4.38
------------------------------------------------------------------------
Provide an implementation for your deque interface (Exercise 4.37) that
uses an array for the underlying data structure.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Whenever we access the array, we have to constraint the index to
[0, maxN]. DQput_end and DQget_beg are exactly the same as QUEUEput and
QUEUEget, respectively. For the other two functions, the slightly more
abstruse expression X = (X - 1 + N) % N is used, where X is head or
tail, depending on the function.

[Is there an expression using modulo to do backwards wrap-around ("reverse
overflow")?](https://stackoverflow.com/questions/14785443/)
--------------------------------------------------------------------- */

#include "DEQUE.h"
#include <stdio.h>
#include <stdlib.h>

static Item *q;
static int N, head, tail;

void DQinit(int maxN) {
  q = malloc((maxN + 1) * sizeof(Item));
  N = maxN + 1;
  head = N;
  tail = 0;
}

int DQempty(void) { return head % N == tail; }
int DQfull(void) { return tail + 1 == head; }

void DQput_beg(Item item) {
  head = (head - 1 + N) % N;
  q[head] = item;
}

void DQput_end(Item item) { // QUEUEput-like
  q[tail++] = item;
  tail = tail % N;
}

Item DQget_beg(void) { // QUEUEget-like
  head = head % N;
  return q[head++];
}

Item DQget_end(void) {
  tail = (tail - 1 + N) % N;
  return q[tail];
}

void DQdump(void) {
  for (int i = head % N; i != tail; i = (i + 1) % N) {
    ITEMshow(q[i]);
    printf(" ");
  }
  printf("\n");
}

void DQprettydump(void) {
  const int digits = 10;
  printf("q[i] = [");
  for (int i = 0; i < N; i++)
    printf(" %*d,", digits, q[i]);
  printf("]");
  printf("\n");
  for (int i = 0; i < N + 1; i++) {
    if (head == i) {
      printf("%*s", 8 + digits, "");
      printf("%*s", (digits + 2) * i, "");
      printf("^head = %d\n", head);
    }
    if (tail == i) {
      printf("%*s", 8 + digits, "");
      printf("%*s", (digits + 2) * i, "");
      printf("^tail = %d\n", tail);
    }
  }
}

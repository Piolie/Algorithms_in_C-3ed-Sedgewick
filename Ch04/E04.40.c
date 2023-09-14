/* ---------------------------------------------------------------------
                             EXERCISE 4.40
------------------------------------------------------------------------
Provide an implementation for the FIFO queue interface in the text
(Program 4.9) that uses a circular list for the underlying data
structure.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'll allocate a circular list of fixed size on QUEUEinit, and then only
traverse and modify the value of each node, never touching the links.

I've found this implementation to be the easiest to understand of all
for a FIFO.
--------------------------------------------------------------------- */

#include "QUEUE.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUEnode *link;
struct QUEUEnode {
  Item item;
  link next;
};

static link head, tail;

link NEW(Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

void QUEUEinit(int maxN) {
  head = malloc(sizeof *head);
  head->next = head;
  head->item = 0;

  link x;
  for (int i = 0; i < maxN; i++) {
    x = NEW(0, head->next);
    head->next = x;
  }
  tail = head;
}

int QUEUEempty(void) { return head == tail; }
int QUEUEfull(void) { return tail->next == head; }

void QUEUEput(Item item) {
  tail->item = item;
  tail = tail->next;
}

Item QUEUEget(void) {
  Item item = head->item;
  head = head->next;
  return item;
}

void DQdump(void) {
  const int digits = 10;
  link t = head;

  printf("q[i] = [");
  do {
    printf(" %*d,", digits, t->item);
    t = t->next;
  } while (t != head);
  printf("]\n");

  printf("%*s", 8 + digits, "");
  printf("^head = 0\n");

  printf("%*s", 8 + digits, "");
  int i = 0;
  for (t = head; t != tail; t = t->next) {
    printf("%*s", (digits + 2), "");
    i++;
  }
  printf("^tail = %d\n", i);
}

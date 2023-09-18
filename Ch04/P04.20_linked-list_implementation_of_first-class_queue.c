/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.20
            Linked-list implementation of first-class queue
------------------------------------------------------------------------
The code for implementations that provide object handles is typically
more cumbersome than the corresponding code for single objects (see
Program 4.10). This code does not check for errors such as a client
attempt to get from an empty queue or an unsuccessful malloc (see
Exercise 4.33).
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdlib.h>

typedef struct QUEUEnode *link;
struct QUEUEnode {
  Item item;
  link next;
};

struct queue {
  link head;
  link tail;
};

link NEW(Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

Q QUEUEinit(int maxN) {
  (void)maxN;
  Q q = malloc(sizeof *q);
  q->head = NULL;
  q->tail = NULL;
  return q;
}

int QUEUEempty(Q q) { return q->head == NULL; }

void QUEUEput(Q q, Item item) {
  if (q->head == NULL) {
    q->tail = NEW(item, q->head);
    q->head = q->tail;
    return;
  }
  q->tail->next = NEW(item, q->tail->next);
  q->tail = q->tail->next;
}

Item QUEUEget(Q q) {
  Item item = q->head->item;
  link t = q->head->next;
  free(q->head);
  q->head = t;
  return item;
}

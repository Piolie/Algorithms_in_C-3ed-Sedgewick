/* ---------------------------------------------------------------------
                             EXERCISE 4.33
------------------------------------------------------------------------
Modify the linked-list-based FIFO queue implementation in the text
(Program 4.10) to call a function QUEUEerror if the client attempts to
get when the queue is empty or if there is no memory available from
malloc for a put.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This exercise is analogous to E04.21. I've followed similar strategies.
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdlib.h>

typedef struct QUEUEnode *link;
struct QUEUEnode {
  Item item;
  link next;
};

static link head, tail;

link NEW(Item item, link next) {
  link x = malloc(sizeof *x);
  if (x) {
    x->item = item;
    x->next = next;
  }
  return x;
}

void QUEUEinit(int maxN) { head = NULL; }

int QUEUEempty() { return head == NULL; }

void QUEUEput(Item item) {
  if (head == NULL) {
    head = (tail = NEW(item, head));
    if (!head)
      QUEUEerror();
    return;
  }
  tail->next = NEW(item, tail->next);
  if (!tail->next)
    QUEUEerror();
  return;
  tail = tail->next;
}

Item QUEUEget() {
  if (QUEUEempty()) {
    QUEUEerror();
    return NULL;
  }
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}

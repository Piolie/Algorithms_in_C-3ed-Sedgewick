/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.10
                 FIFO queue linked-list implementation
------------------------------------------------------------------------
The difference between a FIFO queue and a pushdown stack (Program 4.5)
is that new items are inserted at the end, rather than the beginning.
Accordingly, this program keeps a pointer tail to the last node of
the list, so that the function QUEUEput can add a new node by linking
that node to the node referenced by tail and then updating tail to point
to the new node. The functions QUEUEget, QUEUEinit, and QUEUEempty are
all identical to their counterparts for the linked-list pushdown-stack
implementation of Program 4.5.
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
  x->item = item;
  x->next = next;
  return x;
}
void QUEUEinit(int maxN) { head = NULL; }
int QUEUEempty(void) { return head == NULL; }
void QUEUEput(Item item) {
  if (head == NULL) {
    head = (tail = NEW(item, head));
    return;
  }
  tail->next = NEW(item, tail->next);
  tail = tail->next;
}
Item QUEUEget(void) {
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}

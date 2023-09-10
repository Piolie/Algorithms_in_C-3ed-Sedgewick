/* ---------------------------------------------------------------------
                             EXERCISE 4.23
------------------------------------------------------------------------
Write a linked-list-based pushdown-stack implementation that keeps items
on the list in order from least recently inserted to most recently
inserted. You will need to use a doubly linked list.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Keeping the required order using a doubly linked is somewhat artificial
if we use a tail pointer, since even though the order is as required, we
never access the list from head to tail. We could also use a singly
linked list and pop to/push from the end. The logic to handle it is a
bit more involved and less performant (we have to traverse the whole
list for each push/pop), but it works the same nonetheless.

Just like P04.05, we don't handle the popping from an empty stack.
--------------------------------------------------------------------- */

#include "Item.h"
#include "STACK.h"
#include <stdlib.h>

typedef struct STACKnode *link;
struct STACKnode {
  Item item;
  link next;
  link prev;
};

static link head;
static link tail;

link NEW(Item item, link prev) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = NULL;
  x->prev = prev;
  return x;
}

void STACKinit(int maxN) {
  (void)maxN;
  head = NULL;
  tail = NULL;
}

int STACKempty() { return head == NULL; }

void STACKpush(Item item) {
  if (tail) {
    tail->next = NEW(item, tail);
    tail = tail->next;
  } else {
    tail = NEW(item, tail);
    head = tail;
  }
}

Item STACKpop() {
  Item item = tail->item;
  link t = tail->prev;
  free(tail);
  tail = t;
  return item;
}

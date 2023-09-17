/* ---------------------------------------------------------------------
                             EXERCISE 4.43
------------------------------------------------------------------------
Build a random-queue ADT by writing an interface and an implementation
that uses a linked list as the underlying data structure. Provide
implementations for insert and delete that are as efficient as you can
make them, and analyze their worst-case cost.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
From the book:
  A simple but powerful alternative is the random queue, where the rule
  is to "remove a random item," and the client can expect to get any of
  the items on the queue with equal probability. We can implement the
  operations of a random queue in constant time using an array
  representation (see Exercise 4.42).

The following is a modification of P04.10 to accommodate this behavior.
I'll be reusing the interface from P04.09.

In the worst case, the implementation has to traverse the whole list to
swap the last node with the first. In the average case, half the nodes
have to be traversed.
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
static int count;

link NEW(Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}
void QUEUEinit(int maxN) {
  (void)maxN;
  head = NULL;
  count = 0;
}

int QUEUEempty(void) { return head == NULL; }

void QUEUEput(Item item) {
  count++;
  if (head == NULL) {
    head = (tail = NEW(item, head));
    return;
  }
  tail->next = NEW(item, tail->next);
  tail = tail->next;
}

void swap(void) {
  int irand = rand() % count;
  link t = head;
  for (int i = 0; i < irand; i++)
    t = t->next;

  Item tmp = head->item;
  head->item = t->item;
  t->item = tmp;
}

Item QUEUEget(void) {
  swap();
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  count--;
  return item;
}

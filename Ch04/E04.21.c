/* ---------------------------------------------------------------------
                             EXERCISE 4.21
------------------------------------------------------------------------
Modify the linked-list-based pushdown-stack implementation in the text
(Program 4.5) to call a function STACKerror if the client attempts to
pop when the stack is empty or if there is no memory available from
malloc for a push.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
STACKerror is supposed to be defined somewhere else.

The exercise does not specify what the return value of STACKpop should
be in case of an empty stack. I've chosen NULL, which may or may not
work, depending on the concrete type of Item.
--------------------------------------------------------------------- */

#include "Item.h"
#include "STACK.h"
#include <stdlib.h>

typedef struct STACKnode *link;
struct STACKnode {
  Item item;
  link next;
};
static link head;

link NEW(Item item, link next) {
  link x = malloc(sizeof *x);
  if (x) {
    x->item = item;
    x->next = next;
  }
  return x;
}

void STACKinit(int maxN) {
  (void)maxN;
  head = NULL;
}

int STACKempty(void) { return head == NULL; }

void STACKpush(Item item) {
  head = NEW(item, head);
  if (!head)
    STACKerror();
}

Item STACKpop(void) {
  if (!head) {
    STACKerror();
    return NULL;
  }
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}

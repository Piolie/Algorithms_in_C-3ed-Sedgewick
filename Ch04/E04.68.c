/* ---------------------------------------------------------------------
                             EXERCISE 4.68
------------------------------------------------------------------------
Develop an implementation of your first-class pushdown-stack ADT from
Exercise 4.66 that uses a linked list as the underlying data structure.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Adapted from P04.05 (Linked-list implementation of a pushdown stack) and
P04.20 (Linked-list implementation of first-class queue).

I won't write a client program to test this. P04.02 (Postfix-expression
evaluation) and P04.03 (Infix-to-postfix conversion) could be adapted to
make use of the first-class ADT.
--------------------------------------------------------------------- */

#include "Item.h"
#include "STACK.h"
#include <stdlib.h>

typedef struct STACKnode *link;
struct STACKnode {
  Item item;
  link next;
};
struct stack {
  link head;
};

link NEW(Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

Stack STACKinit(int maxN) {
  (void)maxN;
  Stack stack = malloc(sizeof(*stack));
  stack->head = NULL;
  return stack;
}

int STACKempty(Stack stack) { return stack->head == NULL; }

void STACKpush(Stack stack, Item item) { stack->head = NEW(item, stack->head); }

Item STACKpop(Stack stack) {
  Item item = stack->head->item;
  link t = stack->head->next;
  free(stack->head);
  stack->head = t;
  return item;
}

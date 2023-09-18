/* ---------------------------------------------------------------------
                             EXERCISE 4.67
------------------------------------------------------------------------
Develop an implementation of your first-class pushdown-stack ADT
from Exercise 4.66 that uses an array as the underlying data structure.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Adapted from P04.04 (Array implementation of a pushdown stack) and
P04.20 (Linked-list implementation of first-class queue).

I won't write a client program to test this. P04.02 (Postfix-expression
evaluation) and P04.03 (Infix-to-postfix conversion) could be adapted to
make use of the first-class ADT.
--------------------------------------------------------------------- */

#include "Item.h"
#include "STACK.h"
#include <stdio.h>
#include <stdlib.h>

struct stack {
  Item *s;
  int N;
};

void STACKdump(Stack stack) {
  for (int i = 0; i < stack->N; i++) {
    ITEMshow(stack->s[i]);
    printf(" ");
  }
  printf("\n");
}

Stack STACKinit(int maxN) {
  Stack stack = malloc(sizeof(*stack));
  stack->s = malloc(maxN * sizeof(Item));
  stack->N = 0;
  return stack;
}

int STACKempty(Stack stack) { return stack->N == 0; }

void STACKpush(Stack stack, Item item) { stack->s[stack->N++] = item; }

Item STACKpop(Stack stack) { return stack->s[--stack->N]; }

/* ---------------------------------------------------------------------
                             EXERCISE 4.20
------------------------------------------------------------------------
Modify the array-based pushdown-stack implementation in the text
(Program 4.4) to call a function STACKerror if the client attempts to
pop when the stack is empty or to push when the stack is full.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I've added a STACKfull function and a global variable max to keep track
of the maximum array size used for initialization. STACKerror is
supposed to be defined somewhere else.

The exercise does not specify what the return value of STACKpop should
be in case of an empty stack. I've chosen the last valid element.
--------------------------------------------------------------------- */

#include "Item.h"
#include "STACK.h"
#include <stdlib.h>

static Item *s;
static int N;
static int max;

void STACKinit(int maxN) {
  max = maxN;
  s = malloc(maxN * sizeof(Item));
  N = 0;
}

int STACKempty(void) { return N == 0; }

int STACKfull(void) { return N == max; }

void STACKpush(Item item) {
  if (STACKfull())
    STACKerror();
  else
    s[N++] = item;
}

Item STACKpop() {
  if (STACKempty()) {
    STACKerror();
    return s[N];
  }
  return s[--N];
}

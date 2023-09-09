/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.4
                Array implementation of a pushdown stack
------------------------------------------------------------------------
When there are N items in the stack, this implementation keeps them in
s[0], ..., s[N-1]; in order from least recently inserted to most
recently inserted. The top of the stack (the position where the next
item to be pushed will go) is s[N]. The client program passes the
maximum number of items expected on the stack as the argument to
STACKinit, which allocates an array of that size, but this code does not
check for errors such as pushing onto a full stack (or popping an empty
one).
--------------------------------------------------------------------- */

#include "Item.h"
// #include "Item_char.h"
// #include "Item_float.h"
// #include "Item_int.h"
// #include "Item_string.h"
#include "STACK.h"
#include <stdlib.h>

static Item *s;
static int N;
void STACKinit(int maxN) {
  s = malloc(maxN * sizeof(Item));
  N = 0;
}
int STACKempty() { return N == 0; }
void STACKpush(Item item) { s[N++] = item; }
Item STACKpop() { return s[--N]; }

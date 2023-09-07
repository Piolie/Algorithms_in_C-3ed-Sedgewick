/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.5
             Linked-list implementation of a pushdown stack
------------------------------------------------------------------------
This code implements the stack ADT as illustrated in Figure 4.5. It uses
an auxiliary function NEW to allocate the memory for a node, set its
fields from the function arguments, and return a link to the node.
--------------------------------------------------------------------- */

#include "Item.h"
// #include "Item_char.h"
// #include "Item_int.h"
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
  x->item = item;
  x->next = next;
  return x;
}
void STACKinit(int maxN) {
  (void)maxN;
  head = NULL;
}
int STACKempty() { return head == NULL; }
void STACKpush(Item item) { head = NEW(item, head); }
Item STACKpop() {
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}

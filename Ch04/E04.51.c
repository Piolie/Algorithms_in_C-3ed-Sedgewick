/* ---------------------------------------------------------------------
                             EXERCISE 4.51
------------------------------------------------------------------------
Develop a pushdown-stack implementation that disallows duplicates, using
a forget-the-old-item policy for integer items between 0 and M - 1, and
that uses constant time for both push and pop. Hint: Use a doubly linked
list representation for the stack and keep pointers to nodes, rather
than 0-1 values, in an item-indexed array.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'll be combining my work from E04.23:
  Write a linked-list-based pushdown-stack implementation that keeps
  items on the list in order from least recently inserted to most
  recently inserted. You will need to use a doubly linked list.
with P04.12. The forget-the-old-item policy is implemented with a
function that moves the new node to the top.
--------------------------------------------------------------------- */

// #define DEBUG_E04_51

#include "STACK.h"
#include <stdlib.h>

typedef struct STACKnode *link;
struct STACKnode {
  Item item;
  link prev;
  link next;
};

static link head, tail;
static link *p_array;

link NEW(Item item, link prev) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = NULL;
  x->prev = prev;
  return x;
}

void STACKinit(int maxN) {
  p_array = malloc(maxN * sizeof(*p_array));
  for (int i = 0; i < maxN; i++)
    p_array[i] = NULL;
  head = NULL;
  tail = NULL;
}

int STACKempty() { return head == NULL; }

void STACKmove_to_top(link t) {
  if (t->next) {
    t->next->prev = t->prev;
  } else { // t is already the tail node, do nothing
    return;
  }
  if (t->prev) {
    t->prev->next = t->next;
  } else {          // t is the head node
    head = t->next; // dereference allowed by first if
    head->prev = NULL;
  }
  t->prev = tail;
  t->next = NULL;
  tail->next = t;
  tail = t;
}

void STACKpush(Item item) {
  if (p_array[item]) {
    STACKmove_to_top(p_array[item]);
    return;
  }

  if (tail) {
    tail->next = NEW(item, tail);
    tail = tail->next;
  } else { // empty stack
    tail = NEW(item, NULL);
    head = tail;
  }

  p_array[item] = tail;
}

Item STACKpop() {
  Item item = tail->item;
  link t = tail->prev;
  free(tail);
  if (t)
    t->next = NULL;
  else // this pop empties the stack
    head = NULL;
  tail = t;

  p_array[item] = NULL;

  return item;
}

#ifdef DEBUG_E04_51
#include <stdio.h>

void STACKdump(void) {
  for (link t = head; t; t = t->next) {
    ITEMshow(t->item);
    printf(" ");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[2];
  STACKinit(atoi(argv[1]));
  for (char c = *a; c; c = *++a) {
    if (c >= 'A' && c <= 'Z') {
      printf("%c       ", c);
      STACKpush(c);
      STACKdump();
    } else if (c == '*') {
      printf("*   %c", STACKpop());
      printf("   ");
      STACKdump();
    }
  }
}
#endif // #ifdef DEBUG_E04_51

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing E04.49 (E04.47):
./E04.51.exe 100 "L A * S T I * N * F I R * S T * * * O U * T * * *"
L       L
A       L A
*   A   L
S       L S
T       L S T
I       L S T I
*   I   L S T
N       L S T N
*   N   L S T
F       L S T F
I       L S T F I
R       L S T F I R
*   R   L S T F I
S       L T F I S
T       L F I S T
*   T   L F I S
*   S   L F I
*   I   L F
O       L F O
U       L F O U
*   U   L F O
T       L F O T
*   T   L F O
*   O   L F
*   F   L
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 4.54
------------------------------------------------------------------------
Do Exercise 4.51 for the FIFO queue ADT.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
We have to:
Develop a FIFO queue implementation that disallows duplicates, using a
forget-the-old-item policy for integer items between 0 and M - 1, and
that uses constant time for both push and pop. Hint: Use a doubly linked
list representation for the queue and keep pointers to nodes, rather
than 0-1 values, in an item-indexed array.

I'll be combining my work from E04.39:
  Provide an implementation for your deque interface (Exercise 4.37)
  that uses a doubly linked list for the underlying data structure.
with that of E04.51. The forget-the-old-item policy is implemented with
exactly the same function, just renamed.
--------------------------------------------------------------------- */

// #define DEBUG_E04_54

#include "QUEUE.h"
#include <stdlib.h>

typedef struct QUEUEnode *link;
struct QUEUEnode {
  Item item;
  link prev;
  link next;
};

static link head, tail;
static link *p_array;

link NEW(Item item, link prev, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->prev = prev;
  x->next = next;
  return x;
}

void QUEUEinit(int maxN) {
  p_array = malloc(maxN * sizeof(*p_array));
  for (int i = 0; i < maxN; i++)
    p_array[i] = NULL;
  head = NULL;
  tail = NULL;
}

int QUEUEempty(void) { return head == NULL; }

int QUEUEfull(void) { return 0; }

void QUEUEmove_to_end(link t) {
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

void QUEUEput(Item item) {
  if (p_array[item]) {
    QUEUEmove_to_end(p_array[item]);
    return;
  }

  if (tail) {
    tail->next = NEW(item, tail, NULL);
    tail = tail->next;
  } else {
    tail = NEW(item, NULL, NULL);
    head = tail;
  }

  p_array[item] = tail;
}

Item QUEUEget(void) {
  Item item = head->item;
  link t = head->next;
  free(head);
  if (t)
    t->prev = NULL;
  else // this get empties the deque
    tail = NULL;
  head = t;

  p_array[item] = NULL;

  return item;
}

#ifdef DEBUG_E04_54
#include <stdio.h>

void QUEUEdump(void) {
  for (link t = head; t; t = t->next) {
    ITEMshow(t->item);
    printf(" ");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[2];
  QUEUEinit(atoi(argv[1]));
  for (char c = *a; c; c = *++a) {
    if (c >= 'A' && c <= 'Z') {
      printf("%c       ", c);
      QUEUEput(c);
      QUEUEdump();
    } else if (c == '*') {
      printf("*   %c", QUEUEget());
      printf("   ");
      QUEUEdump();
    }
  }
}
#endif // #ifdef DEBUG_E04_54

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing figure 4.11:
./E04.54.exe 100 "F I R S * T * I N * * * F I * R S * * * T * O U T * * *"
F       F
I       F I
R       F I R
S       F I R S
*   F   I R S
T       I R S T
*   I   R S T
I       R S T I
N       R S T I N
*   R   S T I N
*   S   T I N
*   T   I N
F       I N F
I       N F I
*   N   F I
R       F I R
S       F I R S
*   F   I R S
*   I   R S
*   R   S
T       S T
*   S   T
O       T O
U       T O U
T       O U T
*   O   U T
*   U   T
*   T
--------------------------------------------------------------------- */

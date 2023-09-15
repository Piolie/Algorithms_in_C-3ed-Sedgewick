/* ---------------------------------------------------------------------
                             EXERCISE 4.39
------------------------------------------------------------------------
Provide an implementation for your deque interface (Exercise 4.37) that
uses a doubly linked list for the underlying data structure.
--------------------------------------------------------------------- */

#include "DEQUE.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct DEQUEnode *link;
struct DEQUEnode {
  Item item;
  link prev;
  link next;
};
static link head, tail;

link NEW(Item item, link prev, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->prev = prev;
  x->next = next;
  return x;
}

void DQinit(int maxN) {
  (void)maxN;
  head = NULL;
  tail = NULL;
}

int DQempty(void) { return head == NULL; }

int DQfull(void) { return 0; }

void DQput_beg(Item item) {
  if (head) {
    head->prev = NEW(item, NULL, head);
    head = head->prev;
    return;
  }
  head = NEW(item, NULL, NULL);
  tail = head;
}

void DQput_end(Item item) {
  if (tail) {
    tail->next = NEW(item, tail, NULL);
    tail = tail->next;
    return;
  }
  tail = NEW(item, NULL, NULL);
  head = tail;
}

Item DQget_beg(void) {
  Item item = head->item;
  link t = head->next;
  free(head);
  if (t)
    t->prev = NULL;
  else // this get empties the deque
    tail = NULL;
  head = t;
  return item;
}

Item DQget_end(void) {
  Item item = tail->item;
  link t = tail->prev;
  free(tail);
  if (t)
    t->next = NULL;
  else // this get empties the deque
    head = NULL;
  tail = t;
  return item;
}

void DQdump(void) {
  for (link t = head; t; t = t->next) {
    ITEMshow(t->item);
    printf(" ");
  }
  printf("\n");
}

void DQprettydump(void) {
  const int digits = 10;
  printf("q[i] = [");
  for (link t = head; t; t = t->next)
    printf(" %*d,", digits, t->item);
  printf("]");
  printf("\n");
}

/* ---------------------------------------------------------------------
                             EXERCISE 4.53
------------------------------------------------------------------------
Do Exercise 4.50 for the FIFO queue ADT.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
E04.50:
  Do Exercises 4.48 and 4.49 for the linked-list-based stack
  implementation in Section 4.4 (Program 4.5).
E04.49:
  Modify the standard array-based stack implementation in Section 4.4
  (Program 4.4) to disallow duplicates with a forget-the-old-item
  policy. Use a brute-force approach that involves scanning through, and
  possibly rearranging, the whole stack.
Thus, this exercise asks to:
Modify the standard linked-list-based FIFO queue implementation in
Section 4.4 (Program 4.10) to disallow duplicates with an forget-the-
old-item policy. Use a brute-force approach that involves scanning
through, and possibly rearranging, the whole queue.

Analogously to the first part of this exercise, I'm just copying some lines from
STACKpush to QUEUEput and adapting one function (STACKmove_to_top to
QUEUEmove_to_end) from E04.50_E04.49.
--------------------------------------------------------------------- */

#define DEBUG_E04_53_E04_49

#include "QUEUE.h"
#include <stdlib.h>

typedef struct QUEUEnode *link;
struct QUEUEnode {
  Item item;
  link next;
};

static link head, tail;

link NEW(Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

void QUEUEinit(int maxN) {
  (void)maxN;
  head = NULL;
}

int QUEUEempty(void) { return head == NULL; }

void QUEUEmove_to_end(link t_prev, link t) {
  if (!t_prev) { // t is head
    head = t->next;
  } else {
    t_prev->next = t->next;
  }
  t->next = NULL;
  tail->next = t;
  tail = t;
}

void QUEUEput(Item item) {
  link t_prev = NULL;
  for (link t = head; t; t = t->next) {
    if (eq(t->item, item)) {
      QUEUEmove_to_end(t_prev, t);
      return;
    }
    t_prev = t;
  }

  if (head == NULL) {
    head = (tail = NEW(item, head));
    return;
  }
  tail->next = NEW(item, tail->next);
  tail = tail->next;
}

Item QUEUEget(void) {
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}

#ifdef DEBUG_E04_53_E04_49
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
#endif // #ifdef DEBUG_E04_53_E04_49

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing figure 4.11 and E04.52_E04.49:
E04.53_E04.49.exe 10 "F I R S * T * I N * * * F I * R S * * * T * O U T * * *"
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

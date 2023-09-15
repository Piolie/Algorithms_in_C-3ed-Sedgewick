/* ---------------------------------------------------------------------
                             EXERCISE 4.50
------------------------------------------------------------------------
Do Exercises 4.48 and 4.49 for the linked-list-based stack
implementation in Section 4.4 (Program 4.5).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This exercise is then:
Modify the standard linked-list-based stack implementation in
Section 4.4 (Program 4.5) to disallow duplicates with a forget-the-old-
item policy. Use a brute-force approach that involves scanning through,
and possibly rearranging, the whole stack.

The output differs from the one in E04.49 only in that the order of the
stack is reversed. Printing it in the correct order takes more work,
because the underlying data structure is a singly linked list, which
makes it harder to traverse in the reverse order.

I've implemented a private function called STACKmove_to_top, to avoid
deleting and reinserting a new repeated node. Depending on the
application, a delete and insert operation might be more appropriate.
I've used that approach in E04.52_E04.49.
--------------------------------------------------------------------- */

// #define DEBUG_E04_50_E04_49

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

int STACKempty(void) { return head == NULL; }

void STACKmove_to_top(link t_prev, link t) {
  if (t_prev) {
    t_prev->next = t->next;
    t->next = head;
    head = t;
  }
}

void STACKpush(Item item) {
  link t_prev = NULL;
  for (link t = head; t; t = t->next) {
    if (eq(t->item, item)) {
      STACKmove_to_top(t_prev, t);
      return;
    }
    t_prev = t;
  }
  head = NEW(item, head);
}

Item STACKpop(void) {
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}

#ifdef DEBUG_E04_50_E04_49
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
#endif // #ifdef DEBUG_E04_50_E04_49

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing E04.47:
E04.50_E04.49.exe 50 "L A * S T I * N * F I R * S T * * * O U * T * * *"
L       L
A       A L
*   A   L
S       S L
T       T S L
I       I T S L
*   I   T S L
N       N T S L
*   N   T S L
F       F T S L
I       I F T S L
R       R I F T S L
*   R   I F T S L
S       S I F T L
T       T S I F L
*   T   S I F L
*   S   I F L
*   I   F L
O       O F L
U       U O F L
*   U   O F L
T       T O F L
*   T   O F L
*   O   F L
*   F   L
--------------------------------------------------------------------- */

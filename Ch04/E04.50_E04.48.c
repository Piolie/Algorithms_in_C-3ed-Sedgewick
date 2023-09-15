/* ---------------------------------------------------------------------
                             EXERCISE 4.50
------------------------------------------------------------------------
Do Exercises 4.48 and 4.49 for the linked-list-based stack
implementation in Section 4.4 (Program 4.5).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This exercise is then:
Modify the standard linked-list-based stack implementation in
Section 4.4 (Program 4.5) to disallow duplicates with an ignore-the-new-
item policy. Use a brute-force approach that involves scanning through
the whole stack.

The output differs from the one in E04.48 only in that the order of the
stack is reversed. Printing it in the correct order takes more work,
because the underlying data structure is a singly linked list, which
makes it harder to traverse in the reverse order.
--------------------------------------------------------------------- */

// #define DEBUG_E04_50_E04_48

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

void STACKpush(Item item) {
  for (link t = head; t; t = t->next)
    if (eq(t->item, item))
      return;
  head = NEW(item, head);
}

Item STACKpop(void) {
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}

#ifdef DEBUG_E04_50_E04_48
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
#endif // #ifdef DEBUG_E04_50_E04_48

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing figure 4.9:
./E04.50_E04.48.exe 10 "L A * S T I * N * F I R * S T * * * O U * T * * *"
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
S       I F T S L
T       I F T S L
*   I   F T S L
*   F   T S L
*   T   S L
O       O S L
U       U O S L
*   U   O S L
T       T O S L
*   T   O S L
*   O   S L
*   S   L
--------------------------------------------------------------------- */

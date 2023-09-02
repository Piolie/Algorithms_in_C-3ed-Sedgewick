/* ---------------------------------------------------------------------
                             EXERCISE 3.41
------------------------------------------------------------------------
Implement a version of Program 3.10 that uses a head node.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I think the book has a little inconsistency in its implementation of
dummy head nodes. Notice that program 3.11, which declares to be using
"head nodes", allocates them  in the stack:
  struct node heada, headb;

However, Table 3.1 states that in the case of dummy head nodes, these
should be allocated in the heap using malloc:
  head = malloc(sizeof *head);
  head->next = NULL;

It's no big deal to account for the differences. Just keep them in mind.

------------------------------------------------------------------------
I'll assume that the link x parameter points to a dummy head node, so no
need to check for x == NULL. The reverse reuses the head node, so it has
no need to return anything.
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100

void reverse(link x) {
  link t, y = x->next, r = NULL;
  while (y != NULL) {
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  x->next = r; // make head node's next point to new first node
}

int main(void) {
  int i;
  link head = malloc(sizeof *head);
  head->next = NULL;
  link t;

  printf("Unsorted nodes:\n");
  for (i = 0, t = head; i < N; i++) {
    t->next = malloc(sizeof *t);
    t = t->next;
    t->next = NULL;
    t->item = rand() % 1000;
    printf("%3d ", t->item);
  }

  reverse(head);

  printf("\n\nReversed list:\n");
  for (t = head->next; t != NULL; t = t->next)
    printf("%3d ", t->item);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Unsorted nodes:
 41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942
827 436 391 604 902 153 292 382 421 716 718 895 447 726 771 538 869 912
667 299  35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757
 37 859 723 741 529 778 316  35 190 842 288 106  40 942 264 648 446 805
890 729 370 350   6 101 393 548 629 623  84 954 756 840 966 376 931 308
944 439 626 323 537 538 118  82 929 541

Reversed list:
541 929  82 118 538 537 323 626 439 944 308 931 376 966 840 756 954  84
623 629 548 393 101   6 350 370 729 890 805 446 648 264 942  40 106 288
842 190  35 316 778 529 741 723 859  37 757 662 644 547 868 253 711 141
664 673 333 322 811 703 894  35 299 667 912 869 538 771 726 447 895 718
716 421 382 292 153 902 604 391 436 827 942 995 491 961 827 281 145 705
464 962 358 478 724 169 500 334 467  41
--------------------------------------------------------------------- */

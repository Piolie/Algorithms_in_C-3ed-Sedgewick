/* ---------------------------------------------------------------------
                             EXERCISE 3.42
------------------------------------------------------------------------
Implement a version of Program 3.11 that does not use head nodes.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Corner cases:
  - empty list (== null head);
  - insert at the beginning;
  - insert at the end.
------------------------------------------------------------------------
Figure 3.8 Linked-list sort
This diagram depicts one step in transforming an unordered linked list
(pointed to by a) into an ordered one (pointed to by b), using insertion
sort. We take the first node of the unordered list, keeping a pointer to
it in t (top). Then, we search through b to find the first node x with
x->next->item > t->item (or x->next == NULL), and insert t into the list
following x (center). These operations reduce the length of a by one
node, and increase the length of b by one node, keeping b in order
(bottom). Iterating, we eventually exhaust a and have the nodes in order
in b.
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100

link insertion_sort(link heada) {
  if (!heada) // if the list is empty there is nothing to do
    return heada;

  link headb = heada, a, next_a, b, prev_b;

  for (a = heada; a != NULL; a = next_a) {
    next_a = a->next;
    prev_b = headb;
    for (b = headb; b != NULL; prev_b = b, b = b->next)
      if (b->item > a->item)
        break;

    if (b == headb) // insert node at the beginning
      headb = a;
    else
      prev_b->next = a;

    if (!b) // insert node at the end
      a->next = NULL;
    else
      a->next = b;
  }
  return headb;
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

  head = head->next; // skip dummy head node

  link new_head = insertion_sort(head);

  printf("\n\nSorted nodes:\n");
  for (t = new_head; t != NULL; t = t->next)
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

Sorted nodes:
  6  35  35  37  40  41  82  84 101 106 118 141 145 153 169 190 253 264
281 288 292 299 308 316 322 323 333 334 350 358 370 376 382 391 393 421
436 439 446 447 464 467 478 491 500 529 537 538 538 541 547 548 604 623
626 629 644 648 662 664 667 673 703 705 711 716 718 723 724 726 729 741
756 757 771 778 805 811 827 827 840 842 859 868 869 890 894 895 902 912
929 931 942 942 944 954 961 962 966 995
--------------------------------------------------------------------- */

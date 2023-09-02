/* ---------------------------------------------------------------------
                             EXERCISE 3.34
------------------------------------------------------------------------
Write a function that moves the largest item on a given list to be the
final node on the list.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
My solution finds and keeps references to the node with the largest item
("max node") as well as its previous node. Once all the list has been
traversed, it simply skips the max node and appends it to the end of the
list.

The function follows the "Dummy head node, null tail" convention. There
are some corner cases that it needs to consider:
  - null head;
  - empty list;
  - first node is the largest;
  - last node is the largest;

For the first two cases there is an if guard that checks both head and
head->next for nullness. In either case it returns doing nothing.

In the third case, the if statements inside the for loop are never
executed, but since we correctly initialized x, t, prev_node and
max_node, the rest of the function works OK.

The last case is handled by checking whether the max node is already the
last. If that's the case then the function returns doing nothing.
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100

void largest_to_last(link head) {
  if (!head || !(head->next))
    return;

  link x = head, t = head->next;
  link prev_node = x, max_node = t;

  // find largest item; keep reference to that node and the previous
  // one (at the end of this loop x points to the last node)
  for (int max = t->item; t != NULL; x = t, t = t->next) {
    if (t->item > max) {
      max = t->item;
      prev_node = x;
      max_node = t;
    }
  }

  // if x == max_node then the max node is already at the end
  if (x == max_node)
    return;

  // skip max node
  prev_node->next = max_node->next;

  // set max node link to null and append max node to the end of the list
  max_node->next = NULL;
  x->next = max_node;
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

  largest_to_last(head);

  printf("\n\nLargest to last:\n");
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

Largest to last:
 41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 942 827
436 391 604 902 153 292 382 421 716 718 895 447 726 771 538 869 912 667
299  35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757  37
859 723 741 529 778 316  35 190 842 288 106  40 942 264 648 446 805 890
729 370 350   6 101 393 548 629 623  84 954 756 840 966 376 931 308 944
439 626 323 537 538 118  82 929 541 995
--------------------------------------------------------------------- */

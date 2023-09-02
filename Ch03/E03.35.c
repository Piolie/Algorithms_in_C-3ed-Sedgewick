/* ---------------------------------------------------------------------
                             EXERCISE 3.35
------------------------------------------------------------------------
Write a function that moves the smallest item on a given list to be the
first node on the list.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
My solution finds and keeps references to the node with the smallest
item ("min node") as well as its previous node. Once all the list has
been traversed, it simply skips the min node and appends it to the
beginning of the list.

The function follows the "Dummy head node, null tail" convention. There
are some corner cases that it needs to consider:
  - null head;
  - empty list;
  - first node is the smallest;

For the first two cases there is an if guard that checks both head and
head->next for nullness. In either case it returns doing nothing.

The last case is handled by checking whether the min node is already the
first. If that's the case then the function returns doing nothing.
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100

void smallest_to_first(link head) {
  if (!head || !(head->next))
    return;

  link x = head, t = head->next;
  link prev_node_ptr = x, min_node_ptr = t;

  // find smallest item; keep reference to that node and the previous one
  for (int min = t->item; t != NULL; x = t, t = t->next) {
    if (t->item < min) {
      min = t->item;
      prev_node_ptr = x;
      min_node_ptr = t;
    }
  }

  // if head->next == min_node_ptr then the min node is already at the beginning
  if (head->next == min_node_ptr)
    return;

  // skip min node
  prev_node_ptr->next = min_node_ptr->next;

  // set min node link to head->next and append min node to the beginning of the
  // list
  min_node_ptr->next = head->next;
  head->next = min_node_ptr;
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

  smallest_to_first(head);

  printf("\n\nSmallest to first:\n");
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

Smallest to first:
  6  41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995
942 827 436 391 604 902 153 292 382 421 716 718 895 447 726 771 538 869
912 667 299  35 894 703 811 322 333 673 664 141 711 253 868 547 644 662
757  37 859 723 741 529 778 316  35 190 842 288 106  40 942 264 648 446
805 890 729 370 350 101 393 548 629 623  84 954 756 840 966 376 931 308
944 439 626 323 537 538 118  82 929 541
--------------------------------------------------------------------- */

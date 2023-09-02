/* ---------------------------------------------------------------------
                             EXERCISE 3.36
------------------------------------------------------------------------
Write a function that rearranges a linked list to put the nodes in even
positions after the nodes in odd positions in the list, preserving the
relative order of both the evens and the odds.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
One way of solving this is to make two separate lists (even and odd) and
alternatively add the nodes of the given list to each of these other
two. Then, we simply concatenate the lists and we are done.

This solution works in-place. Each node is linked to the one after the
next and references are kept to the first even and last odd. In the end,
we assign head to the first odd, link the last odd to the first even and
are done:

  head >>> 0 >>> 1 >>> 2 >>> 3 >>> 4 >>> 5

    >>>>>>>>>>>>>>>>   >>>>>>>>>  NULL
   /                \ /         \ /
  0   head >>> 1     2     3     4     5
   \            \         / \         / \
    \            >>>>>>>>>   >>>>>>>>>  |
     \                                  /
      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

The devil, as usual, is in the details. The function has to first check
that the dummy head is not null and that the list has at least two
elements. After that, it's important to know when to stop. There are two
different cases, depending on weather the list has an odd or even number
of nodes.

Note: some variables are really not needed but I added them to make
following the code easier. For example, last_odd is redundant, we could
simply use odd at the end of the function. Also, the first else could
just be a break.
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100

void rearrange_list_odd_even(link head) {
  if (!head || !(head->next) || !(head->next->next))
    return;

  link first_even = head->next;
  link first_odd = head->next->next;
  link last_odd = first_odd;
  link even = first_even;
  link odd = first_odd;

  for (;; odd = odd->next, even = even->next)
    if (odd->next) {
      even->next = odd->next;
      if (odd->next->next)
        odd->next = odd->next->next;
      else // odd number of nodes
      {
        odd->next = NULL;
        last_odd = odd;
        break;
      }
    } else // even number of nodes
    {
      even->next = NULL;
      last_odd = odd;
      break;
    }

  head->next = first_odd;
  last_odd->next = first_even;
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

  rearrange_list_odd_even(head);

  printf("\n\nEvens after odds:\n");
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

Evens after odds:
467 500 724 358 464 145 827 491 942 436 604 153 382 716 895 726 538 912
299 894 811 333 664 711 868 644 757 859 741 778  35 842 106 942 648 805
729 350 101 548 623 954 840 376 308 439 323 538  82 541  41 334 169 478
962 705 281 961 995 827 391 902 292 421 718 447 771 869 667  35 703 322
673 141 253 547 662  37 723 529 316 190 288  40 264 446 890 370   6 393
629  84 756 966 931 944 626 537 118 929
--------------------------------------------------------------------- */

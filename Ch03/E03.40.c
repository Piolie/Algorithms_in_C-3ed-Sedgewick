/* ---------------------------------------------------------------------
                             EXERCISE 3.40
------------------------------------------------------------------------
Solve Exercise 3.39, but make copies of the nodes that pass the test and
return a link to a list containing those nodes, in the order that they
appear in the original list.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
What does "pass the test" mean? Did we remove nodes that passed or that
failed the test in exercise 3.39?

I'll assume that we have to leave the given list unmodified and generate
a new list with copies of the nodes nodes for which aux_func is true.
--------------------------------------------------------------------- */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100

link prune_list(link head, int (*aux_func)(link)) {
  link t, return_head = malloc(sizeof *return_head);

  t = return_head;
  while (head->next) {
    head = head->next;
    if (aux_func(head)) {
      t->next = malloc(sizeof *t);
      t = t->next;
      t->item = head->item;
    }
  }
  t->next = NULL;
  return return_head;
}

int aux_func(link l) { return l->item >= 500; }

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

  link new_head = prune_list(head, aux_func);

  printf("\n\nRemoved nodes:\n");
  for (t = new_head->next; t != NULL; t = t->next)
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

Removed nodes:
            500     724         962     705         827 961     995 942
827         604 902                 716 718 895     726 771 538 869 912
667         894 703 811         673 664     711     868 547 644 662 757
    859 723 741 529 778             842             942     648     805
890 729                     548 629 623     954 756 840 966     931
944     626     537 538         929 541
--------------------------------------------------------------------- */

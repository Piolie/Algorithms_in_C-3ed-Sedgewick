/* ---------------------------------------------------------------------
                             EXERCISE 3.39
------------------------------------------------------------------------
Write a function that takes two arguments—a link to a list and a
function that takes a link as argument—and removes all items on the
given list for which the function returns a nonzero value.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I used an auxiliary function that checks whether the item is >= 500.
prune_list removes all such nodes.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define N 100

void prune_list(link head, int (*aux_func)(link))
{
    while (head->next)
    {
        if (aux_func(head->next))
        {
            link temp = head->next;
            head->next = head->next->next;
            free(temp);
        }
        else
            head = head->next;
    }
}

int aux_func(link l)
{
    return l->item >= 500;
}

int main(void)
{
    int i;
    link head = malloc(sizeof *head);
    head->next = NULL;
    link t;

    printf("Unsorted nodes:\n");
    for (i = 0, t = head; i < N; i++)
    {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 1000;
        printf("%3d ", t->item);
    }

    prune_list(head, aux_func);

    printf("\n\nPruned list:\n");
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

Pruned list:
 41 467 334     169     478 358     464     145 281         491
    436 391         153 292 382 421             447
    299  35             322 333         141     253
 37                     316  35 190     288 106  40     264     446
        370 350   6 101 393              84                 376     308
    439     323         118  82

--------------------------------------------------------------------- */

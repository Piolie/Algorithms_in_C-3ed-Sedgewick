/* ---------------------------------------------------------------------
                             EXERCISE 3.38
------------------------------------------------------------------------
Write a function that takes a link to a list as argument and returns a
link to a copy of the list (a new list that contains the same items, in
the same order).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
As an added difficulty, I decided to code some error handling in the
function, specially to avoid memory leaks. Haven't tested it much
though.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define N 100

link copy_list(link head)
{
    if (!head)
        goto error;

    link temp, return_head = malloc(sizeof *return_head);

    if (!return_head)
        goto error;

    temp = return_head;
    while (head->next)
    {
        temp->next = malloc(sizeof *temp);
        temp = temp->next;
        if (!temp)
            goto error;

        head = head->next;
        temp->item = head->item;
    }
    temp->next = NULL;
    return return_head;

error:  // free all the previously allocated nodes and return NULL
    temp = return_head;
    while (temp)
    {
        temp = return_head->next;
        free(return_head);
        return_head = temp;
    }
    return NULL;
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

    link new_head = copy_list(head);

    // modify the first node in each list
    new_head->next->item = -10;
    head->next->item = 0;

    printf("\n\nCopied list:\n");
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

Copied list:
-10 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942
827 436 391 604 902 153 292 382 421 716 718 895 447 726 771 538 869 912
667 299  35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757
 37 859 723 741 529 778 316  35 190 842 288 106  40 942 264 648 446 805
890 729 370 350   6 101 393 548 629 623  84 954 756 840 966 376 931 308
944 439 626 323 537 538 118  82 929 541

--------------------------------------------------------------------- */

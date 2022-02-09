/* ---------------------------------------------------------------------
                             EXERCISE 3.44
------------------------------------------------------------------------
Implement a function that exchanges two given nodes on a doubly linked
list.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I can't #include "list.h" because it does not include doubly linked
nodes. I'll define such a structure below.

Just like in exercise 3.37, we could just exchange the values of the
respective nodes. In this case, I'll try a different approach than the
one used in that exercise. This time, I'll use delete and insert
operations to exchange de nodes.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
// #include "list.h"

#define N 100

typedef int itemType;
typedef struct double_node* link;
struct double_node {
    itemType item;
    link prev;
    link next;
};

void remove_node(link node)
{
    if (!node)
        return;

    if (node->prev)
        node->prev->next = node->next;
    else
        return;
    if (node->next)
        node->next->prev = node->prev;

    return;
}

void insert_after(link prev, link node)
{
    if (!prev || !node)
        return;

    link next = prev->next;
    prev->next = node;
    node->prev = prev;
    node->next = next;
    if (next)
        next->prev = node;

    return;
}

void exchange(link t, link u)
{
    // is either pointer null?
    if (!t || !u)
        return;

    // do t and u point to the same node?
    if (t == u)
        return;

    link u_prev = u->prev;

    if (u_prev == t)  // t->next == u
    {
        remove_node(t);
        insert_after(u, t);
        return;
    }

    remove_node(u);
    insert_after(t, u);
    remove_node(t);
    insert_after(u_prev, t);
}

int main(void)
{
    int i;
    link head = malloc(sizeof *head);
    head->prev = NULL;
    head->next = NULL;
    link t, t_prev;

    printf("Unsorted nodes:\n");
    for (i = 0, t = head; i < N; i++)
    {
        t_prev = t;
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->prev = t_prev;
        t->item = rand() % 1000;
        printf("%3d ", t->item);
    }

    exchange(head->next, head->next->next);
    exchange(head->next->next->next, head->next->next);

    printf("\n\nExchanged nodes:\n");
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

Exchanged nodes:
467 334  41 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942
827 436 391 604 902 153 292 382 421 716 718 895 447 726 771 538 869 912
667 299  35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757
 37 859 723 741 529 778 316  35 190 842 288 106  40 942 264 648 446 805
890 729 370 350   6 101 393 548 629 623  84 954 756 840 966 376 931 308
944 439 626 323 537 538 118  82 929 541

--------------------------------------------------------------------- */

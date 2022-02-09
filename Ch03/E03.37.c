/* ---------------------------------------------------------------------
                             EXERCISE 3.37
------------------------------------------------------------------------
Implement a code fragment for a linked list that exchanges the positions
of the nodes after the nodes referenced by two given links t and u.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I can think of two ways of solving the problem.

The first and easy one is to just exchange the item from each node. The
function would just do:
    int temp = t->item;
    t->item = u->item;
    u->item = temp;

The second really exchanges the nodes, by manipulating the next field
of t, u, t->next and u->next. That's what I'm implementing below.

The following diagram illustrates the state of the list after each
statement, supposing t is node 0 and u is node 4:

>>> t >>> t_next >>> 2 >>> 3 >>> u >>> u_next >>> 6 >>>

temp = t->next;
>>> t >>> t_next >>> 2 >>> 3 >>> u >>> u_next >>> 6 >>>
            /
    temp >>>

t->next = u->next;
        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
       /                               \
      /                                 \
     /                                   \
>>> t     t_next >>> 2 >>> 3 >>> u >>> u_next >>> 6 >>>
            /
    temp >>>

u->next = temp;
        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
       /                               \
      /       <<<<<<<<<<<<<<<<<<        \
     /       /                  \        \
>>> t     t_next >>> 2 >>> 3 >>> u     u_next >>> 6 >>>
            /
    temp >>>

temp = t->next->next;
        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
       /                               \
      /       <<<<<<<<<<<<<<<<<<        \           <<< temp
     /       /                  \        \         /
>>> t     t_next >>> 2 >>> 3 >>> u     u_next >>> 6 >>>

t->next->next = u->next->next;
        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
       /                               \
      /       <<<<<<<<<<<<<<<<<<        \           <<< temp
     /       /                  \        \         /
>>> t     t_next >>> 2 >>> 3 >>> u     u_next     6 >>>
                      \                  /
                       <<<<<<<<<<<<<<<<<<

u->next->next = temp;
        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
       /                               \
      /       <<<<<<<<<<<<<<<<<<        \           <<< temp
     /       /                  \        \         /
>>> t     t_next     2 >>> 3 >>> u     u_next     6 >>>
             \        \                  /       /
              \        <<<<<<<<<<<<<<<<<<       /
               \                               /
                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

------------------------------------------------------------------------
This works even if t and u are consecutive nodes (meaning t->next == u
or u->next == t):

>>> t >>> t_next >>> 2 >>> 3 >>> u >>> u_next >>> 6 >>>

temp = t->next;
>>> t >>> t_next >>> 2 >>> 3 >>> u >>> u_next >>> 6 >>>
            /
    temp >>>

t->next = u->next;
        >>>>>>>>
       /        \
      /          \
     /            \
>>> t     u >>> u_next >>> 6 >>>
         /
 temp >>>

u->next = temp;
        >>>>>>>>
       /        \
      /  >>>     \
     /   \ /      \
>>> t     u     u_next >>> 6 >>>
         /
 temp >>>

temp = t->next->next;
        >>>>>>>>
       /        \
      /  >>>     \           <<< temp
     /   \ /      \         /
>>> t     u     u_next >>> 6 >>>

t->next->next = u->next->next;
        >>>>>>>>
       /        \
      /  >>>     \           <<< temp
     /   \ /      \         /
>>> t     u     u_next     6 >>>
           \      /
            <<<<<<

u->next->next = temp;
        >>>>>>>>
       /        \
      /          \           <<< temp
     /            \         /
>>> t     u     u_next     6 >>>
         / \      /       /
        /   <<<<<<       /
       /                /
       >>>>>>>>>>>>>>>>>

Also, there is no special case if t is head or u->next is the last node.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define N 100

void exchange(link t, link u)
{
    // is either pointer null or is there no next for any node?
    if (!t || !u || !(t->next) || !(u->next))
        return;

    // do t and u point to the same node?
    if (t == u)
        return;

    link temp;  // auxiliary pointer

    temp = t->next;
    t->next = u->next;
    u->next = temp;

    temp = t->next->next;
    t->next->next = u->next->next;
    u->next->next = temp;
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

    exchange(head, head->next);
    exchange(head->next->next, head->next);

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

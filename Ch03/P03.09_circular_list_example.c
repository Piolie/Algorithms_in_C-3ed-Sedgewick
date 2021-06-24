/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
          PROGRAM 3.9 Circular list example (Josephus problem)
------------------------------------------------------------------------
To represent people arranged in a circle, we build a circular linked
list, with a link from each person to the person on the left in the
circle. The integer i represents the ith person in the circle. After
building a one­node circular list for 1, we insert 2 through N after
that node, resulting in a circle with 1 through N, leaving x pointing to
N. Then, we skip M - 1 nodes, beginning with 1, and set the link of the
(M - 1)st to skip the Mth, continuing until only one node is left.
--------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;

struct node {
    int item;
    link next;
};

int main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]), M = atoi(argv[2]);
    link t = malloc(sizeof *t), x = t;
    t->item = 1;
    t->next = t;
    for (i = 2; i <= N; i++)
    {
        x = (x->next = malloc(sizeof *x));
        x->item = i;
        x->next = t;
    }
    while (x != x->next)
    {
        for (i = 1; i < M; i++)
            x = x->next;
        x->next = x->next->next;
        N--;
    }
    printf("%d\n", x->item);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
P03.09_circular_list_example.exe 1000 32

749

--------------------------------------------------------------------- */

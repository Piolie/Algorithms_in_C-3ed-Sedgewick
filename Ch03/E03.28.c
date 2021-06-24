/* ---------------------------------------------------------------------
                             EXERCISE 3.28
------------------------------------------------------------------------
When building the list, Program 3.9 sets twice as many link values as it
needs to because it maintains a circular list after each node is
inserted. Modify the program to build the circular list without doing
this extra work.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Program 3.9 makes the list circular by setting x->next = t at the end of
every iteration. However, when the next iteration starts it sets
x->next to the new node. This is the extra work the exercise statement
is referring to.

To avoid it, we can simply set x->next = t only after all the nodes have
been added.
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
    }
    x->next = t;
    while (x != x->next)
    {
        for (i = 1; i < M; i++)
            x = x->next;
        x->next = x->next->next;
        N--;
    }
    printf("%d\n", x->item);
}

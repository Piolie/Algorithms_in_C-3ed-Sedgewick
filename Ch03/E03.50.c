/* ---------------------------------------------------------------------
                             EXERCISE 3.50
------------------------------------------------------------------------
Implement the interface in Program 3.12 using malloc and free directly
in allocNode and freeNode, respectively.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 3.50
------------------------------------------------------------------------
There is no allocNode in list.h. It might have been the name of the
newNode function in a previous drafting. I'll stick to the latter.

Looking at the next exercise, it is clear that the changes this exercise
asks are supposed to be compatible with the previous interface. Although
freelist and initNodes don't make much sense if the malloc and free
occur elsewhere, I'll preserve the compatibility, so as to be able to
compile exercise 3.51 with either implementation.

--------------------------------------------------------------------- */

#include <stdlib.h>
#include "list.h"

void initNodes(int N) 
{
    // does nothing in this implementation
}

link newNode(int i)
{
    link x = malloc(sizeof *x);
    x->item = i;
    x->next = x;
    return x;
}

void freeNode(link x)
{
    free(x);
}

void insertNext(link x, link t)
{
    t->next = x->next;
    x->next = t;
}

link deleteNext(link x)
{
    link t = x->next;
    x->next = t->next;
    return t;
}

link Next(link x)
{
    return x->next;
}

int Item(link x)
{
    return x->item;
}

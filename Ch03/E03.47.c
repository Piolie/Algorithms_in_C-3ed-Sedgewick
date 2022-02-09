/* ---------------------------------------------------------------------
                             EXERCISE 3.47
------------------------------------------------------------------------
Write a program that frees (calls free with a pointer to) all the nodes
on a given linked list.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define N 100

int main(void)
{
    int i;
    link head = malloc(sizeof *head);
    head->next = NULL;
    link t;

    // fill list with N nodes with random item
    for (i = 0, t = head; i < N; i++)
    {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 1000;
    }

    // free all nodes
    for (t = head->next; t != NULL; t = head->next)
    {
        head->next = t->next;
        free(t);
    }
}

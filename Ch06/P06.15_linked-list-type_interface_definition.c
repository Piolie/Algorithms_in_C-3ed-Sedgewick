/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.15
                 Linked-list-type interface definition
------------------------------------------------------------------------
This interface for linked lists can be contrasted with the one for
arrays in Program 6.7. The init function builds the list, including
storage allocation. The show function prints out the keys in the list.
Sorting programs use less to compare items and manipulate pointers to
rearrange the items. We do not specify here whether or not lists have
head nodes.
--------------------------------------------------------------------- */

typedef struct node *link;
struct node {
  Item item;
  link next;
};

link NEW(Item, link);
link init(int);
void show(link);
link sort(link);

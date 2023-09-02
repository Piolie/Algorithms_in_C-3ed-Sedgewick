/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                 PROGRAM 3.12 List-processing interface
------------------------------------------------------------------------
This code, which might be kept in an interface file list.h, specifies
the types of nodes and links, and declares some of the operations that
we might want to perform on them. We declare our own functions for
allocating and freeing memory for list nodes. The function initNodes
is for the convenience of the implementation. The typedef for Node and
the functions Next and Item allow clients to use lists without
dependence upon implementation details.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The book says (p. 91):
  We assume that another part of the program uses `typedef` or some
  other mechanism to allow us to declare variables of type `Item`.

(It should probably say "type `itemType`".)

The usage in Program 3.14 suggests `itemType` should be an int for these
programs and exercises, so I'll add that to this interface file.
--------------------------------------------------------------------- */

typedef int itemType;
typedef struct node *link;
struct node {
  itemType item;
  link next;
};
typedef link Node;
void initNodes(int);
link newNode(int);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
int Item(link);

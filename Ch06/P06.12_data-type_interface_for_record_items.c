/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.12
                  Data-type interface for record items
------------------------------------------------------------------------
The records have two keys: a string key (for example, a name) in the
first field, and an integer key (for example, a grade) in the second
field. The comparison less is defined as a function, rather than as a
macro, so we can change sort keys by changing implementations.
--------------------------------------------------------------------- */

struct record {
  char name[30];
  int num;
};
typedef struct record *Item;

#define exch(A, B)                                                             \
  {                                                                            \
    Item t = A;                                                                \
    A = B;                                                                     \
    B = t;                                                                     \
  }

#define compexch(A, B)                                                         \
  if (less(B, A))                                                              \
    exch(A, B);

int less(Item, Item);
Item ITEMrand();
int ITEMscan(Item *);
void ITEMshow(Item);

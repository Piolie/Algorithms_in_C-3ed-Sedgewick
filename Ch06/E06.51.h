/* ---------------------------------------------------------------------
                             EXERCISE 6.51
------------------------------------------------------------------------
Write an interface that defines a first-class abstract data type for
generic items (see Section 4.8), and provide an implementation where the
items are floating point numbers. Test your program with Programs 6.3
and 6.6.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Item.h is this file (E06.51.h), while Array.h is
P06.07_interface_for_array_data_type.h. Their corresponding
implementations are E06.51.c and
P06.08_implementation_of_array_data_type.c.
The implementation of sort() is given in P06.03_insertion_sort.c. The
name of the function has to be changed there or otherwise it won't be
found. Also, Item.h has to be included to use less().
--------------------------------------------------------------------- */

typedef struct item *Item;

int less(Item, Item);
void exch(Item, Item);
void compexch(Item, Item);

Item ITEMrand(void);
int ITEMscan(Item *);
void ITEMshow(Item);

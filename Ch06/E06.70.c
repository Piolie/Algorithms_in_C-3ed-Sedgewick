/* ---------------------------------------------------------------------
                             EXERCISE 6.70
------------------------------------------------------------------------
Implement an ADT for sequences, which allows us to use a single driver
program to debug both linked-list and array sort implementations, for
example with the following code:

  #include "Item.h"
  #include "SEQ.h"
  int main(int argc, char *argv[]) {
    int N = atoi(argv[1]), sw = atoi(argv[2]);
    if (sw)
      SEQrandinit(N);
    else
      SEQscaninit(&N);
    SEQsort();
    SEQshow();
  }

That is, client programs can create a sequence with N items (either
generated randomly or filled from standard input), sort the sequence, or
show its contents. Provide one implementation that uses an array
representation and another that uses a linked-list representation. Use
selection sort.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
MISSING!
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                              EXERCISE 4.5
------------------------------------------------------------------------
Rewrite Program 3.1 to use a generic object type in a file Item.h. Your
object type should include ITEMshow (see Exercise 4.3) and ITEMrand, so
that the program can be used for any type of number for which + and /
are defined.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
ITEMrand is not discussed until Program 6.9 further in the book and it's
not needed here. (It simply returns a random key.)

I've chosen float as the concrete type. The appropriate header has to be
included. The type of number requires * and / defined, not + and / as
stated above.
--------------------------------------------------------------------- */

#include "Item.h"
#include <stdio.h>

Item lg(Item);

int main(void) {
  int i;
  Item N;
  for (i = 1, N = 10; i <= 6; i++, N *= 10) {
    ITEMshow(N);
    printf(" ");
    ITEMshow(lg(N));
    printf(" ");
    ITEMshow(N * lg(N));
    printf("\n");
  }
}

Item lg(Item N) {
  int i;
  for (i = 0; N > 1; i++, N /= 2)
    ;
  return i;
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.05.exe
10.000000 4.000000 40.000000
100.000000 7.000000 700.000000
1000.000000 10.000000 10000.000000
10000.000000 14.000000 140000.000000
100000.000000 17.000000 1700000.000000
1000000.000000 20.000000 20000000.000000
--------------------------------------------------------------------- */

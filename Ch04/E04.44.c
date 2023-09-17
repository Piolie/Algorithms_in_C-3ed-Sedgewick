/* ---------------------------------------------------------------------
                             EXERCISE 4.44
------------------------------------------------------------------------
Write a client that picks numbers for a lottery by putting the numbers
1 through 99 on a random queue, then prints the result of removing five
of them.
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int maxN = 99;
  QUEUEinit(maxN);

  printf("Mixing numbers...\n");
  for (int i = 1; i < maxN + 1; i++) {
    QUEUEput(i);
  }

  printf("Do we have a winner?\n");
  for (int i = 0; i < 5; i++) {
    printf("drew: %d\n", QUEUEget());
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.44.exe
Mixing numbers...
Do we have a winner?
drew: 42
drew: 45
drew: 32
drew: 8
drew: 79
--------------------------------------------------------------------- */
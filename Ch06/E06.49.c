/* ---------------------------------------------------------------------
                             EXERCISE 6.49
------------------------------------------------------------------------
Write an interface and implementation for the generic item data type
(similar to Programs 6.9 and 6.10) to support having the sorting methods
sort long integers.
--------------------------------------------------------------------- */

#include "Item.h" // #include "E06.49.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long int ITEMrand(void) {
  return 2.0 * (rand() - RAND_MAX / 2) / RAND_MAX * LONG_MAX;
}

int ITEMscan(long int *x) { return scanf("%ld", x); }

void ITEMshow(long int x) { printf("%7ld ", x); }

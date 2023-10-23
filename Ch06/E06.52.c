/* ---------------------------------------------------------------------
                             EXERCISE 6.52
------------------------------------------------------------------------
Add a function check to the array data type in Programs 6.8 and 6.7,
which tests whether or not the array is in sorted order
--------------------------------------------------------------------- */

#include "Item.h" // #include "P06.09_sample_interface_for_item_data_type.h"

int sorted(Item a[], int l, int r) {
  for (int i = r; i > l; i--)
    if (less(a[i], a[i - 1]))
      return 0;
  return 1;
}

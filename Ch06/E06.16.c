/* ---------------------------------------------------------------------
                             EXERCISE 6.16
------------------------------------------------------------------------
Give an implementation of insertion sort with the inner loop coded as a
while loop that terminates on one of two conditions, as described in the
text.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I assume this is referring to P06.01 (nonadaptive insertion sort) and
not P06.03 (adaptive insertion sort), since the latter already includes
a while loop and implements the sentinel, which makes the second test
(j > l) unnecessary.
--------------------------------------------------------------------- */

void sort(Item a[], int l, int r) {
  int i, j;
  for (i = l + 1; i <= r; i++) {
    j = i;
    while ((j > l) && (less(a[j], a[j - 1]))) {
      exch(a[j - 1], a[j]);
      j--;
    }
  }
}

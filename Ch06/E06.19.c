/* ---------------------------------------------------------------------
                             EXERCISE 6.19
------------------------------------------------------------------------
Give a nonadaptive implementation of selection sort based on finding the
minimum element with code like the first for loop in Program 6.3.
--------------------------------------------------------------------- */

void selection(Item a[], int l, int r) {
  int i, j;
  for (i = l; i < r; i++)
    for (j = i + 1; j <= r; j++)
      compexch(a[i], a[j]);
}

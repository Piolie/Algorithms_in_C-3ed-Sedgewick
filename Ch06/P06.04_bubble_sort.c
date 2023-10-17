/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.4
                              Bubble sort
------------------------------------------------------------------------
For each i from 1 to r-1, the inner (j) loop puts the minimum element
among the elements in a[i], ..., a[r] into a[i] by passing from right to
left through the elements, compare-exchanging successive elements. The
smallest one moves on all such comparisons, so it "bubbles" to the
beginning. As in selection sort, as the index i travels from left to
right through the file, the elements to its left are in their final
position in the array.
--------------------------------------------------------------------- */

void bubble(Item a[], int l, int r) {
  int i, j;
  for (i = l; i < r; i++)
    for (j = r; j > i; j--)
      compexch(a[j - 1], a[j]);
}

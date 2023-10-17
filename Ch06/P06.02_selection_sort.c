/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.2
                             Selection sort
------------------------------------------------------------------------
For each i from 1 to r-1, exchange a[i] with the minimum element in
a[i], ..., a[r]. As the index i travels from left to right, the elements
to its left are in their final position in the array (and will not be
touched again), so the array is fully sorted when i reaches the right
end.
--------------------------------------------------------------------- */

void selection(Item a[], int l, int r) {
  int i, j;
  for (i = l; i < r; i++) {
    int min = i;
    for (j = i + 1; j <= r; j++)
      if (less(a[j], a[min]))
        min = j;
    exch(a[i], a[min]);
  }
}

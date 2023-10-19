/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.5
                               Shellsort
------------------------------------------------------------------------
If we do not use sentinels and then replace every occurrence of "1" by
"h" in insertion sort, the resulting program h-sorts the file. Adding
an outer loop to change the increments leads to this compact shellsort
implementation, which uses the increment sequence 1 4 13 40 121 364
1093 3280 9841 ....
--------------------------------------------------------------------- */

void shellsort(Item a[], int l, int r) {
  int i, j, h;
  for (h = 1; h <= (r - l) / 9; h = 3 * h + 1)
    ;
  for (; h > 0; h /= 3)
    for (i = l + h; i <= r; i++) {
      j = i;
      Item v = a[i];
      while (j >= l + h && less(v, a[j - h])) {
        a[j] = a[j - h];
        j -= h;
      }
      a[j] = v;
    }
}

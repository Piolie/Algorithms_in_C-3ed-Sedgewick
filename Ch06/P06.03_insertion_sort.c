/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.3
                             Insertion sort
------------------------------------------------------------------------
This code is an improvement over the implementation of sort in
Program 6.1 because (i) it first puts the smallest element in the array
into the first position, so that that element can serve as a sentinel;
(ii) it does a single assignment, rather than an exchange, in the inner
loop; and (iii) it terminates the inner loop when the element being
inserted is in position. For each i, it sorts the elements
a[1], ..., a[i] by moving one position to the right elements in the
sorted list a[1], ..., a[i-1] that are larger than a[i], then putting
a[i] into its proper position.
--------------------------------------------------------------------- */

void insertion(Item a[], int l, int r) {
  int i;
  for (i = l + 1; i <= r; i++)
    compexch(a[l], a[i]);
  for (i = l + 2; i <= r; i++) {
    int j = i;
    Item v = a[i];
    while (less(v, a[j - 1])) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
}

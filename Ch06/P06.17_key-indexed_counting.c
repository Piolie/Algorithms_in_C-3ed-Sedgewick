/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.17
                          Key-indexed counting
------------------------------------------------------------------------
The first for loop initializes the counts to 0; the second for loop sets
the second counter to the number of Os, the third counter to the number
of 1s, and so forth. Then, the third for loop simply adds these numbers
to produce counts of the number of keys less than or equal to the one
corresponding to the count. These numbers now give the indices of the
end of the part of the file where keys belong. The fourth for loop moves
the keys into an auxiliary array b according to these indices, and the
final loop moves the sorted file back into a. The keys must be integers
less than Mfor this code to work, although we can easily modify it to
extract such keys from more complex items (see Exercise 6.75).
--------------------------------------------------------------------- */

void distcount(int a[], int l, int r) {
  int i, j, cnt[M];
  int b[maxN];
  for (j = 0; j < M; j++)
    cnt[j] = 0;
  for (i = l; i <= r; i++)
    cnt[a[i] + 1]++;
  for (j = 1; j < M; j++)
    cnt[j] += cnt[j - 1];
  for (i = l; i <= r; i++)
    b[cnt[a[i]]++] = a[i];
  for (i = l; i <= r; i++)
    a[i] = b[i];
}

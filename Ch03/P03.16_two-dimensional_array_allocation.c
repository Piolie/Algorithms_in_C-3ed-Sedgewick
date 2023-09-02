/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 3.16
                    Two-dimensional array allocation
------------------------------------------------------------------------
This function dynamically allocates the memory for a two-dimensional
array, as an array of arrays. We first allocate an array of pointers,
then allocate memory for each row. With this function, the statement
    int **a = malloc2d(M, N);
allocates an M-by-N array of integers.
--------------------------------------------------------------------- */

int **malloc2d(int r, int c) {
  int i;
  int **t = malloc(r * sizeof(int *));
  for (i = 0; i < r; i++)
    t[i] = malloc(c * sizeof(int));
  return t;
}

/* ---------------------------------------------------------------------
                             EXERCISE 3.63
------------------------------------------------------------------------
Write a version of Program 3.16 that handles three-dimensional arrays.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
See why this function is not a good idea:
  [Correctly allocating multi-dimensional arrays](https://stackoverflow.com/questions/42094465/)
--------------------------------------------------------------------- */

int **malloc3d(int rows, int columns, int depth) {
  int r, c;
  int ***t = malloc(depth * sizeof(int **));
  for (r = 0; r < rows; r++) {
    t[r] = malloc(rows * sizeof(int *));
    for (c = 0; c < columns; c++)
      t[r][c] = malloc(columns * sizeof(int));
  }
  return t;
}

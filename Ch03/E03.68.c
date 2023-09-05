/* ---------------------------------------------------------------------
                             EXERCISE 3.68
------------------------------------------------------------------------
Implement matrix multiplication for matrices represented with multi­
lists.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Function multiply_2D_matrices has been adapted from the book (p. 115),
and used for validation of the output of multiply_2D_multilists, which
is the function that the exercise is asking to write. I've also
included an auxiliary multilists_are_equal function to quickly check
the results.

Notice that once the rth row of the product has been completed, the rth
row of m1 does not intervene any longer. However, my implementation
does not take advantage of this fact, and always traverses m1 from the
first row (link tm1 = m1->next_c). It could be improved by keeping
track of the last node in the current row, and starting from the next
one once the computation of the following row starts.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
  int val;
  int row;
  int col;
  link next_c; // next node in the same row
  link next_r; // next node in the same column
};

void *build_sparse_matrix(int rows, int cols) {
  int id = 0;
  int(*matrix)[cols] = malloc(sizeof(int[rows][cols]));
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      int val = (rand() % 2) * (rand() % 2) * (rand() % 2);
      matrix[i][j] = val ? ++id : 0;
    }

  return matrix;
}

void print_2D_matrix(int rows, int cols, int matrix[rows][cols]) {
  const int digits = 4;
  printf("%*s", digits + 2, " ");
  for (int c = 0; c < cols; c++)
    printf("%*d", digits, c);
  printf("\n");
  printf("%*s", digits + 2, " ");
  for (int r = 0; r < digits * cols + 1; r++)
    printf("-");
  printf("\n");

  for (int r = 0; r < rows; r++) {
    printf("%*d |", digits, r);
    for (int c = 0; c < cols; c++)
      printf("%*d", digits, matrix[r][c]);
    printf("\n");
  }
}

link init_multilist(int rows, int cols) {
  link multi = malloc(sizeof *multi);
  // interpret the row and col fields of the
  // multilist's head as the dimensions of the matrix
  multi->row = rows;
  multi->col = cols;
  multi->val = -99; // no interpretation
  multi->next_c = NULL;
  multi->next_r = NULL;

  return multi;
}

void insert_in_multilist(link multi, int row, int col, int val) {
  // could be used to validate row and col args
  // int rows = multi->row;
  // int cols = multi->col;

  link tc, tr;

  for (tc = multi; tc->next_c; tc = tc->next_c) {
    if (tc->next_c->row == row) {
      // if node was already created, replace value and return
      if (tc->next_c->col == col) {
        tc = tc->next_c;
        tc->val = val;
        return;
      }
      if (tc->next_c->col > col)
        // insert node
        break;
    }
    if (tc->next_c->row > row)
      // insert node
      break;
  }

  for (tr = multi; tr->next_r; tr = tr->next_r) {
    if (tr->next_r->col == col)
      if (tr->next_r->row > row)
        // insert node
        break;
    if (tr->next_r->col > col)
      // insert node
      break;
  }

  // create node, assign values
  link tmp = malloc(sizeof *tmp);
  tmp->val = val;
  tmp->row = row;
  tmp->col = col;
  // insert node in row list
  tmp->next_c = tc->next_c;
  tc->next_c = tmp;
  // insert node in col list
  tmp->next_r = tr->next_r;
  tr->next_r = tmp;
}

link matrix_to_multilist(int rows, int cols, int matrix[rows][cols]) {
  link multi = init_multilist(rows, cols);
  int val;

  // look for nonzero nodes and insert
  for (int row = 0; row < rows; row++)
    for (int col = 0; col < cols; col++)
      if ((val = matrix[row][col]))
        insert_in_multilist(multi, row, col, val);

  return multi;
}

void print_2D_multilist(link multi) {
  const int digits = 4;

  printf("Nodes by rows:\n");
  for (link t = multi->next_c; t; t = t->next_c)
    printf("%*d -> ", digits, t->val);
  printf("*\n");

  printf("\n");

  printf("Nodes by columns:\n");
  for (link t = multi->next_r; t; t = t->next_r)
    printf("%*d -> ", digits, t->val);
  printf("*\n");
}

void pretty_print_2D_multilist(link multi) {
  int cols = multi->col;
  int rows = multi->row;
  const int digits = 4;

  printf("%*s", digits + 2, " ");
  for (int c = 0; c < cols; c++)
    printf("%*d", digits, c);
  printf("\n");
  printf("%*s", digits + 2, " ");
  for (int r = 0; r < digits * cols + 1; r++)
    printf("-");
  printf("\n");

  link t = multi->next_c;
  int row = 0, last_row = 0;
  while (t) {
    row = t->row;
    while (row > last_row) {
      printf("%*d |", digits, last_row);
      last_row++;
      printf("\n");
    }

    printf("%*d |", digits, row);

    int last_col = 0;
    while (t) {
      if (t->row > last_row) {
        last_row++;
        break;
      }
      int c = t->col + 1;
      printf("%*d", digits * (c - last_col), t->val);
      last_col = c;
      t = t->next_c;
    }
    row++;
    printf("\n");
  }
  while (row < rows) {
    printf("%*d |", digits, row++);
    printf("\n");
  }
}

void *multiply_2D_matrices(int rows1, int cols1, int m1[rows1][cols1],
                           int rows2, int cols2, int m2[rows2][cols2]) {
  if (cols1 != rows2)
    return NULL;

  int(*m)[cols2] = build_sparse_matrix(rows1, cols2);
  for (int i = 0; i < rows1; i++)
    for (int j = 0; j < cols2; j++) {
      m[i][j] = 0;
      for (int k = 0; k < cols1; k++)
        m[i][j] += m1[i][k] * m2[k][j];
    }

  return m;
}

void *multiply_2D_multilists(int rows1, int cols1, link m1, int rows2,
                             int cols2, link m2) {
  if (cols1 != rows2)
    return NULL;

  link m = init_multilist(rows1, cols2);

  for (int row = 0; row < rows1; row++) {
    link tm2 = m2->next_r;
    for (int col = 0; col < cols2; col++) {
      link tm1 = m1->next_c;
      int val = 0;
      while (tm1 && tm2) {
        if ((tm1->row > row) || (tm2->col > col))
          break;

        if ((tm1->row == row) && (tm2->col == col)) {
          if (tm1->col == tm2->row) {
            val += tm1->val * tm2->val;
            tm1 = tm1->next_c;
            tm2 = tm2->next_r;
            continue;
          } else if (tm1->col > tm2->row) {
            tm2 = tm2->next_r;
            continue;
          } else {
            tm1 = tm1->next_c;
            continue;
          }
        }

        if (tm1->row < row)
          tm1 = tm1->next_c;
        if (tm2->col < col)
          tm2 = tm2->next_r;
      }

      if (val)
        insert_in_multilist(m, row, col, val);
    }
  }
  return m;
}

int multilists_are_equal(link multi1, link multi2) {
  while (multi1 && multi2) {
    if (multi1->row != multi2->row)
      return 0;
    if (multi1->col != multi2->col)
      return 0;
    if (multi1->val != multi2->val)
      return 0;
    multi1 = multi1->next_c;
    multi2 = multi2->next_c;
  }
  if (multi1 || multi2) // lists are different length
    return 0;
  return 1;
}
int main(int argc, char *argv[]) {
  (void)argc;
  int rows1 = atoi(argv[1]);
  int cols1 = atoi(argv[2]);

  int rows2 = atoi(argv[3]);
  int cols2 = atoi(argv[4]);

  int(*matrix1)[cols1] = build_sparse_matrix(rows1, cols1);
  int(*matrix2)[cols2] = build_sparse_matrix(rows2, cols2);
  link multi1 = matrix_to_multilist(rows1, cols1, matrix1);
  link multi2 = matrix_to_multilist(rows2, cols2, matrix2);

  printf("Matrix 1:\n");
  pretty_print_2D_multilist(multi1);
  printf("\nMatrix 2:\n");
  pretty_print_2D_multilist(multi2);

  printf("\n2D-array product:\n");
  int(*matrix)[cols2] =
      multiply_2D_matrices(rows1, cols1, matrix1, rows2, cols2, matrix2);
  link multi = matrix_to_multilist(rows1, cols2, matrix);
  pretty_print_2D_multilist(multi);

  printf("\nMultilist product:\n");
  link product =
      multiply_2D_multilists(rows1, cols1, multi1, rows2, cols2, multi2);
  pretty_print_2D_multilist(product);

  printf("\n2D-array and multilist products are equal: %s\n",
         multilists_are_equal(multi, product) ? "YES!" : "NO!");
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.68.exe 10 5 5 10
Matrix 1:
         0   1   2   3   4
      ---------------------
   0 |                   1
   1 |
   2 |           2
   3 |               3
   4 |
   5 |
   6 |               4
   7 |
   8 |
   9 |       5   6   7

Matrix 2:
         0   1   2   3   4   5   6   7   8   9
      -----------------------------------------
   0 |                       1
   1 |
   2 |           2   3
   3 |                           4           5
   4 |                   6

2D-array product:
         0   1   2   3   4   5   6   7   8   9
      -----------------------------------------
   0 |                   6
   1 |
   2 |           4   6
   3 |                          12          15
   4 |
   5 |
   6 |                          16          20
   7 |
   8 |
   9 |          12  18          28          35

Multilist product:
         0   1   2   3   4   5   6   7   8   9
      -----------------------------------------
   0 |                   6
   1 |
   2 |           4   6
   3 |                          12          15
   4 |
   5 |
   6 |                          16          20
   7 |
   8 |
   9 |          12  18          28          35

2D-array and multilist products are equal: YES!
--------------------------------------------------------------------- */

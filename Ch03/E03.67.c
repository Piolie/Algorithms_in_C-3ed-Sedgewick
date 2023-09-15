/* ---------------------------------------------------------------------
                             EXERCISE 3.67
------------------------------------------------------------------------
Write a program to convert a sparse matrix from a two-dimensional
array to a multilist with nodes for only nonzero values.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
See E03.67_alternative.c for my notes and a different approach.
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

int main(int argc, char *argv[]) {
  (void)argc;
  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);

  int(*matrix)[cols] = build_sparse_matrix(rows, cols);
  link multi = matrix_to_multilist(rows, cols, matrix);

  printf("Matrix representation:\n");
  print_2D_matrix(rows, cols, matrix);
  printf("\nMultilist (pretty) representation:\n");
  pretty_print_2D_multilist(multi);
  printf("\nMultilist row and column lists:\n");
  print_2D_multilist(multi);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.67.exe 10 10
Matrix representation:
         0   1   2   3   4   5   6   7   8   9
      -----------------------------------------
   0 |   0   0   0   0   1   0   0   0   0   0
   1 |   0   0   2   0   0   0   0   0   3   0
   2 |   0   0   0   0   0   0   0   0   0   0
   3 |   0   0   0   4   0   0   0   0   0   0
   4 |   0   0   0   0   0   0   5   6   7   0
   5 |   0   0   0   0   0   8   0   0   0   0
   6 |   0   0   0   0   0   0   0   0   0   0
   7 |   0   0   9  10   0   0   0   0   0   0
   8 |   0   0   0   0   0   0  11   0   0  12
   9 |   0   0   0   0  13   0   0   0   0   0

Multilist (pretty) representation:
         0   1   2   3   4   5   6   7   8   9
      -----------------------------------------
   0 |                   1
   1 |           2                       3
   2 |
   3 |               4
   4 |                           5   6   7
   5 |                       8
   6 |
   7 |           9  10
   8 |                          11          12
   9 |                  13

Multilist row and column lists:
Nodes by rows:
   1 ->    2 ->    3 ->    4 ->    5 ->    6 ->    7 ->    8 ->    9 ->   10 ->
11 ->   12 ->   13 -> *

Nodes by columns:
   2 ->    9 ->    4 ->   10 ->    1 ->   13 ->    8 ->    5 ->   11 ->    6 ->
3 ->    7 ->   12 -> *
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 3.67
------------------------------------------------------------------------
Write a program to convert a sparse matrix from a two-dimensional
array to a multilist with nodes for only nonzero values.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This was my first attempt at this exercise. After finishing it, I
realized that maybe the solution the author looked for was more likely
the last one mentioned below. Since the program works and I've found
the following notes useful, I'm keeping this as an alternative take.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The relevant sections of the book say:
    We can build compound data structures exclusively with links, as
    well. Figure 3.13 shows an example of a multilist, where nodes have
    multiple link fields and belong to independently maintained linked
    lists.
    [...]
    If a multidimensional matrix is sparse (relatively few of the
    entries are nonzero), then we might use a multilist rather than a
    multidimensional array to represent it. We could use one node for
    each [nonzero] value in the matrix and one link for each dimension,
    with the link pointing to the next item [node] in that dimension.

I don't see how to implement this in a straightforward manner. For
example, if the we're handed a diagonal matrix, then each node has no
next node in either of the two dimensions. How do we get to each node
then?

I could think of three possible solutions:
1) Use an array with as many nodes as the are nonzero entries. More like
an adjacency-multilist representation.
This would imply first counting the number of nonzero entries, then
reserving memory for the array and finally visiting each node to create
the links. This requires various passes through the matrix and adding
nodes or implementing matrix operations with this representation doesn't
look very ergonomic, since the node index in the array is unrelated to
its position in the matrix.

2) Starting at the first row and moving right, add each node as it
appears. If the row ends before finding another nonzero node, continue
with the next row. Similarly while moving down through the first column.
Example:
+---------------+
| 0   0   1   0 |
| 0   2   0   0 |  rows:    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> *
| 0   0   3   4 |  columns: 5 -> 2 -> 6 -> 1 -> 3 -> 4 -> *
| 5   6   0   0 |
+---------------+
That way, if we start at the head node, we can always traverse all nodes
in the matrix, either going row-wise or column-wise.
*I think this is the one Mr. Sedgewick wanted us to write.*

3) Use a list of dummy node heads for each dimension. This allows us to
quickly retrieve all the nodes from any row or column, which makes
operating on matrices much easier. Starting at the head, we traverse the
dummy list in the desired direction, until we reach the intended dummy
node, then follow the links in the other direction to get the nodes.
This also requires two passes and more memory for the dummy nodes. Let's
do that. This implementation keeps all nodes in the same row sorted from
left to right, and all in the same column sorted from top to bottom.

drx = dummy row x; dcy = dummy column y.
head dc0 dc1 dc2 dc3
    +---------------+
dr0 | 0   0   1   0 |     dc0: 4->  | dr0: 1->
dr1 | 0   2   0   0 |     dc1: 2->5 | dr1: 2->
dr2 | 0   0   3   0 |     dc2: 1->3 | dr2: 3->
dr3 | 4   5   0   6 |     dc2: 6->  | dr3: 4->5->6
    +---------------+

I took inspiration from the answer to this SO question:
- [Application of multilist data structure in
C++](https://stackoverflow.com/questions/11796143/).

The node for each entry should then contain, besides the value of the
entry and the links referred to above, information about the row and
column where it is located in the matrix.

I use (rand()%2)*(rand()%2)*(rand()%2) as a quick and dirty way of
making the matrix sparse. Also, made every nonzero entry different, to
make it easier to check the results.

For the multilist, there are functions to pretty print the matrix and
also to print each row and column list.

See also this SO answer:
  [Function to dynamically allocate
matrix](https://stackoverflow.com/questions/32050256/).
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
  link t, multi = malloc(sizeof *multi);
  // interpret the row and col fields of the
  // multilist's head as the dimensions of the matrix
  multi->row = rows;
  multi->col = cols;
  multi->val = -99; // no interpretation
  multi->next_c = NULL;
  multi->next_r = NULL;

  // allocate and link dummy row heads
  t = multi;
  for (int r = 0; r < rows; r++) {
    t->next_r = malloc(sizeof *t);
    t = t->next_r;
    t->val = -1;
    t->row = r;
    t->col = -1;
    t->next_c = NULL;
    t->next_r = NULL;
  }

  // allocate and link dummy col heads
  t = multi;
  for (int c = 0; c < cols; c++) {
    t->next_c = malloc(sizeof *t);
    t = t->next_c;
    t->val = -1;
    t->row = -1;
    t->col = c;
    t->next_c = NULL;
    t->next_r = NULL;
  }

  return multi;
}

void insert_in_multilist(link multi, int row, int col, int val) {
  // could be used to validate row and col args
  // int rows = multi->row;
  // int cols = multi->col;

  link tc, tr;

  link row_head = multi->next_r;
  for (int r = 0; r < row; r++)
    row_head = row_head->next_r;
  for (tc = row_head; tc->next_c; tc = tc->next_c) {
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
  link col_head = multi->next_c;
  for (int c = 0; c < col; c++)
    col_head = col_head->next_c;
  for (tr = col_head; tr->next_r; tr = tr->next_r)
    if (tr->next_r->row > row)
      break;

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
  for (link tr = multi->next_r; tr; tr = tr->next_r) {
    printf("row %*d: ", digits, tr->row);
    for (link t = tr->next_c; t; t = t->next_c)
      printf("%*d -> ", digits, t->val);
    printf("*\n");
  }

  printf("\n");

  printf("Nodes by columns:\n");
  for (link tc = multi->next_c; tc; tc = tc->next_c) {
    printf("col %*d: ", digits, tc->col);
    for (link t = tc->next_r; t; t = t->next_r)
      printf("%*d -> ", digits, t->val);
    printf("*\n");
  }
}

void pretty_print_2D_multilist(link multi) {
  int cols = multi->col;
  const int digits = 4;

  printf("%*s", digits + 2, " ");
  for (int c = 0; c < cols; c++)
    printf("%*d", digits, c);
  printf("\n");
  printf("%*s", digits + 2, " ");
  for (int r = 0; r < digits * cols + 1; r++)
    printf("-");
  printf("\n");

  for (link tr = multi->next_r; tr; tr = tr->next_r) {
    printf("%*d |", digits, tr->row);
    int last_col = 0;
    for (link t = tr->next_c; t; t = t->next_c) {
      int c = t->col + 1;
      printf("%*d", digits * (c - last_col), t->val);
      last_col = c;
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);

  // using a function relies on malloc:
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
E03.67_alternative.exe 10 10
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
row    0:    1 -> *
row    1:    2 ->    3 -> *
row    2: *
row    3:    4 -> *
row    4:    5 ->    6 ->    7 -> *
row    5:    8 -> *
row    6: *
row    7:    9 ->   10 -> *
row    8:   11 ->   12 -> *
row    9:   13 -> *

Nodes by columns:
col    0: *
col    1: *
col    2:    2 ->    9 -> *
col    3:    4 ->   10 -> *
col    4:    1 ->   13 -> *
col    5:    8 -> *
col    6:    5 ->   11 -> *
col    7:    6 -> *
col    8:    3 ->    7 -> *
col    9:   12 -> *
--------------------------------------------------------------------- */

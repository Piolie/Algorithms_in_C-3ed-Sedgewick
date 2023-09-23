/* ---------------------------------------------------------------------
                             EXERCISE 4.80
------------------------------------------------------------------------
Develop an ADT that provides clients with the ability to perform
algebraic operations on matrices of abstract objects for which addition,
subtraction, multiplication, and division are defined.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'm borrowing heavily from E03.67 and E03.68.

This implementation only supports types for which + and * is already
defined: char, int, float, etc. (subtraction and division are not
needed). In case we want to support more abstract types, we could
write appropriate operations in an Item.c file, and then modify this
implementation to use ITEMadd instead of +, ITEMmult instead of *, and
so on.
--------------------------------------------------------------------- */

// #define DEBUG_E04_80

#include "Item.h"   // typedef int Item
#include "MATRIX.h" // #include "E04.80_interface.h"
#include <stdio.h>
#include <stdlib.h>

struct matrix {
  int rows;
  int cols;
  Item (*m)[]; // pointer to array of Item
};

void MATshow(Matrix matrix) {
  const int digits = 4;
  const int rows = matrix->rows;
  const int cols = matrix->cols;
  Item(*m)[rows] = matrix->m;

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
      ITEMshow(m[r][c], digits);
    printf("\n");
  }
}

Matrix MATinit(int rows, int cols) {
  Matrix matrix = malloc(sizeof(*matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->m = malloc(sizeof(Item[rows][cols]));
  return matrix;
}

void MATset(Matrix matrix, int row, int col, Item val) {
  Item(*m)[matrix->rows] = matrix->m;
  m[row][col] = val;
}

Matrix MATadd(Matrix matrix1, Matrix matrix2) {
  const int rows = matrix1->rows;
  const int cols = matrix1->cols;

  Item(*m1)[rows] = matrix1->m;
  Item(*m2)[rows] = matrix2->m;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      m1[i][j] += m2[i][j];
  return matrix1;
}

Matrix MATmult(Matrix matrix1, Matrix matrix2) {
  const int rows1 = matrix1->rows;
  const int cols1 = matrix1->cols;
  const int rows2 = matrix2->rows;
  const int cols2 = matrix2->cols;

  Matrix matrix = MATinit(rows1, cols2);

  Item(*m)[rows1] = matrix->m;
  Item(*m1)[rows1] = matrix1->m;
  Item(*m2)[rows2] = matrix2->m;

  for (int i = 0; i < rows1; i++)
    for (int j = 0; j < cols2; j++) {
      m[i][j] = 0;
      for (int k = 0; k < cols1; k++)
        m[i][j] += m1[i][k] * m2[k][j];
    }
  return matrix;
}

#ifdef DEBUG_E04_80
int main(void) {
  int rows1 = 4;
  int cols1 = 4;
  int rows2 = 4;
  int cols2 = 4;
  Matrix m1 = MATinit(rows1, cols1);
  Matrix m2 = MATinit(rows2, cols2);

  for (int row = 0; row < rows1; row++)
    for (int col = 0; col < cols1; col++)
      MATset(m1, row, col, row + col);

  for (int row = 0; row < rows2; row++)
    for (int col = 0; col < cols2; col++)
      MATset(m2, row, col, row == col); // identity matrix

  printf("M1 = \n");
  MATshow(m1);
  printf("\n");
  printf("M2 = \n");
  MATshow(m2);
  printf("\n");
  printf("M1 = M1 + M2 = \n");
  MATshow(MATadd(m1, m2));
  printf("\n");
  printf("M1 = M1 * M2 = \n");
  MATshow(MATmult(m1, m2));
}
#endif // #ifdef DEBUG_E04_80

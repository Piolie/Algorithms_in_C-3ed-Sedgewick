/* ---------------------------------------------------------------------
                             EXERCISE 4.80
------------------------------------------------------------------------
Develop an ADT that provides clients with the ability to perform
algebraic operations on matrices of abstract objects for which addition,
subtraction, multiplication, and division are defined.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Just like in E04.79, the implementation doesn't check the validity of
the inputs.

The addition modifies the first parameter.
--------------------------------------------------------------------- */

typedef struct matrix *Matrix;
void MATshow(Matrix matrix);
Matrix MATinit(int rows, int cols);
void MATset(Matrix matrix, int row, int col, Item val);
Matrix MATadd(Matrix matrix1, Matrix matrix2);
Matrix MATmult(Matrix matrix1, Matrix matrix2);

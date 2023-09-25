/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 5.4
            Recursive program to evaluate prefix expressions
------------------------------------------------------------------------
To evaluate a prefix expression, we either convert a number from ASCII
to binary (in the while loop at the end), or perform the operation
indicated by the first character in the expression on the two operands,
evaluated recursively. This function is recursive, but it uses a global
array containing the expression and an index to the current character
in the expression. The pointer is advanced past each subexpression
evaluated.
--------------------------------------------------------------------- */

char *a;
int i;
int eval(void) {
  int x = 0;
  while (a[i] == ' ')
    i++;
  if (a[i] == '+') {
    i++;
    return eval() + eval();
  }
  if (a[i] == '*') {
    i++;
    return eval() * eval();
  }
  while ((a[i] >= '0') && (a[i] <= '9'))
    x = 10 * x + (a[i++] - '0');
  return x;
}

/* ---------------------------------------------------------------------
  Figure 5.3
  Prefix expression evaluation example

  This nested sequence of function calls illustrates the operation of
  the recursive prefix-expression­evaluation algorithm on a sample
  expression. For simplicity, the expression arguments are shown here.
  The algorithm itself never explicitly decides the extent of its
  argument string: rather, it takes what it needs from the front of the
  string.

  eval() * + 7 * * 4 6 + 8 9 5
    eval() + 7 * * 4 6 + 8 9
      eval() 7
      eval() * * 4 6 + 8 9
        eval() * 4 6
        eval() 4
        eval() 6
        return 24 = 4*6
      eval() + 8 9
        eval() 8
        eval() 9
        return 17 = 8 + 9
      return 408 = 24*17
    return 415 = 7+408
  eval() 5
  return 2075 = 415*5
--------------------------------------------------------------------- */

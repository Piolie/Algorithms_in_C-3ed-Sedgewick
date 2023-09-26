/* ---------------------------------------------------------------------
                             EXERCISE 5.10
------------------------------------------------------------------------
Write a recursive program to evaluate infix expressions. You may assume
that operands are always enclosed in parentheses.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This solution works only with expressions of the form
  (a op (b op (c op (...))))
I don't see how to solve this without the use of a stack. I've assumed
there are no spaces between tokens.
--------------------------------------------------------------------- */

#include <stdio.h>

char *a;
int i;

int eval(void) {
  int x = 0;
  int y = 0;
  if (a[i] == '(') {
    i++;
    x = eval();
  }
  char c = a[i];
  if (c == '+') {
    i++;
    y = eval();
    return x + y;
  } else if (c == '*') {
    i++;
    y = eval();
    return x * y;
  }
  if ((a[i] >= '0') && (a[i] <= '9')) {
    int num = 0;
    while ((a[i] >= '0') && (a[i] <= '9'))
      num = 10 * num + (a[i++] - '0');
    return num;
  }

  if (a[i++] != '\0') {
    return eval();
  }
  return 0;
}

int main(int argc, char *argv[]) {
  (void)argc;
  a = argv[1];
  i = 0;
  printf("%d\n", eval());
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.10.exe "(1+(2+3)"
6

./E05.10.exe "(1+(2*3)"
7

./E05.10.exe "(1+(2*(3+(4*(5+6))))"
95
--------------------------------------------------------------------- */

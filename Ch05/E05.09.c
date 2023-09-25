/* ---------------------------------------------------------------------
                              EXERCISE 5.9
------------------------------------------------------------------------
Write a recursive program to evaluate postfix expressions.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
One alternative is to first convert the postfix expression to prefix,
and then evaluate as in E05.08. This can be done easily using a stack.

I've simply traverse the string right-to-left. This turns the increments
to decrements (++ to --) and changes the handling of the operands in the
last while.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

char *a;
int i;

int eval(void) {
  int x = 0;
  while (a[i] == ' ')
    i--;
  if (a[i] == '+') {
    i--;
    return eval() + eval();
  }
  if (a[i] == '*') {
    i--;
    return eval() * eval();
  }
  int j = 1;
  while ((a[i] >= '0') && (a[i] <= '9')) {
    x += j * (a[i--] - '0');
    j *= 10;
  }
  return x;
}

int main(int argc, char *argv[]) {
  (void)argc;
  a = argv[1];
  i = strlen(a) - 1;
  printf("%d", eval());
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.09.exe "144 12 12 12 * * +"
1872

./E05.09.exe "5 9 8 + 6 4 * * 7 + *"
2075
--------------------------------------------------------------------- */

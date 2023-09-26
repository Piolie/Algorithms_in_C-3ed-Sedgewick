/* ---------------------------------------------------------------------
                             EXERCISE 5.11
------------------------------------------------------------------------
Write a recursive program that converts infix expressions to postfix.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This is the recursive version of P04.03 (Infix-to-postfix conversion).
It turned out to be more robust than the previous version, since it
ignores whitespaces and doesn't care about extra matching parenthesis.
--------------------------------------------------------------------- */

#include <stdio.h>

char *a;
int i;

void eval(void) {
  if (a[i] == '(') {
    i++;
    eval();
  }
  char c = a[i];
  if ((c == '+') || (c == '*')) {
    i++;
    eval();
    printf("%c ", c);
    return;
  }
  if ((a[i] >= '0') && (a[i] <= '9')) {
    while ((a[i] >= '0') && (a[i] <= '9'))
      printf("%c", a[i++]);
    printf(" ");
    return;
  }

  if (a[i++] != '\0') {
    eval();
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  a = argv[1];
  i = 0;
  eval();
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.11.exe "( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )"
5 9 8 + 4 6 * * 7 + *

./E05.11.exe "((5 * 9) * (8 + ((7 * (4 + 6)) * (2 + (1 * 3) ))))"
5 9 * 8 7 4 6 + * 2 1 3 * + * + *

./E05.11.exe "(3 * (((2 * 5) * 3) + 2))"
3 2 5 * 3 * 2 + *

./E05.11.exe "(((((3 * (((2 * 5) * 3) + 2))))))"
3 2 5 * 3 * 2 + *
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 4.15
------------------------------------------------------------------------
Write a program that converts a postfix expression to infix, using a
pushdown stack.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The book outlines the method:
  [...] we can consider the following process for converting a postfix
  expression to an infix expression: We replace all occurrences of two
  operands followed by an operator by their infix equivalent, with
  parentheses, to indicate that the result can be considered to be an
  operand. That is, we replace any occurrence of a b * and a b + by
  (a * b) and (a + b), respectively. Then, we perform the same
  transformation on the resulting expression, continuing until all the
  operators have been processed.
  5 9 8 + 4 6 * * 7 + *
  5 (9 + 8) (4 * 6) * 7 + *
  5 ((9 + 8) * (4 * 6)) 7 + *
  5 (((9 + 8) * (4 * 6)) + 7) *
  (5 * (((9 + 8) * (4 * 6)) + 7))
  We can determine the operands associated with any Operator in the
  postf‌ix expression in this way, so no parentheses are necessary.

To make this work, we'll need a stack of strings, since each operand
can now be itself an expression. I'm adding the appropriate
Item_string.h, which is a copy of E04.03. To build the strings, we'll be
using the snprintf, provided by the standard library since C99, and
assume a maximum string size of BUFSZ. (We could dynamically allocate
the exact memory we need for each string using two calls to snprintf, as
explained in: [Building Strings from variables in
C](https://stackoverflow.com/questions/4881937/).)

I've switched to the linked-list implementation, on a whim.

I've not bothered with '-', '/' or unary operations.
--------------------------------------------------------------------- */

#include "STACK.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSZ 50

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[1];
  int i, N = strlen(a);
  STACKinit(N);
  for (i = 0; i < N; i++) {
    if ((a[i] == '+') || (a[i] == '*')) {
      char *buffer = malloc(BUFSZ * sizeof(*buffer));
      Item last = STACKpop();
      snprintf(buffer, BUFSZ, "(%s %c %s)", STACKpop(), a[i], last);
      STACKpush(buffer);
    }
    if ((a[i] >= '0') && (a[i] <= '9')) {
      char *buffer = malloc(BUFSZ * sizeof(*buffer));
      for (int j = 0; (a[i] >= '0') && (a[i] <= '9'); j++, i++) {
        buffer[j] = a[i];
        buffer[j + 1] = '\0';
      }
      STACKpush(buffer);
    }
  }
  printf("%s\n", STACKpop());
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.15.exe "5 9 8 + 4 6 * * 7 + *"
(5 * (((9 + 8) * (4 * 6)) + 7))

./E04.15.exe "5 9 * 8 7 4 6 + * 2 1 3 * + * + *"
((5 * 9) * (8 + ((7 * (4 + 6)) * (2 + (1 * 3)))))

./E04.15.exe "3 2 5 * 3 * 2 + *"
(3 * (((2 * 5) * 3) + 2))
--------------------------------------------------------------------- */

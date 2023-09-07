/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.3
                      Infix-to-postfix conversion
------------------------------------------------------------------------
This program is another example of a pushdown-stack client. In this
case, the stack contains characters—we assume that Item is defined to be
char (that is, we use a different Item.h file than for Program 4.2). To
convert (A+B) to the postfix form AB+, we ignore the left parenthesis,
convert A to postfix, save the + on the stack, convert B to postfix,
then, on encountering the right parenthesis, pop the stack and output
the +.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Makefiles for the array and linked-list implementations are provided.
The results will of course be the same.

I've included Item_char.h, which is Item.h implemented for char.

For the algorithm to work it's self-evident that the number of closing
parenthesis must equal the number of operators. If we add extra pairs of
parenthesis then the program keeps popping from an empty stack, and if
each operation is not surrounded by parenthesis, then some operators
are never popped.
--------------------------------------------------------------------- */

#include "Item.h"
// #include "Item_char.h"
#include "STACK.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[1];
  int i, N = strlen(a);
  STACKinit(N);
  for (i = 0; i < N; i++) {
    if (a[i] == ')')
      printf("%c ", STACKpop());
    if ((a[i] == '+') || (a[i] == '*'))
      STACKpush(a[i]);
    if ((a[i] >= '0') && (a[i] <= '9'))
      printf("%c ", a[i]);
  }
  printf("\n");
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
P04.03.exe "( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )"
5 9 8 + 4 6 * * 7 + *

P04.03.exe "((5 * 9) * (8 + ((7 * (4 + 6)) * (2 + (1 * 3) ))))"
5 9 * 8 7 4 6 + * 2 1 3 * + * + *

BUGGY OUTPUT:
P04.03.exe "(((3 * (2 + 5 * 3))))"
3 2 5 3 * + * SEGFAULT

BUGGY OUTPUT:
P04.03.exe "3 * (2 * 5 * 3 + 2)"
3 2 5 3 2 +

SHOULD BE:
P04.03.exe "(3 * (((2 * 5) * 3) + 2))"
3 2 5 * 3 * 2 + *
--------------------------------------------------------------------- */

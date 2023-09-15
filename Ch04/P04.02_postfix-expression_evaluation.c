/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.2
                     Postfix-expression evaluation
------------------------------------------------------------------------
This pushdown-stack client reads any postfix expression involving
multiplication and addition of integers, then evaluates the expression
and prints the computed result.
When we encounter operands, we push them on the stack; when we encounter
operators, we pop the top two entries from the stack and push the result
of applying the operator to them. The order in which the two STACKpop()
operations are performed in the expressions in this code is unspecified
in C, so the code for noncommutative operators such as subtraction or
division would be slightly more complicated.
The program assumes that at least one blank follows each integer, but
otherwise does not check the legality of the input at all. The final if
statement and the while loop perform a calculation similar to the C atoi
function, which converts integers from ASCII strings to integers for
calculation. When we encounter a new digit, we multiply the accumulated
result by 10 and add the digit.
The stack contains integers—that is, we assume that Item is defined to
be int in Item.h, and that Item.h is also included in the stack
implementation (see, for example, Program 4.4).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Makefiles for the array and linked-list implementations are provided.
The results will of course be the same.

STACK.h must include Item_int.h, which is Item.h implemented for int.
--------------------------------------------------------------------- */

#include "STACK.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[1];
  int i, N = strlen(a);
  STACKinit(N);
  for (i = 0; i < N; i++) {
    if (a[i] == '+')
      STACKpush(STACKpop() + STACKpop());
    if (a[i] == '*')
      STACKpush(STACKpop() * STACKpop());
    if ((a[i] >= '0') && (a[i] <= '9'))
      STACKpush(0);
    while ((a[i] >= '0') && (a[i] <= '9'))
      STACKpush(10 * STACKpop() + (a[i++] - '0'));
  }
  printf("%d \n", STACKpop());
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./P04.02.exe "5 9 8 * 7 4 6 + * + *"
710

./P04.02.exe "5 9 8 + 4 6 * * 7 + *"
2075

./P04.02.exe "5 9 * 8 7 4 6 + * 2 1 3 * + * + *"
16110
--------------------------------------------------------------------- */

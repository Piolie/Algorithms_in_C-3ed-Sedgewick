/* ---------------------------------------------------------------------
                             EXERCISE 4.12
------------------------------------------------------------------------
Extend your solution to Exercise 4.11 to include the unary operators
- (negation) and $ (square root). Also, modify the abstract stack
machine in Program 4.2 to use floating point. For example, given the
expression (-(-1) + $((-1) * (-1)-(4 * (-1))))/2
your program should print the value 1.618034.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Since this program only works with postfix notation, the input should
be first passed through E04.12_P04.03 to convert from infix to postfix.

Keep in mind that when compiling E04.12_P04.02 (this program), header
Item_float.h must be used in the implementation, and when compiling
E04.12_P04.03, it is header Item_char.h.
--------------------------------------------------------------------- */

#include "STACK.h"
#include <math.h>
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
    if (a[i] == '-') {
      Item last = STACKpop();
      STACKpush(STACKpop() - last);
    }
    if (a[i] == '/') {
      Item last = STACKpop();
      STACKpush(STACKpop() / last);
    }
    if (a[i] == 'r')
      STACKpush(sqrt(STACKpop()));
    if ((a[i] >= '0') && (a[i] <= '9'))
      STACKpush(0);
    while ((a[i] >= '0') && (a[i] <= '9'))
      STACKpush(10 * STACKpop() + (a[i++] - '0'));
  }
  ITEMshow(STACKpop());
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.12_P04.02.exe "0 0 1 - - 0 1 - 0 1 - * 4 0 1 - * - r + 2 /"
1.618034
--------------------------------------------------------------------- */

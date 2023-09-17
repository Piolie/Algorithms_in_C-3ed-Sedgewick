/* ---------------------------------------------------------------------
                             EXERCISE 4.11
------------------------------------------------------------------------
Extend Programs 4.2 and 4.3 to include the - (subtract) and / (divide)
operations.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
We mustn't rush to add code analogous to the existing for the + and *
operations because it won't work correctly. Subtraction and division are
noncommutative operations, and as stated in program 4.2, C doesn't
guarantee the order in which the two STACKpop() operations are
performed. Thus, we have to first pop an operand and store it in a
temporary variable, before calling STACKpush.

I've only included the makefile for the array implementation. Keep in
mind that when compiling E04.11_P04.02 (this program), the concrete type
in Item.h has to be int, while when compiling E04.11_P04.03 it has to be
char.
--------------------------------------------------------------------- */

#include "Item.h"
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
    if (a[i] == '-') {
      Item last = STACKpop();
      STACKpush(STACKpop() - last);
    }
    if (a[i] == '/') {
      Item last = STACKpop();
      STACKpush(STACKpop() / last);
    }
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
./E04.11_P04.02.exe "5 9 8 * 7 4 6 - * - *"
430

./E04.11_P04.02.exe "5 9 8 + 4 6 * * 7 / *"
290

./E04.11_P04.02.exe "5 9 - 8 7 4 6 + * 2 1 3 * + / + *"
-88
--------------------------------------------------------------------- */

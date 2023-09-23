/* ---------------------------------------------------------------------
                             EXERCISE 4.77
------------------------------------------------------------------------
Modify the postfix-evaluation program in Section 4.3 to evaluate post­
fix expressions consisting of arbitrarily long integers, using the ADT
that you developed for Exercise 4.76.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'm modifying P04.02. We have to cheat, like in E04.69, to convince the
stack that our Bigint is an Item.

Each operator or operand must be an argument to the program. This has
the little inconvenience that the character '*' is treated as a wildcard
by the command-line. To make it work I've used 'p' instead.
--------------------------------------------------------------------- */

#include "BIGINT.h" // #include "E04.76_interface.h"
#include "Item.h"   // typedef struct bigint *Item;
#include "STACK.h"  // #include "P04.01_pushdown-stack_ADT_interface.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  STACKinit(atoi(argv[1]));
  for (int i = 2; i < argc; i++) {
    switch (argv[i][0]) {
    case '+':
      STACKpush(BIGINTadd(STACKpop(), STACKpop()));
      break;
    case 'p':
      STACKpush(BIGINTmult(STACKpop(), STACKpop()));
      break;
    default:
      STACKpush(BIGINTinit(argv[i], 0));
      break;
    }
  }
  BIGINTshow(STACKpop());
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.77.exe 10 "9999" "0001" "+"
10000

./E04.77.exe 10 "123" "456" "p"
056088

./E04.77.exe 10 "999999999999999999999999999999999999999999999" \
"000000000000000000000000000000000000000000001" "+"
1000000000000000000000000000000000000000000000

./E04.77.exe 10 "4294967296" "4294967296" "p"
18446744073709551616
--------------------------------------------------------------------- */

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
This program transforms the input so that it can be processed by
E04.12_P04.02.

The minus sign '-' is unary only when preceded by a '('. My solution is
to first push a '0', then the operand and finally the '-'. That way we
avoid having to modify the behavior of the evaluator program for '-'.

I'll use 'r' instead of '$', because bash and powershell use '$' to
escape variable names.

As shown in P04.03, the algorithm has a bug that requires the number of
parenthesis in the input to match the number of operators for it to
work. The input we'll be using is:
  (((-(-1)) + (r(((-1) * (-1)) - (4 * (-1)))))/2)
--------------------------------------------------------------------- */

#include "Item.h"
#include "STACK.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[1];
  int i, N = strlen(a);
  char prev = '(';
  STACKinit(N);
  for (i = 0; i < N; i++) {
    if (a[i] == '(')
      prev = '(';
    if (a[i] == '-') {
      if (prev == '(') {
        printf("%c ", '0');
        prev = '-';
      }
      STACKpush('-');
    }
    if (a[i] == ')') {
      printf("%c ", STACKpop());
      prev = ')';
    }
    if ((a[i] == '+') || (a[i] == '*') || (a[i] == '/') || (a[i] == 'r')) {
      STACKpush(a[i]);
      prev = a[i];
    }
    if ((a[i] >= '0') && (a[i] <= '9')) {
      printf("%c ", a[i]);
      prev = a[i];
    }
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.12_P04.03.exe "(((-(-1)) + (r(((-1) * (-1)) - (4 * (-1)))))/2)"
0 0 1 - - 0 1 - 0 1 - * 4 0 1 - * - r + 2 /
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 4.69
------------------------------------------------------------------------
Modify the postfix-evaluation program in Section 4.3 to evaluate postfix
expressions consisting of complex numbers with integer coefficients,
using the first-class complex numbers ADT in the text (Programs 4.16 and
4.17). For simplicity, assume that the complex numbers all have nonnull
integer coefficients for both real and imaginary parts and are written
with no spaces. For example, your program should print the output 8+4i
when given the input
  1+1i 0+1i + 1-2i * 3+4i + .
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The book kind of put us in an awkward situation at this point, since our
STACK.h and implementations expect data of type Item as defined in its
corresponding header, and nowhere does the COMPLEX.h header file refer
to Item. We can cheat by using a new Item.h like this:
  #include COMPLEX.h
  typedef Complex Item;
  #define ITEMshow(X) {Item T = (X); printf("(%f+%fi)", Re(T), Im(T));}

We have to compile and link with the stack implementation (either E04.67
or E04.68) and the complex number implementation (E04.57_P04.16).

I've not bothered with unary operators or error handling. As long as the
input is formatted as above and the real parts are positive, it works.
--------------------------------------------------------------------- */

#include "Item.h"
#include "STACK.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[1];
  int i, N = strlen(a);
  Stack stack = STACKinit(N);
  for (i = 0; i < N; i++) {
    if ((a[i] == '+') && (a[i - 1] == ' ')) {
      STACKpush(stack, COMPLEXadd(STACKpop(stack), STACKpop(stack)));
    }
    if ((a[i] == '*') && (a[i - 1] == ' ')) {
      STACKpush(stack, COMPLEXmult(STACKpop(stack), STACKpop(stack)));
    }
    if ((a[i] >= '0') && (a[i] <= '9')) {
      float re = 0.0;
      float im = 0.0;
      float sign = 1.0;
      while ((a[i] >= '0') && (a[i] <= '9'))
        re = 10 * re + (a[i++] - '0');
      if (a[i] == '-')
        sign = -1.0;
      i++;
      while ((a[i] >= '0') && (a[i] <= '9'))
        im = 10 * im + (a[i++] - '0');
      STACKpush(stack, COMPLEXinit(re, sign * im));
    }
  }
  ITEMshow(STACKpop(stack));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.69.exe "1+1i 0+1i + 1-2i * 3+4i +"
(8.000000+4.000000i)

./E04.69.exe "0-1i 0+1i + 1-2i + 1+2i +"
(2.000000+0.000000i)
--------------------------------------------------------------------- */

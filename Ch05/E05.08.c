/* ---------------------------------------------------------------------
                              EXERCISE 5.8
------------------------------------------------------------------------
Give the figure corresponding to Figure 5.3 for the result of recursive
prefix-expression evaluation for the input + * * 12 12 12 144.
--------------------------------------------------------------------- */

#include <stdio.h>

static char *a;
static int i = 0;
static int depth = 0;

int eval(void) {
  depth++;
  int x = 0;
  while (a[i] == ' ')
    i++;
  printf("%*seval() %s\n", depth, "", &a[i]);
  if (a[i] == '+') {
    i++;
    int e1 = eval();
    int e2 = eval();
    printf("%*sreturn %d = %d + %d\n", depth + 1, "", e1 + e2, e1, e2);
    depth--;
    return e1 + e2;
  }
  if (a[i] == '*') {
    i++;
    int e1 = eval();
    int e2 = eval();
    printf("%*sreturn %d = %d * %d\n", depth + 1, "", e1 * e2, e1, e2);
    depth--;
    return e1 * e2;
  }
  while ((a[i] >= '0') && (a[i] <= '9'))
    x = 10 * x + (a[i++] - '0');
  depth--;
  return x;
}

int main(int argc, char *argv[]) {
  (void)argc;
  a = argv[1];
  eval();
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing figure 5.3:
./E05.08.exe "* + 7 * * 4 6 + 8 9 5"
 eval() * + 7 * * 4 6 + 8 9 5
  eval() + 7 * * 4 6 + 8 9 5
   eval() 7 * * 4 6 + 8 9 5
   eval() * * 4 6 + 8 9 5
    eval() * 4 6 + 8 9 5
     eval() 4 6 + 8 9 5
     eval() 6 + 8 9 5
     return 24 = 4 * 6
    eval() + 8 9 5
     eval() 8 9 5
     eval() 9 5
     return 17 = 8 + 9
    return 408 = 24 * 17
   return 415 = 7 + 408
  eval() 5
  return 2075 = 415 * 5

./E05.08.exe "+ * * 12 12 12 144"
 eval() + * * 12 12 12 144
  eval() * * 12 12 12 144
   eval() * 12 12 12 144
    eval() 12 12 12 144
    eval() 12 12 144
    return 144 = 12 * 12
   eval() 12 144
   return 1728 = 144 * 12
  eval() 144
  return 1872 = 1728 + 144
--------------------------------------------------------------------- */

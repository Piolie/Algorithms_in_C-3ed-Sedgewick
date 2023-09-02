/* ---------------------------------------------------------------------
                             EXERCISE 3.64
------------------------------------------------------------------------
Modify Program 3.17 to process input strings individually (allocate
memory for each string after reading it from the input). You can assume
that all strings have less than 100 characters.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This program makes correct use of the qsort function, by first supplying
it a compare function with the correct signature (with consts). Inside
compare, the void pointers are safely and correctly casted to pointer to
const pointer to char, then dereferenced and input to strcmp. That's why
the compiler does not raise the warnings of Program 3.17. See the
respective references there.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nmax 1000
#define MAX_LENGTH 100

int compare(const void *i, const void *j) {
  return strcmp(*(char *const *)i, *(char *const *)j);
}
int main(void) {
  char buf[MAX_LENGTH];
  int i, N, len;
  char *a[Nmax];
  for (N = 0; N < Nmax; N++) {
    if (scanf("%s", buf) == EOF)
      break;
    len = strlen(buf);
    a[N] = malloc((len + 1) * sizeof(*a[N]));
    strcpy(a[N], buf);
  }
  qsort(a, N, sizeof(char *), compare);
  for (i = 0; i < N; i++)
    printf("%s\n", a[i]);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.64.exe
this
is
a
test
string
^Z
a
is
string
test
this

E03.64.exe
This
is
yet
another
string
to
test
^Z
This
another
is
string
test
to
yet
--------------------------------------------------------------------- */

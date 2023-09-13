/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 3.17
                      Sorting an array of strings
------------------------------------------------------------------------
This program illustrates an important string-processing function:
rearranging a set of strings into sorted order. We read strings into a
buffer large enough to hold them all, maintaining a pointer to each
string in an array, then rearrange the pointers to put the pointer to
the smallest string in the first position in the array, the pointer to
the second smallest string in the second position in the array, and so
forth.

The qsort library function that actually does the sort takes four
arguments: a pointer to the beginning of the array, the number of
objects, the size of each object, and a comparison function. It achieves
independence from the type of object being sorted by blindly rearranging
the blocks of data that represent objects (in this case string pointers)
and by using a comparison function that takes pointers to void as
argument. This code casts these back to type pointer to pointer to char
for strcmp. To actually access the first character in a string for a
comparison, we dereference three pointers: one to get the index (which
is a pointer) into our array, one to get the pointer to the string
(using the index), and one to get the character (using the pointer).

We use a different method to achieve type independence for our sorting
and searching functions (see Chapters 4 and 6).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The compiler complains that the arguments of the compare function are
incompatible with what qsort expects:
    warning: passing argument 4 of 'qsort' from incompatible pointer
    type [-Wincompatible-pointer-types]
        qsort(a, N, sizeof(char*), compare);
                                   ^~~~~~~
                                   |
                                   int (*)(void *, void *)
    note: expected 'int (*)(const void *, const void *)' but argument is
    of type 'int (*)(void *, void *)'

The correct usage of qsort for an array of strings is explained in the
the following comp.lang.c FAQ question:
    [Question 13.8](http://www.c-faq.com/lib/qsort1.html).
Also interesting are the discussions in the following SO question:
    [What are the parameters in this C qsort function
call?](https://stackoverflow.com/questions/2228695/) and specially the following
comp.lang.c FAQ question: [Question 13.9](http://www.c-faq.com/lib/qsort2.html).

See exercise E03.64 for an implementation that uses qsort correctly.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nmax 1000
#define Mmax 10000

char buf[Mmax];
int M = 0;
int compare(void *i, void *j) { return strcmp(*(char **)i, *(char **)j); }
int main(void) {
  int i, N;
  char *a[Nmax];
  for (N = 0; N < Nmax; N++) {
    a[N] = &buf[M];
    if (scanf("%s", a[N]) == EOF)
      break;
    M += strlen(a[N]) + 1;
  }
  qsort(a, N, sizeof(char *), compare);
  for (i = 0; i < N; i++)
    printf("%s\n", a[i]);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
P03.17_Sorting_an_array_of_strings.exe
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

P03.17_Sorting_an_array_of_strings.exe
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

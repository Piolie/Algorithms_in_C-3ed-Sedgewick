/* ---------------------------------------------------------------------
                             EXERCISE 3.58
------------------------------------------------------------------------
Suppose that memory for strings is individually allocated. Write
versions of strcpy and strcat that allocate memory and return a pointer
to the new string for the result.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The context for this problem is given in page 114:
    Often, memory allocation is a less severe problem when we are
    working with strings than it might first appear, because we work
    with pointers to the strings, rather that with the characters
    themselves. Indeed, we do not normally assume in C code that all
    strings sit in individually allocated chunks of memory. We tend to
    assume that each string sits in memory of indeterminate allocation,
    just big enough for the string and its termination character. We
    must be very careful to ensure adequate allocation when we are
    performing operations that build or lengthen strings.

By "individually allocated" I assume that the allocated memory is
_exactly_ the size of the string plus its termination character. This
isn't good programming practice. Functions shouldn't handle memory. That
is the responsibility of the application that uses them. /rant

I could think of two approaches:
    1. Allocating the memory first and then simply calling the original
    srtcpy and strcat.
    2. Implementing the whole functions ourselves.

--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpy_ind_alloc1(const char *src)
{
    char *dest = malloc((strlen(src) + 1)*sizeof(*dest));
    return strcpy(dest, src);
}

char *strcpy_ind_alloc2(const char *src)
{
    char *dest = malloc((strlen(src) + 1)*sizeof(*dest));
    char *ret = dest;
    while ((*dest++ = *src++));
    return ret;
}

char *strcat_ind_alloc1(const char *a, const char *b)
{
    char *dest = malloc((strlen(a) + strlen(b) + 1)*sizeof(*dest));
    dest[0] = 0;
    return strcat(strcat(dest, a), b);
}

char *strcat_ind_alloc2(const char *a, const char *b)
{
    char *dest = malloc((strlen(a) + strlen(b) + 1)*sizeof(*dest));
    char *ret = dest;
    while ((*dest++ = *a++));
    dest--;
    while ((*dest++ = *b++));
    return ret;
}

int main(void)
{
    char s1[] = "String 1.\0ignore string";
    char s2[] = "String 2.";
    printf("strcpy_ind_alloc1: %s\n", strcpy_ind_alloc1(s1));
    printf("strcpy_ind_alloc2: %s\n", strcpy_ind_alloc2(s1));
    printf("strcat_ind_alloc1: %s\n", strcat_ind_alloc1(s1, s2));
    printf("strcat_ind_alloc2: %s\n", strcat_ind_alloc2(s1, s2));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.58.exe
strcpy_ind_alloc1: String 1.
strcpy_ind_alloc2: String 1.
strcat_ind_alloc1: String 1.String 2.
strcat_ind_alloc2: String 1.String 2.

--------------------------------------------------------------------- */

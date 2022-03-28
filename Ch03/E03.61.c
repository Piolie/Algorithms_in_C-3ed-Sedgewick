/* ---------------------------------------------------------------------
                             EXERCISE 3.61
------------------------------------------------------------------------
Implement a pointer version of Program 3.15.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#define N 10000
int main(int argc, char *argv[])
{
    (void)argc;
    int i;
    char *a = malloc(N*sizeof(*a)), *p = argv[1];
    char *temp_a = a, *temp_p = p;
    while ((*temp_a++ = getchar()) != EOF);
    *--temp_a = 0;
    i = 0;
    while (*(temp_a = a++))
    {
        temp_p = p;
        while (*temp_p)
            if (*temp_a++ != *temp_p++)
                break;
        if (*temp_p == 0) printf("%d ", i);
        i++;
    }
    printf("\n");
  }

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
I had to run this program from the windows console (or PowerShell).
There, we can signal the end of the input by pressing Ctrl+Z in a new
line and pressing Enter. This outputs ^Z and makes getchar() return EOF.
In mintty the equivalent is supposedly Ctrl+D, but it wouldn't work for
me.
------------------------------------------------------------------------

E03.61.exe long
this is a very long string
^Z
15

E03.61.exe long
long
^Z
0

E03.61.exe long
 long
^Z
1

E03.61.exe long
lang
^Z

--------------------------------------------------------------------- */

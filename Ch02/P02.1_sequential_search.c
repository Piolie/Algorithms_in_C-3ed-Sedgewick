/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 2.1
------------------------------------------------------------------------
This function checks whether the number v is among a previously stored
set of numbers in a[l], a[l+1], ..., a[r], by comparing against each
number sequentially, starting at the beginning. If we reach the end
without finding the number sought, then we return the value -1.
Otherwise, we return the index of the array position containing the
number.
--------------------------------------------------------------------- */

#include <stdio.h>

#define N 10

int search(int a[], int v, int l, int r)
{
    int i;
    for (i = l; i <= r; i++)
        if (v == a[i])
            return i;
    return -1;
}

int main(void)
{
    int a[N] = {0, 3, 5, 6, 7, 8}, v, l, r;

    printf("a[] = ");
    for (int i = 0; i < N; i++)
        printf("%d, ", a[i]);
    printf("\n");
    v = 2; l = 0; r = 9;
    printf("v = %d, l = %d, r = %d, index = %d\n", v, l, r, search(a, v, l, r));
    v = 3; l = 0; r = 9;
    printf("v = %d, l = %d, r = %d, index = %d\n", v, l, r, search(a, v, l, r));
    v = 3; l = 2; r = 9;
    printf("v = %d, l = %d, r = %d, index = %d\n", v, l, r, search(a, v, l, r));

}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
a[] = 0, 3, 5, 6, 7, 8, 0, 0, 0, 0,
v = 2, l = 0, r = 9, index = -1
v = 3, l = 0, r = 9, index = 1
v = 3, l = 2, r = 9, index = -1

--------------------------------------------------------------------- */

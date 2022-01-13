/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
        PROGRAM 1.1 QUICK-FIND SOLUTION TO CONNECTIVITY PROBLEM
------------------------------------------------------------------------
This program reads a sequence of pairs of nonnegative integers less than
N from standard input (interpreting the pair p q to mean "connect object
p to object q") and prints out pairs representing objects that are not
yet connected. It maintains an array id that has an entry for each
object, with the property that id[p] and id[q] are equal if and only if
p and q are connected. For simplicity, we define N as a compile-time
constant. Alternatively, we could take it from the input and allocate
the id array dynamically (see Section 3.2).
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10000
int main(void)
{
    int i, p, q, t, id[N];
    for (i = 0; i < N; i++)
        id[i] = i;
    while (scanf("%d %d", &p, &q) == 2)
    {
        if (id[p] == id[q])
            continue;
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t)
                id[i] = id[q];
        printf(" %d %d\n", p, q);
    }
}

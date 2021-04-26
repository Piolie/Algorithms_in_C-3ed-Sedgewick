/* ---------------------------------------------------------------------
                              EXERCISE 1.8
------------------------------------------------------------------------
Do Exercise 1.4, but use the weighted quick-union algorithm with path
compression by halving (Program 1.4).
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10000

void print_id(int id[])
{
    printf("id = ");
    for (int i = 0; i < 10; i++)
        printf("%d ", id[i]);
    printf("...\n");
}

int main(void)
{
    int i, j, p, q, id[N], sz[N], access_count;
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%d %d", &p, &q) == 2)
    {
        for (i = p, access_count++; i != id[i]; i = id[i])
        {
            access_count += 3;
            int t = i;
            i = id[id[t]];
            id[t] = i;
        }
        for (j = q, access_count++; j != id[j]; j = id[j])
        {
            access_count += 3;
            int t = j;
            j = id[id[t]];
            id[t] = j;
        }
        if (i == j)
            continue;
        access_count += 2;
        if (sz[i] < sz[j])
        {
            access_count++;
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            access_count++;
            id[j] = i;
            sz[i] += sz[j];
        }
        print_id(id);
        printf(" %d %d\n", p, q);
        printf("Number of accesses = %d\n", access_count);
    }
}

/* ---------------------------------------------------------------------
Notes:
    - only shows first 10 entries of id;
    - the access counter ignores the initialization and print_id steps;
    - the access counter includes accesses to sz;
    - lvalue assignments are _not_ considered accesses:
        id[i] = id[q] -> 1 access;
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
0 2
id = 0 1 0 3 4 5 6 7 8 9 ...
 0 2
Number of accesses = 5
1 4
id = 0 1 0 3 1 5 6 7 8 9 ...
 1 4
Number of accesses = 10
2 5
id = 0 1 0 3 1 0 6 7 8 9 ...
 2 5
Number of accesses = 18
3 6
id = 0 1 0 3 1 0 3 7 8 9 ...
 3 6
Number of accesses = 23
0 4
id = 0 0 0 3 1 0 3 7 8 9 ...
 0 4
Number of accesses = 31
6 0
id = 0 0 0 0 1 0 3 7 8 9 ...
 6 0
Number of accesses = 39
1 3

--------------------------------------------------------------------- */

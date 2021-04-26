/* ---------------------------------------------------------------------
                              EXERCISE 1.17
------------------------------------------------------------------------
Answer Exercise 1.4, but using the weighted quick-union algorithm with
full path compression (Exercise 1.16).
--------------------------------------------------------------------- */

#include <stdio.h>
#define N 10000

void print_id(int id[])
{
    printf("id = ");
    for (int i = 0; i < 20; i++)
        printf("%d ", id[i]);
    printf("...\n");
}

int access_count = 0; /* made it global so it can be changed in find*/

int find(int id[], int i)
{
    access_count++;
    if (i == id[i])
        return i;
    return id[i] = find(id, id[i]);
    
}

int main(void)
{
    int i, j, p, q, id[N], sz[N];
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%d %d", &p, &q) == 2)
    {
        i = find(id, p);
        j = find(id, q);
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
Number of accesses = 16  
3 6
id = 0 1 0 3 1 0 3 7 8 9 ...
 3 6
Number of accesses = 21  
0 4
id = 0 0 0 3 1 0 3 7 8 9 ...
 0 4
Number of accesses = 27  
6 0
id = 0 0 0 0 1 0 3 7 8 9 ...
 6 0
Number of accesses = 33
1 3

--------------------------------------------------------------------- */

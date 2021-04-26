/* ---------------------------------------------------------------------
                              EXERCISE 1.16
------------------------------------------------------------------------
Show how to modify Program 1.3 to implement full path compression,
where we complete each union operation by making every node that we
touch point to the root of the new tree.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
To implement path compression, we have to set the id[] entry
corresponding to each node encountered along the way to link directly to
the root.

Since we don't yet know what the root is, we could:
    - save the root once it's found and re-visit all the previous nodes,
        setting them all to root. This requires more variables and extra
        steps to be done the find/union parts; or
    - another, cleaner alternative is to factor the for finding loops
        into a recursive function that sets all visited nodes at once
        when it returns. I'll go with that.

(I'm not claiming these are the only possible solutions, just the ones I
could think of/find.)
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

int find(int id[], int i)
{
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
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        print_id(id);
        printf(" %d %d\n", p, q);
    }
}
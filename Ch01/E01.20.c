/* ---------------------------------------------------------------------
                              EXERCISE 1.20
------------------------------------------------------------------------
Modify Program 1.3 to use the height of the trees (longest path from
any node to the root), instead of the weight, to decide whether to set
id[i] = j or id[j] = i. Run empirical studies to compare this variant
with Program 1.3.

------------------------------------------------------------------------
                    HEIGHTED VERSION OF QUICK UNION
------------------------------------------------------------------------
This program keeps an additional array height[] for the purpose of
maintaining, for each object with id[i] == i, the height of the
associated tree, so that the union operation can link the shorter of the
two specified trees to the taller, thus preventing the growth of long
paths in the trees.

------------------------------------------------------------------------
The only time the height of the resulting union grows is when the trees
are the same height:

trees of different heights:     | trees of the same height:
                                |
    T1  T2     T1+T2            |      T1  T2     T1+T2
                                |
    0   4       0               |      0   4       0
    |   |       |\              |      |   |       |\
    1   5       1 4             |      1   5       1 4
    |   |       | |             |      |   |       | |
    2   6       2 5             |      2   6       2 5
    |           | |             |      |   |       | |
    3           3 6             |      3   7       3 6
                                |                    |
                                |                    7

I owe you the empirical studies.
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

int main(void)
{
    int i, j, p, q, id[N], height[N], max_height = 0;
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        height[i] = 0; /* each node is its own root */
    }
    while (scanf("%d %d", &p, &q) == 2)
    {
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j)
            continue;
        if (height[i] < height[j])
            id[i] = j;
        else if (height[i] > height[j])
            id[j] = i;
        else
        {
            id[j] = i;   /* or id[i] = j, it's the same... */
            height[i]++; /* though this line would become height[j]++ */
            max_height = (height[i] > max_height) ? height[i] : max_height;
        }
        print_id(id);
        printf(" %d %d\n", p, q);
        printf("max_height = %d\n", max_height);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------

id = 0 0 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ...
 0 1
max_height = 1
id = 0 0 2 2 4 5 6 7 8 9 10 11 12 13 14 15 ...
 2 3
max_height = 1
id = 0 0 2 2 4 4 6 7 8 9 10 11 12 13 14 15 ...
 4 5
max_height = 1
id = 0 0 2 2 4 4 6 6 8 9 10 11 12 13 14 15 ...
 6 7
max_height = 1
id = 0 0 2 2 4 4 6 6 8 8 10 11 12 13 14 15 ...
 8 9
max_height = 1
id = 0 0 2 2 4 4 6 6 8 8 10 10 12 13 14 15 ...
 10 11
max_height = 1
id = 0 0 2 2 4 4 6 6 8 8 10 10 12 12 14 15 ...
 12 13
max_height = 1
id = 0 0 2 2 4 4 6 6 8 8 10 10 12 12 14 14 ...
 14 15
max_height = 1
id = 0 0 0 2 4 4 6 6 8 8 10 10 12 12 14 14 ...
 0 2
max_height = 2
id = 0 0 0 2 4 4 4 6 8 8 10 10 12 12 14 14 ...
 4 6
max_height = 2
id = 0 0 0 2 4 4 4 6 8 8 8 10 12 12 14 14 ...
 8 10
max_height = 2
id = 0 0 0 2 4 4 4 6 8 8 8 10 12 12 12 14 ...
 12 14
max_height = 2
id = 0 0 0 2 0 4 4 6 8 8 8 10 12 12 12 14 ...
 0 4
max_height = 3
id = 0 0 0 2 0 4 4 6 8 8 8 10 8 12 12 14 ...
 8 12
max_height = 3
id = 0 0 0 2 0 4 4 6 0 8 8 10 8 12 12 14 ...
 0 8
max_height = 4

--------------------------------------------------------------------- */

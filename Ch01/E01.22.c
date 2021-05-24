/* ---------------------------------------------------------------------
                              EXERCISE 1.22
------------------------------------------------------------------------
Modify Program 1.4 to generate random pairs of integers between 0 and
N - 1 instead of reading them from standard input, and to loop until
N - 1 union operations have been performed. Run your program for
N = 10^3, 10^4, 10^5 and 10^6 and print out the total number of edges
generated for each value of N.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
It seems to me that what the problem is asking it's not very clear:
after N - 1 effective union operations, all nodes will be connected and
and the number of edges will of course be N - 1.
I'll instead loop until N - 1 unions are performed and print the number
of _attempts_ made. I'll also do 100 runs and take the average. For 10^6
elements, this can take a couple minutes.
Some C programming notes:
    - We have to use pointers, with malloc and free, because for
    N = 10^6 the stack is not enough to work with id and sz.
    - rand() returns integers in the range [0, RAND_MAX], which in my
    system is [0, 32767]. Since we need numbers in [0, N-1], we can
    use the llrand function from https://stackoverflow.com/a/28116032.
    I shortened the mask so that the return value fits in 31 bits.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000
#define RUNS 100

unsigned long long llrand(void)
{
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0x7FFFFFFFULL;
}

int main(void)
{
    int total = 0;
    srand((unsigned int) time(NULL));
    for (int run=0; run < RUNS; run++)
    {
        int i, j, p, q, *id, *sz, attempts, union_counter;

        id = malloc(N*sizeof(int));
        sz = malloc(N*sizeof(int));

        union_counter = 0;
        attempts = 0;
        for (i = 0; i < N; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
        while (union_counter < N - 1)
        {
            attempts++;
            p = llrand() % N;
            q = llrand() % N;
            for (i = p; i != id[i]; i = id[i])
            {
                int t = i;
                i = id[id[t]];
                id[t] = i;
            }
            for (j = q; j != id[j]; j = id[j])
            {
                int t = j;
                j = id[id[t]];
                id[t] = j;
            }
            if (i == j)
                continue;
            union_counter++;
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
        }

        free(id);
        free(sz);
        total += attempts;
    }
    printf("average attempts = %e\n", (double)total/RUNS);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
For each value of N, the programs does RUNS runs and prints the average:

For N = 10^3: attempts = 3695
For N = 10^4: attempts = 48764
For N = 10^5: attempts = 601638
For N = 10^6: attempts = 7484813

--------------------------------------------------------------------- */


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
It seems to me that what the problem is asking is not very clear:
after N - 1 effective union operations, all nodes will be connected and
the number of edges will of course be N - 1.
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
    for(int N = 1000; N <= 1000000; N*=10)
    {
        int total = 0;
        for (int run = 0; run < RUNS; run++)
        {
            int i, j, p, q, *id, *sz, attempts, union_counter;

            id = malloc(N*sizeof(*id));
            sz = malloc(N*sizeof(*sz));

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
        printf("average attempts for N = %d: %.f\n", N, (double)total/RUNS);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
average attempts for N = 1000: 3662
average attempts for N = 10000: 48194
average attempts for N = 100000: 604954
average attempts for N = 1000000: 7103127

--------------------------------------------------------------------- */

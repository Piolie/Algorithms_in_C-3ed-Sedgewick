/* ---------------------------------------------------------------------
                              EXERCISE 1.22
------------------------------------------------------------------------
Modify your program from Exercise 1.22 to plot the number of edges
needed to connect N items, for 100 <= N <= 1000.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_MIN 100
#define N_MAX 1001
#define RUNS 100

unsigned long long llrand()
{
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

void print_attempts(int attempts, int N)
{
    int scale = 100; /* to scale the number of stars printed */
    printf("%d ", N);
    for (int i = 0; i < attempts/scale; i++)
        printf("*");
    printf("\n");
}

int main(void)
{
    srand((unsigned int) time(NULL));
    for(int N = N_MIN; N < N_MAX; N++)
    {
        int total = 0;
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
        print_attempts(total/RUNS, N);
    }
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

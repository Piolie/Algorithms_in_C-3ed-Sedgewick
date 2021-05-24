/* ---------------------------------------------------------------------
                              EXERCISE 2.49
------------------------------------------------------------------------
Write a driver program that generates M random integers and puts them
in an array, then counts the number of N random integers that matches
one of the numbers in the array, using sequential search. Run your
program for M = 10, 100, and 1000 and N = 10, 100, and 1000.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The problem statement does not specify the range of the integers. I'll
assume *four* digit integers.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_RANDOM 999  /* 10^4 - 1 */

/* From https://stackoverflow.com/a/28116032 */
unsigned long long llrand(void)
{
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

int search(unsigned long array[], int value, int left, int right)
{
    int i;
    for (i = left; i <= right; i++)
        if (value == array[i])
            return i;
    return -1;
}

int main(void)
{
    srand((unsigned int) time(NULL));

    int counts[] = {10, 100, 1000};
    size_t size = (sizeof counts)/(sizeof counts[0]);

    for (size_t idx_N = 0; idx_N < size; idx_N++)
    {
        printf("N = %d:\n", counts[idx_N]);
        unsigned long *N_numbers = malloc(counts[idx_N] * sizeof *N_numbers);
        for (int i = 0; i < size; i++)
            N_numbers[i] = llrand() % MAX_RANDOM;

        for (size_t idx_M = 0; idx_M < size; idx_M++)
        {
            int matches = 0;
            for (int j = 0; j < counts[idx_M]; j++)
            {
                unsigned long M = llrand() % MAX_RANDOM;
                if (search(N_numbers, M, 0, size-1) != -1)
                    matches++;
            }

            printf("\tM = %d, matches = %d\n", counts[idx_M], matches);
        }
        free(N_numbers);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
N = 10:
        M = 10, matches = 0
        M = 100, matches = 0
        M = 1000, matches = 4
N = 100:
        M = 10, matches = 0
        M = 100, matches = 0
        M = 1000, matches = 4
N = 1000:
        M = 10, matches = 0
        M = 100, matches = 1
        M = 1000, matches = 2

--------------------------------------------------------------------- */

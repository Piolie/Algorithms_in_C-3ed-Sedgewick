/* ---------------------------------------------------------------------
                              EXERCISE 2.42
------------------------------------------------------------------------
Solve the recurrence
    C_N = a*C_(N/2), for N >= 2 with C_1 = 1
when N is a power of 2.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
N = 2^n

C_N = C_(2^n)
    = a*C_(2^n/2)
    = a*C_(2^(n-1))
    = a*(a*C_(2^(n-2)))
    = a^2*(a*C_(2^(n-3)))
    = ...
    = a^n*(C_(2^(n-n)))
    = a^n*(C_1)
    = a^n

------------------------------------------------------------------------
We would have to apply induction to formally prove it.

--------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>

unsigned int C_N(unsigned int a, unsigned int N)
{
    if(N == 1)
        return 1;

    return a*C_N(a, N/2);
}

unsigned int C_2pown_formula(unsigned int a, unsigned int n)
{
    return (unsigned int)pow(a, n);
}

int main(void)
{
    printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
    printf("----------------------------------------------\n");
    unsigned int a = 3;
    unsigned int N, n;
    for (N = 1, n = 0; N < 100000; n++, N = (unsigned int)(exp2(n)))
    {
        unsigned int CN_recurrence = C_N(a, N);
        unsigned int CN_formula = C_2pown_formula(a, n);
        int equal = (CN_recurrence == CN_formula);
        printf("%u\t%u\t\t%u\t\t%s\n", N, CN_recurrence, CN_formula, equal ? "TRUE" : "FALSE");
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
N       C_N (rec.)      C_N (form.)     Equal?
----------------------------------------------
1       1               1               TRUE
2       3               3               TRUE
4       9               9               TRUE
8       27              27              TRUE
16      81              81              TRUE
32      243             243             TRUE
64      729             729             TRUE
128     2187            2187            TRUE
256     6561            6561            TRUE
512     19683           19683           TRUE
1024    59049           59049           TRUE
2048    177147          177147          TRUE
4096    531441          531441          TRUE
8192    1594323         1594323         TRUE
16384   4782969         4782969         TRUE
32768   14348907        14348907        TRUE
65536   43046721        43046721        TRUE

--------------------------------------------------------------------- */

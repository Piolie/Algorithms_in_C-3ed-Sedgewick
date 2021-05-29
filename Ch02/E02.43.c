/* ---------------------------------------------------------------------
                              EXERCISE 2.43
------------------------------------------------------------------------
Solve the recurrence
    C_N = (C_(N/2))^2, for N >= 2 with C_1 = 1
when N is a power of 2.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
N = 2^n

C_N = C_(2^n)
    = (C_(2^n/2))^2
    = (C_(2^(n-1)))^2
    = ((C_(2^(n-2)))^2)^2
    = (C_(2^(n-2)))^4
    = (C_(2^(n-3)))^8
    = ...
    = (C_(2^(n-n)))^(2^n)
    = (C_1)^(2^n)
    = 1^(2^n)
    = 1

------------------------------------------------------------------------
We would have to apply induction to formally prove it.
(This one is easy.)

--------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>

unsigned int C_N(unsigned int N)
{
    if(N == 1)
        return 1;

    return (unsigned int)pow(C_N(N/2), 2);
}

unsigned int C_2pown_formula(unsigned int n)
{
    return 1;
}

int main(void)
{
    printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
    printf("----------------------------------------------\n");
    unsigned int N, n;
    for (N = 1, n = 0; N < 100000; n++, N = (unsigned int)(exp2(n)))
    {
        unsigned int CN_recurrence = C_N(N);
        unsigned int CN_formula = C_2pown_formula(n);
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
2       1               1               TRUE
4       1               1               TRUE
8       1               1               TRUE
16      1               1               TRUE
32      1               1               TRUE
64      1               1               TRUE
128     1               1               TRUE
256     1               1               TRUE
512     1               1               TRUE
1024    1               1               TRUE
2048    1               1               TRUE
4096    1               1               TRUE
8192    1               1               TRUE
16384   1               1               TRUE
32768   1               1               TRUE
65536   1               1               TRUE

--------------------------------------------------------------------- */

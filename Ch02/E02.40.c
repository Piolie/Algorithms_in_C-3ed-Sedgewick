/* ---------------------------------------------------------------------
                              EXERCISE 2.40
------------------------------------------------------------------------
Solve the recurrence
    C_N = C_(N/2) + N^2, for N >= 2 with C_1 = 0
when N is a power of 2.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
N = 2^n

C_N = C_(2^n)
    = C_(2^n/2) + (2^n)^2
    = C_(2^(n-1)) + 2^(2n)
    = C_(2^(n-1)/2) + (2^(n-1))^2 + 2^(2n)
    = C_(2^(n-2)) + 2^(2(n-1)) + 2^(2n)
    = ...
    = C_(2^(n-n)) + 2^(2*1) + 2^(2*2) + ... + 2^(2(n-1)) + 2^(2n)
    = C_1 + 2^(2*1) + 2^(2*2) + ... + 2^(2(n-1)) + 2^(2n)
    =       2^(2*1) + 2^(2*2) + ... + 2^(2(n-1)) + 2^(2n)

      k=n
      ---
    = \   2^(2k)
      /
      ---
      k=1

------------------------------------------------------------------------
We would have to apply induction to formally prove it.

--------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>

unsigned int C_N(unsigned int N)
{
    if(N == 1)
        return 0;

    return C_N(N/2) + N*N;
}

unsigned int C_2pown_formula(unsigned int n)
{
    unsigned int result = 0;
    for (unsigned int i=1; i < n+1; i++)
        result += (unsigned int)(exp2(2*i));

    return result;
}

int main(void)
{
    printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
    printf("----------------------------------------------\n");
    unsigned int N, n;
    for (N = 1, n = 0; N < 65; n++, N = (unsigned int)(exp2(n)))
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
1       0               0               TRUE
2       4               4               TRUE
4       20              20              TRUE
8       84              84              TRUE
16      340             340             TRUE
32      1364            1364            TRUE
64      5460            5460            TRUE

--------------------------------------------------------------------- */

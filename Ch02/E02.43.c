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

unsigned C_N(unsigned N)
{
    if(N == 1)
        return 1;

    return (unsigned)pow(C_N(N/2), 2);
}

unsigned C_2pown_formula(unsigned n)
{
    return 1;
}

int main(void)
{
    printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
    printf("----------------------------------------------\n");
    unsigned N, n;
    for (N = 1, n = 0; N < 100000; n++, N = (unsigned)(exp2(n)))
    {
        unsigned CN_recurrence = C_N(N);
        unsigned CN_formula = C_2pown_formula(n);
        int equal = (CN_recurrence == CN_formula);
        printf("%u\t%u\t\t%u\t\t%d\n", N, CN_recurrence, CN_formula, equal);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
N       C_N (rec.)      C_N (form.)     Equal?
----------------------------------------------
1       1               1               1
2       1               1               1
4       1               1               1
8       1               1               1
16      1               1               1
32      1               1               1
64      1               1               1
128     1               1               1
256     1               1               1
512     1               1               1
1024    1               1               1
2048    1               1               1
4096    1               1               1
8192    1               1               1
16384   1               1               1
32768   1               1               1
65536   1               1               1

--------------------------------------------------------------------- */

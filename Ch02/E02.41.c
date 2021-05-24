/* ---------------------------------------------------------------------
                              EXERCISE 2.41
------------------------------------------------------------------------
Solve the recurrence
    C_N = C_(N/a) + 1, for N >= 2 with C_1 = 0
when N is a power of a.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
N = a^n

C_N = C_(a^n)
    = C_(a^n/a) + 1
    = C_(a^(n-1)) + 1
    = C_(a^(n-1)/a) + 1 + 1
    = C_(a^(n-2)) + 1 + 1
    = ...
    = C_(a^(n-n)) + 1 + 1 + ... + 1 + 1
    = C_1 + n
    = n

------------------------------------------------------------------------

We would have to apply induction to formally prove it.

--------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>

unsigned C_N(unsigned a, unsigned N)
{
    if(N == 1)
        return 0;

    return C_N(a, N/a) + 1;
}

unsigned C_apown_formula(unsigned n)
{
    return n;
}

int main(void)
{
    printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
    printf("----------------------------------------------\n");
    unsigned a = 7;
    unsigned N, n;
    for (N = 1, n = 0; N < 100000; n++, N = (unsigned)(pow(a, n)))
    {
        unsigned CN_recurrence = C_N(a, N);
        unsigned CN_formula = C_apown_formula(n);
        int equal = (CN_recurrence == CN_formula);
        printf("%u\t%u\t\t%u\t\t%d\n", N, CN_recurrence, CN_formula, equal);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
N       C_N (rec.)      C_N (form.)     Equal?
----------------------------------------------
1       0               0               1
7       1               1               1
49      2               2               1
343     3               3               1
2401    4               4               1
16807   5               5               1

--------------------------------------------------------------------- */

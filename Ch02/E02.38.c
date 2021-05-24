/* ---------------------------------------------------------------------
                              EXERCISE 2.38
------------------------------------------------------------------------
Give a table of the values of C_N in Formula 2.4 for 1 <= N <= 32, for
the following three cases: (i) interpret N/2 to mean floor[N/2];
(ii) interpret N/2 to mean ceil[N/2]; (iii) interpret 2C_(N/2) to mean
C_floor[N/2] + C_ceil[N/2].
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Formula 2.4:
    C_N = 2C_(N/2) + N, for N <= 2 with C_1 = 0.

--------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>

unsigned C_N_floor(unsigned N)
{
    if(N == 1)
        return 0;

    return 2*C_N_floor(floor(N/2.0)) + N;
}

unsigned C_N_ceil(double N)
{
    if(N == 1)
        return 0;

    return 2*C_N_ceil(ceil(N/2.0)) + N;
}

unsigned C_N_floor_ceil(double N)
{
    if(N == 1)
        return 0;

    return C_N_floor_ceil(floor(N/2.0)) + C_N_floor_ceil(ceil(N/2.0)) + N;
}

int main(void)
{
    printf("N\tC_N (i)\t\tC_N (ii)\tC_N (iii)\n");
    printf("----------------------------------------------\n");
    for (unsigned N = 3; N < 33; N++)
    {
        unsigned CN_recurrence1 = C_N_floor(N);
        unsigned CN_recurrence2 = C_N_ceil(N);
        unsigned CN_recurrence3 = C_N_floor_ceil(N);
        printf("%u\t%u\t\t%u\t\t%u\n", N, CN_recurrence1, CN_recurrence2, CN_recurrence3);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
N       C_N (i)         C_N (ii)        C_N (iii)
----------------------------------------------
3       3               7               5
4       8               8               8
5       9               19              12
6       12              20              16
7       13              23              20
8       24              24              24
9       25              47              29
10      28              48              34
11      29              51              39
12      36              52              44
13      37              59              49
14      40              60              54
15      41              63              59
16      64              64              64
17      65              111             70
18      68              112             76
19      69              115             82
20      76              116             88
21      77              123             94
22      80              124             100
23      81              127             106
24      96              128             112
25      97              143             118
26      100             144             124
27      101             147             130
28      108             148             136
29      109             155             142
30      112             156             148
31      113             159             154
32      160             160             160

--------------------------------------------------------------------- */


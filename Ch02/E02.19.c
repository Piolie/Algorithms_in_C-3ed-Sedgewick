/* ---------------------------------------------------------------------
                              EXERCISE 2.19
------------------------------------------------------------------------
Give the largest value of N for which you can solve a problem that
requires at least f(N) instructions on a machine that can execute 10^9
instructions per second, for the following functions f(N): N^(3/2),
N^(5/4), 2*N*H_N, N*lg N * lglg N, and N^2*lg N.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
If some problem requires f(N) instructions to solve, and my machine can
execute 10^9 instructions per second, then the time that it will take is
simply:
    T = f(N)/10^9

I think that what the exercise is asking doesn't make much sense.
Theoretically, there is no "largest value of N". However, we already
know that for some f(N), the time could be longer than the remaining
life of the universe, even for moderately large N.

I'll constraint the exercise to solving the problem in under 1 second:
    T = f(N)/10^9 < 1
means
    f(N) < 10^9

Notes:
    - the solution uses an array of functions so as not to repeat too
    much code;
    - the lowest N has to be 2 for lglg(N) to be defined.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <math.h>

#define IPS 1000000000 /* 10^9 */
#define N_FUNCTIONS 5

typedef double f_N(unsigned int);

double pow_3_2(unsigned int n)
{
    return pow(n, 3.0/2.0);
}

double pow_5_4(unsigned int n)
{
    return pow(n, 5.0/4.0);
}

double H_N(unsigned int n)
{
    const double log2 = log(2);
    const double gamma = 0.57721;

    return log(n)/log2 + gamma + 1.0/(12*n);
}

double twoNH_N(unsigned int n)
{
    return 2*n*H_N(n);
}

double lgN(unsigned int n)
{
    return log(n)/log(2);
}

double NlgNlglgN(unsigned int n)
{
    return n*lgN(n)*lgN(lgN(n));
}

double N2lgN(unsigned int n)
{
    return n*n*lgN(n);
}

const char f_names[N_FUNCTIONS][20] = /* function names to print */
    {{"N^(3/2)"}, {"N^(5/4)"}, {"2*N*H_N"}, {"N*lg N * lglg N"}, {"N^2*lg N"}};

int main(void)
{
    unsigned int i, N;

    f_N *f_array[N_FUNCTIONS] = /* fancy array of functions */
        {pow_3_2, pow_5_4, twoNH_N, NlgNlglgN, N2lgN};

    for (i = 0; i < N_FUNCTIONS; i++)
    {
        for (N = 2; f_array[i](N) < IPS; N++);
        printf("%15s: N < %u\n", f_names[i], N);
    }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
        N^(3/2): N < 1000000
        N^(5/4): N < 15848932
        2*N*H_N: N < 20128848
N*lg N * lglg N: N < 9534905
       N^2*lg N: N < 8740

--------------------------------------------------------------------- */

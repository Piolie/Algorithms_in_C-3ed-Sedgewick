/* ---------------------------------------------------------------------
                              EXERCISE 2.5
------------------------------------------------------------------------
For what values of N is 10*N*lg N > 2 N^2?
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Clearing the inequality a little we get:
    10*N*lg N > 2 N^2
         lg N > N/5

There is no analytical solution, so we approximate.
f(N) = lg N and g(N) = N/5 intersect at two different points:
    N1 ~= 1.177
    N2 ~= 22.44

Let's choose any N between N1 and N2 and see what we've got. For N = 4,
the left side is 2 and the right side is 4/5, so the inequality holds
true. That means the range of integer N values is [2, 22].

Let's use a little program to verify, with n up to ULLONG_MAX.
Remember that log_b(a) = log_c(a)/log_c(b). This allows us to write
lg a = log(a)/log(2).
--------------------------------------------------------------------- */

#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(void)
{
    unsigned long long n;
    const double log2 = log(2);
    for (n = 1; n < ULLONG_MAX; n++)
        if (log(n)/log2 > n/5.0)
            printf("In range: %llu\n", n);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
In range: 2
In range: 3
In range: 4
In range: 5
In range: 6
In range: 7
In range: 8
In range: 9
In range: 10
In range: 11
In range: 12
In range: 13
In range: 14
In range: 15
In range: 16
In range: 17
In range: 18
In range: 19
In range: 20
In range: 21
In range: 22

--------------------------------------------------------------------- */

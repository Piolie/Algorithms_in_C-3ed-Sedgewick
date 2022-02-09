/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                      PROGRAM 3.2 Types of numbers
------------------------------------------------------------------------
This program computes the average μ and standard deviation σ of a
sequence x_1, x_2, ... , x_N of integers generated by the library
procedure rand, following the mathematical definitions

        -----
     1  \
μ = --- /      x_i
     N  ------
        1<=i<=N

and

          -----                    -----
       1  \                     1  \
σ^2 = --- /      (x_i - μ)^2 = --- /      x_i^2 - μ^2
       N  ------                N  ------
         1<=i<=N                  1<=i<=N

Note that a direct implementation from the definition of σ requires one
pass to compute the average and another to compute the sums of the
squares of the differences between the members of the sequence and the
average, but rearranging the formula makes it possible for us to compute
σ^2 in one pass through the data.

We use the typedef declaration to localize reference to the fact that
the type of the data is into For example, we could keep the typedef
and the function randNum in a separate file (referenced by an include
directive), and then we could use this program to test random numbers
of a different type by changing that file (see text).

Whatever the type of the data, the program uses ints for indices and
floats to compute the average and standard deviation, and will be
effective only if conversion functions from the data to float perform in
a reasonable manner.

--------------------------------------------------------------------- */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef int Number;

Number randNum(void)
{
    return rand();
}

int main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    float m1 = 0.0, m2 = 0.0;
    Number x;
    for (i = 0; i < N; i++)
    {
        x = randNum();
        m1 += ((float) x)/N;
        m2 += ((float) x*x)/N;
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2-m1*m1));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
P03.02_types_of_numbers.exe 1000

       Average: 16397.156250
Std. deviation: 9442.030290

--------------------------------------------------------------------- */
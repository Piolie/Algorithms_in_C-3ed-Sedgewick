/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                   PROGRAM 3.6 Sieve of Eratosthenes
------------------------------------------------------------------------
To change the value of the maximum prime computed in Program 3.5, we
need to recompile the program. Instead, we can take the maximum desired
number from the command line, and use it to allocate space for the array
at execution time, using the library function malloc from stdlib.c. For
example, if we compile this program and use 1000000 as a command-line
argument, then we get all the primes less than 1 million (as long as our
computer is big and fast enough to make the computation feasible); we
can also debug with 100 (without using much time or space). We will use
this idiom frequently, though, for brevity, we will omit the
insufficient-memory test.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This program doesn't work if the command line argument is 1000000, no
matter what the statement above says. It doesn't even work with 100000.
The issue is with the product i*j. Since both variables are ints, the
product overflows for big enough i and j. Signed integer overflow is
undefined behavior in C. On my system, the program ends with no error
message at all. Your's could be different.

Using unsigned long int for i and j works for argument 1000000.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long int i, j, N = atoi(argv[1]);
    int *a = malloc(N*sizeof(int));
    if (a == NULL)
    {
        printf("Insufficient memory.\n");
        return 1;
    }
    for (i = 2; i < N; i++)
        a[i] = 1;
    for (i = 2; i < N; i++)
        if (a[i])
            for (j = i; i*j < N; j++)
                a[i*j] = 0;
    for (i = 2; i < N; i++)
        if (a[i]) printf("%4ld ", i);
    printf("\n");
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
P03.06_dynamic_memory_allocation_for_an_array.exe 1000
  2    3    5    7   11   13   17   19   23   29   31   37   41   43
 47   53   59   61   67   71   73   79   83   89   97  101  103  107
109  113  127  131  137  139  149  151  157  163  167  173  179  181
191  193  197  199  211  223  227  229  233  239  241  251  257  263
269  271  277  281  283  293  307  311  313  317  331  337  347  349
353  359  367  373  379  383  389  397  401  409  419  421  431  433
439  443  449  457  461  463  467  479  487  491  499  503  509  521
523  541  547  557  563  569  571  577  587  593  599  601  607  613
617  619  631  641  643  647  653  659  661  673  677  683  691  701
709  719  727  733  739  743  751  757  761  769  773  787  797  809
811  821  823  827  829  839  853  857  859  863  877  881  883  887
907  911  919  929  937  941  947  953  967  971  977  983  991  997

--------------------------------------------------------------------- */

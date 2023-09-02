/* ---------------------------------------------------------------------
                             EXERCISE 2.34
------------------------------------------------------------------------
Answer Exercise 2.33, but interpret N/2 to mean ceil[N/2].
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
(I think I found a solution for this problem, but only through trial and
error. The following are mostly some notes I took while trying.)

Look:
   N   (N)_2   ceil[N/2]    (N-1)    ceil[(N-1)/2]
   1       1          1        0           0
   2      10          1        1           1
   3      11         10       10           1
   4     100         10       11          10
   5     101         11      100          10
   6     110         11      101          11
   7     111        100      110          11
   8    1000        100      111         100
   9    1001        101     1000         100
  10    1010        101     1001         101
  11    1011        110     1010         101
  12    1100        110     1011         110
  13    1101        111     1100         110
  14    1110        111     1101         111
  15    1111       1000     1110         111

It seems like the number of bits in the binary representation of N is
1 greater than the number of bits in the binary representation of
ceil[N/2] except for a shift. If we instead compare with the number of
bits in the binary representation of ceil[(N-1)/2] we have a full
coincidence. We can write
  #N = #ceil[(N-1)/2] + 1
(# is the "number of bits in the binary representation" operator.)

Thus, floor[lg N] + 1, the number of bits in the binary representation
of N, is the solution to the equation
  C_N = C_ceil[(N-1)/2] + 1
but not of our equation!
------------------------------------------------------------------------
Let's try manually calculating some values:
   N   C_N  C_(N-1)    C_N-C_(N-1)
   1   1
   2   2       1           1
   3   3       2           1
   4   3       3           0
   5   4       3           1
   6   4       4           0
   7   4       4           0
   8   4       4           0
   9   5       4           1
  10   5       5           0
  11   5       5           0
  12   5       5           0
  13   5       5           0
  14   5       5           0
  15   5       5           0
  16   5       5           0
  17   6       5           1

It seems that:
                  / 1, for N = 2^k + 1
  C_N - C_(N-1) = |
                  \ 0, for 2^k + 1 < N <= 2^(k+1)

I fiddled around a bit and found a function that seems to work:
  C_N = floor[lg(N-1)] + 2.

N = 2^k + 1:
  C_N - C_(N-1) = floor[lg(2^k + 1 - 1)] + 2 - floor[lg(2^k + 1 - 1 - 1)] + 2
                = floor[lg(2^k)] - floor[lg(2^k - 1)]
                = floor[k lg 2] - floor[lg(2^k - 1)]
                = k - (k - 1)
                = 1

2^k + 1 < N <= 2^(k+1):
  C_N - C_(N-1) = floor[lg(N-1)] + 2 - floor[lg(N-2)] + 2
                = k - k
                = 0

We would have to apply induction to formally prove it.

The following program uses both the recurrence and the formula to
compute the table, and checks that the values are equal.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>

unsigned int C_N_ceil(double N) {
  if (N == 1)
    return 1;

  return C_N_ceil(ceil(N / 2.0)) + 1;
}

int main(void) {
  printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
  printf("----------------------------------------------\n");
  for (unsigned int N = 2; N < 33; N++) {
    unsigned int CN_recurrence = C_N_ceil(N);
    unsigned int CN_formula = (unsigned int)floor(log(N - 1) / log(2)) + 2;
    int equal = (CN_recurrence == CN_formula);
    printf("%u\t%u\t\t%u\t\t%s\n", N, CN_recurrence, CN_formula,
           equal ? "TRUE" : "FALSE");
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
N       C_N (rec.)      C_N (form.)     Equal?
----------------------------------------------
2       2               2               TRUE
3       3               3               TRUE
4       3               3               TRUE
5       4               4               TRUE
6       4               4               TRUE
7       4               4               TRUE
8       4               4               TRUE
9       5               5               TRUE
10      5               5               TRUE
11      5               5               TRUE
12      5               5               TRUE
13      5               5               TRUE
14      5               5               TRUE
15      5               5               TRUE
16      5               5               TRUE
17      6               6               TRUE
18      6               6               TRUE
19      6               6               TRUE
20      6               6               TRUE
21      6               6               TRUE
22      6               6               TRUE
23      6               6               TRUE
24      6               6               TRUE
25      6               6               TRUE
26      6               6               TRUE
27      6               6               TRUE
28      6               6               TRUE
29      6               6               TRUE
30      6               6               TRUE
31      6               6               TRUE
32      6               6               TRUE
--------------------------------------------------------------------- */

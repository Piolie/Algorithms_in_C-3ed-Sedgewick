/* ---------------------------------------------------------------------
                             EXERCISE 2.33
------------------------------------------------------------------------
Give a table of the values of C_N in Formula 2.2 for 1 <= N <= 32,
interpreting N/2 to mean floor[N/2].
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The book states:
  In the case that N/2 represents floor[N/2], we have a simple solution:
  C_N is the number of bits in the binary representation of N, and that
  number is floor[lg N] + 1, by definition.

The proof of this statement does not seem obvious to me. Not even
intuitively. Let's investigate a little.

Figure 2.6 clarifies the intuitive part:
   N   (N)_2   floor[N/2]     floor[lg N] + 1
   1       1          0            1
   2      10          1            2
   3      11          1            2
   4     100         10            3
   5     101         10            3
   6     110         11            3
   7     111         11            3
   8    1000        100            4
   9    1001        100            4
  10    1010        101            4
  11    1011        101            4
  12    1100        110            4
  13    1101        110            4
  14    1110        111            4
  15    1111        111            4

  Given the binary representation of a number N (center), we obtain
  floor[N/2] by removing the rightmost bit. That is, the number of bits
  in the binary representation of N is 1 greater than the number of bits
  in the binary representation of floor[N/2]. Therefore,
  floor[lg N] + 1, the number of bits in the binary representation of
  N, is the solution to Formula 2.2 for the case that N/2 is interpreted
  as floor[N/2].

If we denote "the number of bits in the binary representation" as #, we
can then write
  #N = #floor[N/2] + 1
which is the same equation that defines C_N. Thus
  C_N = floor[lg N] + 1

We could more formally prove this using induction. Some hints for
similar problems are given at:
https://math.stackexchange.com/questions/3135601/
https://math.stackexchange.com/questions/1370643/
https://math.stackexchange.com/questions/3505063/
https://math.stackexchange.com/questions/2991149/

We can manually check for 0 < N < 10:
  C_1                           = 1
  C_1 = floor[lg 1] + 1 = 0 + 1 = 1

  C_2 = C_floor[2/2] + 1 = C_1 + 1      = 2
  C_2 = floor[lg 2] + 1 = floor[1] + 1 = 2

  C_3 = C_floor[3/2] + 1 = C_floor[1.5] + 1 = C_1 + 1 = 2
  C_3 = floor[lg 3] + 1 = floor[1.58] + 1             = 2

  C_4 = C_floor[4/2] + 1 = C_2 + 1     = 3
  C_4 = floor[lg 4] + 1 = floor[2] + 1 = 3

  C_5 = C_floor[5/2] + 1 = C_floor[2.5] + 1 = C_2 + 1 = 3
  C_5 = floor[lg 5] + 1 = floor[2.32] + 1 = 2 + 1     = 3

  C_6 = C_floor[6/2] + 1 = C_3 + 1        = 3
  C_6 = floor[lg 6] + 1 = floor[2.58] + 1 = 3

  C_7 = C_floor[7/2] + 1 = C_floor[3.5] + 1 = C_3 + 1       = 3
  C_7 = floor[lg 7] + 1 = floor[lg 2.81] + 1 = floor[2] + 1 = 3

  C_8 = C_floor[8/2] + 1 = C_4 + 1     = 4
  C_8 = floor[lg 8] + 1 = floor[4] + 1 = 4

  C_9 = C_floor[9/2] + 1 = C_floor[4.5] + 1 = C_4 + 1    = 4
  C_9 = floor[lg 9] + 1 = floor[3.17] + 1 = floor[3] + 1 = 4

The following program uses both the recurrence and the formula to
compute the table, and checks that the values are equal.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>

unsigned C_N_floor(double N) {
  if (N == 1)
    return 1;

  return C_N_floor(floor(N / 2.0)) + 1;
}

int main(void) {
  printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
  printf("----------------------------------------------\n");
  for (unsigned N = 1; N < 33; N++) {
    unsigned CN_recurrence = C_N_floor(N);
    unsigned CN_formula = (unsigned)floor(log(N) / log(2)) + 1;
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
1       1               1               TRUE
2       2               2               TRUE
3       2               2               TRUE
4       3               3               TRUE
5       3               3               TRUE
6       3               3               TRUE
7       3               3               TRUE
8       4               4               TRUE
9       4               4               TRUE
10      4               4               TRUE
11      4               4               TRUE
12      4               4               TRUE
13      4               4               TRUE
14      4               4               TRUE
15      4               4               TRUE
16      5               5               TRUE
17      5               5               TRUE
18      5               5               TRUE
19      5               5               TRUE
20      5               5               TRUE
21      5               5               TRUE
22      5               5               TRUE
23      5               5               TRUE
24      5               5               TRUE
25      5               5               TRUE
26      5               5               TRUE
27      5               5               TRUE
28      5               5               TRUE
29      5               5               TRUE
30      5               5               TRUE
31      5               5               TRUE
32      6               6               TRUE
--------------------------------------------------------------------- */

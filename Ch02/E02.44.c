/* ---------------------------------------------------------------------
                             EXERCISE 2.44
------------------------------------------------------------------------
Solve the recurrence
    C_N = (2 + 1/lg N)*C_(N/2), for N >= 2 with C_1 = 1
when N is a power of 2.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
N = 2^n

C_N = (2 + 1/lg 2^n)*C_(2^n/2)
    = (2 + 1/n)*C_(2^(n-1))
    = (2 + 1/n)*(2 + 1/lg 2^(n-1))*C_(2^(n-2))
    = (2 + 1/n)*(2 + 1/(n-1))*C_(2^(n-2))
    = ...
    = (2 + 1/n)*(2 + 1/(n-1))*...*(2 + 1/(1))*C_(2^(n-n))
    = (2 + 1/n)*(2 + 1/(n-1))*...*(2 + 1/(1))*C_1
    = (2 + 1/n)*(2 + 1/(n-1))*...*(2 + 1)

       i=n
      ----- /      1  \
    =  | |  | 2 + --- |
       | |  \      i  /
       i=1

------------------------------------------------------------------------
We would have to apply induction to formally prove it.
(This one is easy.)

--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>

double C_N(double N) {
  if (N == 1)
    return 1;

  return (2 + 1.0 / log2(N)) * C_N(N / 2);
}

unsigned int C_2pown_formula(unsigned int n) {
  double result = 1;
  for (unsigned int i = 1; i < n + 1; i++)
    result *= (2 + 1.0 / i);

  return (unsigned int)result;
}

int main(void) {
  printf("N\tC_N (rec.)\tC_N (form.)\tEqual?\n");
  printf("----------------------------------------------\n");
  unsigned int N, n;
  for (N = 1, n = 0; N < 10000000; n++, N = (unsigned int)(exp2(n))) {
    unsigned int CN_recurrence = C_N(N);
    unsigned int CN_formula = C_2pown_formula(n);
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
2       3               3               TRUE
4       7               7               TRUE
8       17              17              TRUE
16      39              39              TRUE
32      86              86              TRUE
64      187             187             TRUE
128     402             402             TRUE
256     854             854             TRUE
512     1804            1804            TRUE
1024    3788            3788            TRUE
2048    7922            7922            TRUE
4096    16504           16504           TRUE
8192    34279           34279           TRUE
16384   71007           71007           TRUE
32768   146748          146748          TRUE
65536   302668          302668          TRUE
131072  623140          623140          TRUE
262144  1280899         1280899         TRUE
524288  2629213         2629213         TRUE
1048576 5389888         5389888         TRUE
2097152 11036438        11036438        TRUE
4194304 22574532        22574532        TRUE
8388608 46130567        46130567        TRUE
--------------------------------------------------------------------- */

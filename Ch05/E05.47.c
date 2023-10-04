/* ---------------------------------------------------------------------
                             EXERCISE 5.47
------------------------------------------------------------------------
Draw a plot of N versus the number of recursive calls that your function
from Exercise 5.41 makes to compute C_N, for 0 <= N <= 1024. (For the
purposes of this calculation, start your program from scratch for each
N.)
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The number of recursive calls seems to grow quadratically fast. We could
further optimize the function by applying memoization to the sum, which
is what makes most of the calls.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

static float *knownC;
static int calls;

float C(unsigned int N) {
  calls++;
  if (knownC[N] != -1)
    return knownC[N];
  if (N == 0)
    return (knownC[N] = 0);

  float sum = 0;
  for (unsigned int k = 1; k <= N; k++)
    sum += C(k - 1) + C(N - k);
  return (knownC[N] = N + sum / N);
}

int main(void) {
  int N = 1024;
  knownC = malloc((N + 1) * sizeof *knownC);

  for (int i = 0; i <= N + 1; i += 50) {
    for (int j = 0; j <= i + 1; j++)
      knownC[j] = -1;
    calls = 0;
    C(i);
    printf("N = %4d ", i);
    for (int j = 0; j < calls / 25000; j++)
      printf("*");
    printf(" %2d calls", calls);
    printf("\n");
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.47.exe
N =    0   1 calls
N =   50  2551 calls
N =  100  10101 calls
N =  150  22651 calls
N =  200 * 40201 calls
N =  250 ** 62751 calls
N =  300 *** 90301 calls
N =  350 **** 122851 calls
N =  400 ****** 160401 calls
N =  450 ******** 202951 calls
N =  500 ********** 250501 calls
N =  550 ************ 303051 calls
N =  600 ************** 360601 calls
N =  650 **************** 423151 calls
N =  700 ******************* 490701 calls
N =  750 ********************** 563251 calls
N =  800 ************************* 640801 calls
N =  850 **************************** 723351 calls
N =  900 ******************************** 810901 calls
N =  950 ************************************ 903451 calls
N = 1000 **************************************** 1001001 calls
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 5.43
------------------------------------------------------------------------
Draw a plot of N versus the number of recursive calls that your function
from Exercise 5.41 makes to compute P_N, for 0 <= N <= 1024. (For the
purposes of this calculation, start your program from scratch for each
N.)
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The number of recursive calls remains somewhat bounded.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int *knownF;
static int calls;

int P(unsigned int N) {
  calls++;
  if (knownF[N] != -1)
    return knownF[N];
  if (N == 0)
    return 0;
  if (N == 1)
    return 1;
  if (N > 1) {
    int f = floor(N / 2.0);
    int c = ceil(N / 2.0);
    int Pf = P(f);
    int Pc = P(c);
    return (knownF[N] = f + Pf + Pc);
  }
  return -1;
}

int main(void) {
  int N = 1024;
  knownF = malloc((N + 1) * sizeof *knownF);

  for (int i = 0; i <= N + 1; i += 50) {
    for (int j = 0; j <= i + 1; j++)
      knownF[j] = -1;
    calls = 0;
    P(i);
    printf("N = %4d ", i);
    for (int j = 0; j < calls; j++)
      printf("*");
    printf(" %2d calls", calls);
    printf("\n");
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.43.exe
N =    0 *  1 calls
N =   50 ******************* 19 calls
N =  100 ********************* 21 calls
N =  150 ************************* 25 calls
N =  200 *********************** 23 calls
N =  250 *************************** 27 calls
N =  300 *************************** 27 calls
N =  350 ***************************** 29 calls
N =  400 ************************* 25 calls
N =  450 ******************************* 31 calls
N =  500 ***************************** 29 calls
N =  550 ********************************* 33 calls
N =  600 ***************************** 29 calls
N =  650 ********************************* 33 calls
N =  700 ******************************* 31 calls
N =  750 ********************************* 33 calls
N =  800 *************************** 27 calls
N =  850 *********************************** 35 calls
N =  900 ********************************* 33 calls
N =  950 *********************************** 35 calls
N = 1000 ******************************* 31 calls
--------------------------------------------------------------------- */

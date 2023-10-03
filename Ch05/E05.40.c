/* ---------------------------------------------------------------------
                             EXERCISE 5.40
------------------------------------------------------------------------
Write a function that uses bottom-up dynamic programming to compute the
value of P_N defined by the recurrence
  P_N = floor[N/2] + P_floor[N/2] + P_ceil[N/2],
  for N >= 1 with P_0 = 0.
Draw a plot of N versus P_N - N*lg(N/2) for 0 <= N <= 1024.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
There seems to be a missing term to compute the recurrence:
  P_0 = 0
  P_1 = floor[1/2] + P_floor[1/2] + P_ceil[1/2]
      = floor[0.5] + P_floor[0.5] + P_ceil[0.5]
      =     0      + P_0          + P_1
      =     0      +  0           + P_1
      = P_1

I'll then start like the Fibonacci sequence: P_0 = 0 and P_1 = 1.

Notice that if N is even:
  P_N = N/2 + P_(N/2) + P_(N/2)
while if N is odd:
  P_N = N/2 + P_(N/2) + P_(N/2 + 1)

To calculate P_N, we only need to know the first N/2 + 2 elements. Thus,
this function first populates an array with the values of P_i for
0 <= i <= N/2 + 1 and then uses that array to find the value of P_N.

I'm not including the plot.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int P(unsigned int N) {
  int knownP[N / 2 + 2];
  knownP[0] = 0;
  knownP[1] = 1;

  unsigned int i;
  for (i = 2; i < N / 2 + 2; i++) {
    if (i % 2) { // odd: P_i = i / 2 + P_(i / 2) + P_(i / 2 + 1)
      knownP[i] = i / 2 + knownP[i / 2] + knownP[i / 2 + 1];
    } else { // even: P_N = i / 2 + P_(i / 2) + P_(i / 2)
      knownP[i] = i / 2 + knownP[i / 2] + knownP[i / 2];
    }
  }
  if (N % 2) {
    return N / 2 + knownP[N / 2] + knownP[N / 2 + 1];
  } else {
    return N / 2 + knownP[N / 2] + knownP[N / 2];
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  printf("P_%d = %d\n", N, P(N));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.40.exe 20
P_20 = 60

./E05.40.exe 99
P_99 = 411

./E05.40.exe 1001
P_1001 = 5939
--------------------------------------------------------------------- */

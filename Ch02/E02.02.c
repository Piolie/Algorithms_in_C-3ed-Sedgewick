/* ---------------------------------------------------------------------
                              EXERCISE 2.2
------------------------------------------------------------------------
How long does it take to count to 1 billion? (ignoring overflow)?
Determine the amount of time it takes the program

  int i, j, k, count = 0;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      for (k = 0; k < N; k++)
        count++;

to complete in your programming environment, for N = 10, 100, and 1000.
If your compiler has optimization features that are supposed to make
programs more efficient, check whether or not they do so for this
program.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'm compiling with GCC using either:
  gcc -m64 -std=c99
  gcc -m64 -O1 -std=c99

(Using either -O2 or -O3 results in instant finishing times.)

Also, since the standard clock in C is not very accurate, we'll be
accumulating several (RUNS) runs and taking the average to get a better
measurement. Ideally, we would use a profiler, designed specifically for
these use cases. However, clock() is enough for a simple exercise.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <time.h>

#define N 10
#define RUNS 10000000

int main(void) {
  time_t time;

  time = clock();
  for (int run = 0; run < RUNS; run++) {
    int i, j, k, count = 0;
    for (i = 0; i < N; i++)
      for (j = 0; j < N; j++)
        for (k = 0; k < N; k++)
          count++;
  }
  time = clock() - time;

  printf("Average time for N = %d: %e seconds\n", N,
         (double)time / RUNS / CLOCKS_PER_SEC);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Without compiler optimizations:
  - N = 10; RUNS = 100000     : 1.27 microseconds
  - N = 100; RUNS = 100       : 1.58 milliseconds
  - N = 1000; RUNS = 10       : 1.56 seconds

With compiler optimizations (-O1):
  - N = 10; RUNS = 10000000   : 0.6 nanoseconds
  - N = 100; RUNS = 100       : 0.37 milliseconds
  - N = 1000; RUNS = 10       : 0.24 seconds
--------------------------------------------------------------------- */

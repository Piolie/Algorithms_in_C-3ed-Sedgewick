/* ---------------------------------------------------------------------
                             EXERCISE 3.19
------------------------------------------------------------------------
Write a program that determines empirically the number of random
positive integers less than 1000 that you can expect to generate before
getting each value at least once.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This program should be run several times to get the average number of
tries needed.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(void) {
  char array[N] = {0};
  int number, numbers_left, tries = 0;

  for (numbers_left = N; numbers_left > 0;) {
    number = rand() % N;
    tries++;
    // printf("number = %d\n", number);
    if (!array[number]) {
      array[number] = 1;
      numbers_left--;
    }
  }
  printf("Number of tries before getting all ints < %d = %d\n", N, tries);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Number of tries before getting all ints < 1000 = 8565
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 3.18
------------------------------------------------------------------------
Write a program that determines empirically the number of random
positive integers less than 1000 that you can expect to generate before
getting a repeated value.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This program should be run several times to get the average number of
random ints needed.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(void) {
  char array[N] = {0};
  int number, count;

  for (;;) {
    number = rand() % N;
    printf("number = %d\n", number);
    if (array[number])
      break;
    else {
      array[number] = 1;
      count++;
    }
  }
  printf("Number of unique random ints less than %d = %d\n", N, count);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
number = 41
number = 467
number = 334
number = 500
number = 169
number = 724
number = 478
number = 358
number = 962
number = 464
number = 705
number = 145
number = 281
number = 827
number = 961
number = 491
number = 995
number = 942
number = 827
Number of unique random ints less than 1000 = 18
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 3.17
------------------------------------------------------------------------
Write a program that counts the number of different integers less than
1000 that appear in an input stream.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'll use argv[] as the input stream.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int count = 0;
  for (int i = 1; i < argc; i++)
    if (atoi(argv[i]) < 1000)
      count++;
  printf("Number of ints less than 1000 = %d\n", count);
}

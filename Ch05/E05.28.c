/* ---------------------------------------------------------------------
                             EXERCISE 5.28
------------------------------------------------------------------------
Write a function that computes efficiently the number of trailing 0s in
the binary representation of an integer.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Is this supposed to be a solution that uses recursion? Does the solution
need to be efficient in time, space or what?

I've written a recursive function to print the binary representation of
the number. The function that counts the trailing zeros does bit
manipulations and assumes the number is a 32-bit positive integer.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

void print_bin(int n) {
  if (n == 0) {
    printf("%d ", 0);
    return;
  }
  print_bin(n / 2);
  printf("%d ", n % 2);
}

int ctz(int v) {
  int count = 0;

  if (v) {
    while (!(v & 1)) {
      count++;
      v >>= 1;
    }
    return count;
  } else
    return 32;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int n = atoi(argv[1]);
  print_bin(n);
  printf("\n");
  printf("%d trailing zeros in the binary representation of %d", ctz(n), n);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.28.exe 0
0
32 trailing zeros in the binary representation of 0

./E05.28.exe 4
0 1 0 0
2 trailing zeros in the binary representation of 4

./E05.28.exe 65535
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 trailing zeros in the binary representation of 65535

./E05.28.exe 65536
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
16 trailing zeros in the binary representation of 65536

./E05.28.exe 2147483647
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 trailing zeros in the binary representation of 2147483647
--------------------------------------------------------------------- */

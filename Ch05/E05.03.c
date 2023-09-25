/* ---------------------------------------------------------------------
                              EXERCISE 5.3
------------------------------------------------------------------------
Give the sequences of argument values that result when Program 5.2 is
invoked for each of the integers 1 through 9.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int depth;

int puzzle(int N) {
  printf("%*spuzzle(%d)\n", depth, "", N);
  depth++;
  if (N == 1)
    return 1;
  if (N % 2 == 0)
    return puzzle(N / 2);
  else
    return puzzle(3 * N + 1);
}

int main(void) {
  for (int N = 1; N < 10; N++) {
    depth = 0;
    printf("N = %d\n", N);
    puzzle(N);
    printf("\n");
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.03.exe
N = 1
puzzle(1)

N = 2
puzzle(2)
 puzzle(1)

N = 3
puzzle(3)
 puzzle(10)
  puzzle(5)
   puzzle(16)
    puzzle(8)
     puzzle(4)
      puzzle(2)
       puzzle(1)

N = 4
puzzle(4)
 puzzle(2)
  puzzle(1)

N = 5
puzzle(5)
 puzzle(16)
  puzzle(8)
   puzzle(4)
    puzzle(2)
     puzzle(1)

N = 6
puzzle(6)
 puzzle(3)
  puzzle(10)
   puzzle(5)
    puzzle(16)
     puzzle(8)
      puzzle(4)
       puzzle(2)
        puzzle(1)

N = 7
puzzle(7)
 puzzle(22)
  puzzle(11)
   puzzle(34)
    puzzle(17)
     puzzle(52)
      puzzle(26)
       puzzle(13)
        puzzle(40)
         puzzle(20)
          puzzle(10)
           puzzle(5)
            puzzle(16)
             puzzle(8)
              puzzle(4)
               puzzle(2)
                puzzle(1)

N = 8
puzzle(8)
 puzzle(4)
  puzzle(2)
   puzzle(1)

N = 9
puzzle(9)
 puzzle(28)
  puzzle(14)
   puzzle(7)
    puzzle(22)
     puzzle(11)
      puzzle(34)
       puzzle(17)
        puzzle(52)
         puzzle(26)
          puzzle(13)
           puzzle(40)
            puzzle(20)
             puzzle(10)
              puzzle(5)
               puzzle(16)
                puzzle(8)
                 puzzle(4)
                  puzzle(2)
                   puzzle(1)
--------------------------------------------------------------------- */

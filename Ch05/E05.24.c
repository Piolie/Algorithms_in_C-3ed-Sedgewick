/* ---------------------------------------------------------------------
                             EXERCISE 5.24
------------------------------------------------------------------------
Write a program that produces a solution to the towers of Hanoi problem
by filling in an array that holds all the moves, as in Program 5.9
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The key to this exercise is in the following excerpt (p. 202):
  We see immediately that the sequence of lengths [heights of the marks
  on the ruler] is precisely the same as the sequence of disks moved for
  the towers of Hanoi problem.

For the disks to start in the first peg and end in the middle one, we
have to take into account the parity of the number of disks. If the
number of disks is odd we make the very first move to the right (+1),
whereas if it is odd we make the first move to the left (-1). I've used
this little trick to change the signs according to parity:
  sign = 2 * (N & 1) - 1
is +1 if x is odd, -1 otherwise. It's used for the sign variable, which
tracks the parity of N and also when saving the value of t, to track its
parity.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

static int *move_arr;
static int moves;

void calculate_moves(int N) {
  int sign = 2 * (N & 1) - 1; // +1 if N is odd
  for (int t = 1, j = 1; t <= N; j += j, t++)
    for (int i = 0; j + i <= moves; i += j + j)
      move_arr[j + i - 1] = t * (2 * (t & 1) - 1) * sign;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  moves = (1 << N) - 1; // 2^N - 1
  move_arr = malloc(moves * sizeof *move_arr);

  calculate_moves(N);

  for (int i = 0; i < moves / 2; i++)
    printf("%+2d ", move_arr[i]);
  printf("\n");
  for (int i = moves / 2; i < moves; i++)
    printf("%+2d ", move_arr[i]);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.24.exe 1

+1

./E05.24.exe 2
-1
+2 -1

./E05.24.exe 3
+1 -2 +1
+3 +1 -2 +1

./E05.24.exe 4
-1 +2 -1 -3 -1 +2 -1
+4 -1 +2 -1 -3 -1 +2 -1

./E05.24.exe 5
+1 -2 +1 +3 +1 -2 +1 -4 +1 -2 +1 +3 +1 -2 +1
+5 +1 -2 +1 +3 +1 -2 +1 -4 +1 -2 +1 +3 +1 -2 +1
--------------------------------------------------------------------- */

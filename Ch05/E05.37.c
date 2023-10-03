/* ---------------------------------------------------------------------
                             EXERCISE 5.37
------------------------------------------------------------------------
Write a function that computes F_N mod M, using only a constant amount
of space for intermediate calculations.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This one really surprised me, because it's marked in the book as a "test
your understanding" exercise, which "should present no special
difficulty".

The sequence (F_N mod M) is periodic with a period called the Pisano
period. Given M, we can allocate an array of at least this length and
then index by N % M in that array.

The added difficulty lies in that there is no general formula for the
Pisano period and also no general upper bounds, so we have to manually
calculate it. This implies detecting a cycle, which is doable but not
trivial (see E03.54).

From inspecting the tables of F_N mod M, I've noticed that all cycles
seem to start with the sequence 0 1, which is never repeated inside the
cycle, so I'll use that heuristic to calculate the period. Adapted from:
[Calculating Pisano periods for any
integer](https://mathoverflow.net/questions/144308/).

This procedure implies calculating all the first P numbers of F_N mod P,
but since we haven't yet allocated the array, we cannot save these
values. Thus, we end up recalculating them in the calls to F_mod_M().

For more information, check the
[Wikipedia](https://en.wikipedia.org/wiki/Pisano_period).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I was reading the section again and realized that maybe what the author
intended was that we implemented a simple function that kept track of
just the last two values to calculate the next. I've implemented that
as F_mod_M_simple.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

static int *knownF;

int F_mod_M_simple(int i, int M) {
  if ((M == 0) || (M == 1))
    return 0;
  if (i == 0)
    return 0;
  if (i == 1)
    return 1;
  if (i > 1) {
    int x2 = 0;
    int x1 = 1;
    int xN = 0;
    for (int j = 1; j < i; j++) {
      xN = (x1 + x2) % M;
      x2 = x1;
      x1 = xN;
    }
    return xN % M;
  }
  return 0;
}

int pisano(int M) {
  if ((M == 0) || (M == 1))
    return 0;
  int x2 = 0;
  int x1 = 1;
  int xN = 1;
  for (int i = 0;; i++) {
    xN = (x1 + x2) % M;
    x2 = x1;
    x1 = xN;
    if ((x2 == 0) && (x1 == 1))
      return i + 1;
  }
}

int F_mod_M(int i, int M, int P) {
  int t;
  if (knownF[i % P] != -1)
    return (knownF[i % P]);
  if (i == 0)
    t = 0;
  if (i == 1)
    t = 1;
  if (i > 1)
    t = (F_mod_M(i - 1, M, P) + F_mod_M(i - 2, M, P)) % M;
  return knownF[i % P] = t;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  int P = pisano(M);
  knownF = malloc(P * sizeof *knownF);
  for (int i = 0; i < P; i++)
    knownF[i] = -1;

  printf("Pisano period for M = %d: %d\n", M, P);
  printf("F_%d mod %d = %d\n", N, M, F_mod_M(N, M, P));
  printf("F_%d mod %d = %d\n", N, M, F_mod_M_simple(N, M));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.37.exe 357 5
Pisano period for M = 5: 20
F_357 mod 5 = 2
F_357 mod 5 = 2

./E05.37.exe 2341 94
Pisano period for M = 94: 96
F_2341 mod 94 = 5
F_2341 mod 94 = 5

./E05.37.exe 10577 144
Pisano period for M = 144: 24
F_10577 mod 144 = 13
F_10577 mod 144 = 13
--------------------------------------------------------------------- */

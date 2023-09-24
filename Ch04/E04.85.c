/* ---------------------------------------------------------------------
                             EXERCISE 4.85
------------------------------------------------------------------------
Write a client program that tests your ADT from Exercise 4.84.
--------------------------------------------------------------------- */

#include "SET.h" // #include "E04.84_interface.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const int M = 10;
  Set s1 = SETcreate(M);
  Set s2 = SETcreate(M);
  for (int i = 0; i < M/2; i++) {
    SETaddelement(s1, 2*i);
    SETaddelement(s2, i % 6);
  }
  printf("s1:          ");
  SETprint(s1);
  printf("\n");
  printf("s2:          ");
  SETprint(s2);
  printf("\n");
  printf("s1 union s2: ");
  SETprint(SETunion(s1, s2));
  printf("\n");
  printf("s1 inter s2: ");
  SETprint(SETinter(s1, s2));
  printf("\n");
  printf("compl s1:    ");
  SETprint(SETcompl(s1));
  printf("\n");
  printf("compl s2:    ");
  SETprint(SETcompl(s2));
  printf("\n");
  printf("s2 \\ s1:     ");
  SETprint(SETdiff(s2, s1));
  printf("\n");
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
.\E04.85.exe
s1:            1   0   1   0   1   0   1   0   1   0
s2:            1   1   1   1   1   0   0   0   0   0
s1 union s2:   1   1   1   1   1   0   1   0   1   0
s1 inter s2:   1   0   1   0   1   0   0   0   0   0
compl s1:      0   1   0   1   0   1   0   1   0   1
compl s2:      0   0   0   0   0   1   1   1   1   1
s2 \ s1:       0   1   0   1   0   0   0   0   0   0
--------------------------------------------------------------------- */

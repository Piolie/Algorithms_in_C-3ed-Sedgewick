/* ---------------------------------------------------------------------
                             EXERCISE 3.21
------------------------------------------------------------------------
Modify Program 3.7 to simulate a situation where the coin turns up heads
with probability λ/N. Run 1000 trials for an experiment with 32 flips
to get output that you can compare with Figure 3.2. This distribution is
the classical Poisson distribution.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The statement doesn't suggest a value for λ, so the comparison doesn't
make too much sense. I'll choose λ = 5 since 5/32 = 0,156 ~ 1/6 ~ 0.167.
This way we can compare with the result from E3.20.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int heads(float p) { return rand() < RAND_MAX * p; }

int main(int argc, char *argv[]) {
  int i, j, cnt;
  (void)argc;
  int N = atoi(argv[1]), M = atoi(argv[2]);
  float p = atof(argv[3]) / N;
  int *f = malloc((N + 1) * sizeof(int));
  for (j = 0; j <= N; j++)
    f[j] = 0;
  for (i = 0; i < M; i++, f[cnt]++)
    for (cnt = 0, j = 0; j <= N; j++)
      if (heads(p))
        cnt++;
  for (j = 0; j <= N; j++) {
    printf("%2d ", j);
    for (i = 0; i < f[j]; i += 10)
      printf("*");
    printf("\n");
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.20.exe 32 1000 0.1666667    E03.21.exe 32 1000 5
With p = 0.1666667 (~1/6):      With λ = 5:

 0 *                             0 *
 1 ***                           1 ***
 2 ******                        2 *******
 3 ***********                   3 **************
 4 ******************            4 ********************
 5 ******************            5 ******************
 6 ******************            6 *****************
 7 ************                  7 **********
 8 *********                     8 *******
 9 *****                         9 ****
10 ***                          10 **
11 *                            11 *
12 *                            12 *
13 *                            13 *
14                              14
15                              15
16                              16
17                              17
18                              18
19                              19
20                              20
21                              21
22                              22
23                              23
24                              24
25                              25
26                              26
27                              27
28                              28
29                              29
30                              30
31                              31
32                              32
--------------------------------------------------------------------- */

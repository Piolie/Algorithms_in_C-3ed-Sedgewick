/* ---------------------------------------------------------------------
                             EXERCISE 5.48
------------------------------------------------------------------------
Give the contents of the arrays maxKnown and itemKnown that are computed
by Program 5.13 for the call knap(17) with the items in Figure 5.16.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int val;
} Item;

#define N 5
static int *maxKnown;
static Item *itemKnown;
static Item items[N] = {[0] = {.size = 3, .val = 4},
                        [1] = {.size = 4, .val = 5},
                        [2] = {.size = 7, .val = 10},
                        [3] = {.size = 8, .val = 11},
                        [4] = {.size = 9, .val = 13}};

int knap(int M) {
  int i, space, max, maxi = 0, t;
  if (maxKnown[M] != -1)
    return maxKnown[M];
  for (i = 0, max = 0; i < N; i++)
    if ((space = M - items[i].size) >= 0)
      if ((t = knap(space) + items[i].val) > max) {
        max = t;
        maxi = i;
      }
  maxKnown[M] = max;
  itemKnown[M] = items[maxi];
  return max;
}

int main(void) {
  int M = 17;

  maxKnown = malloc((M + 1) * sizeof *maxKnown);
  for (int i = 0; i <= M; i++)
    maxKnown[i] = -1;
  itemKnown = malloc((M + 1) * sizeof *itemKnown);
  for (int i = 0; i <= M; i++)
    itemKnown[i] = (Item){0};

  int K = knap(M);

  printf("knap(%d) = %d\n", M, K);
  printf("maxKnown[%d]  = ", M);
  for (int i = 0; i <= M; i++)
    printf("%2d ", maxKnown[i]);

  printf("\n");

  printf("itemKnown[%d] = ", M);
  for (int i = 0; i <= M; i++)
    printf("{%2d, %2d}, ", itemKnown[i].size, itemKnown[i].val);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.48.exe
knap(17) = 24
maxKnown[17]  =  0  0  0  4  5  5  8 10 11 13 14 15 -1 18 20 -1 -1 24
itemKnown[17] = { 3,  4}, { 3,  4}, { 3,  4}, { 3,  4}, { 4,  5},
                { 4,  5}, { 3,  4}, { 7, 10}, { 8, 11}, { 9, 13},
                { 3,  4}, { 3,  4}, { 0,  0}, { 3,  4}, { 7, 10},
                { 0,  0}, { 0,  0}, { 3,  4},
--------------------------------------------------------------------- */

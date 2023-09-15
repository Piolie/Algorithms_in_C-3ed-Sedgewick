/* ---------------------------------------------------------------------
                             EXERCISE 3.33
------------------------------------------------------------------------
Develop a version of Program 3.9 that uses an array of indices to
implement the linked list (see Figure 3.6).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Notes:
  - I created a little auxiliary function to print the arrays.
  - Running the program with parameters 9 5 allows us to verify that
  the next array is in sync with the one shown in figure 3.6.
  - Also, initializing item and next like:
      for (i = 0; i < N; i++)
          item[i] = N-i;
      for (i = 1; i < N; i++)
          next[i] = i-1;
      next[0] = N-1;
  and starting with int x = 0 allows us to verify the result of
  Exercise 3.32. We can quickly check it by uncommenting the line:
    // #define E03_32
  and recompiling.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// #define E03_32

void print_array(int *arr, int N) {
  for (int i = 0; i < N; i++)
    printf(" %d", arr[i]);
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc < 3)
    return EXIT_FAILURE;

  int i;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  int *item = malloc(N * sizeof(*item));
  int *next = malloc(N * sizeof(*next));

#ifndef E03_32
  for (i = 0; i < N; i++)
    item[i] = i + 1;

  for (i = 0; i < N; i++)
    next[i] = i + 1;
  next[N - 1] = 0;

  int x = N - 1;
#else
  for (i = 0; i < N; i++)
    item[i] = N - i;

  for (i = 1; i < N; i++)
    next[i] = i - 1;
  next[0] = N - 1;

  int x = 0;
#endif

  printf("item[] = ");
  print_array(item, N);

  printf("next[] = ");
  print_array(next, N);

  while (x != next[x]) {
    for (i = 1; i < M; i++)
      x = next[x];
    printf("deleted item: %d ->", item[next[x]]);
    next[x] = next[next[x]];
    print_array(next, N);
  }
  printf("The leader is: %d\n", item[x]);
  free(item);
  free(next);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
// #define E03_32

./E03.33.exe 9 5
item[] =  1 2 3 4 5 6 7 8 9
next[] =  1 2 3 4 5 6 7 8 0
deleted item: 5 -> 1 2 3 5 5 6 7 8 0
deleted item: 1 -> 1 2 3 5 5 6 7 8 1
deleted item: 7 -> 1 2 3 5 5 7 7 8 1
deleted item: 4 -> 1 2 5 5 5 7 7 8 1
deleted item: 3 -> 1 5 5 5 5 7 7 8 1
deleted item: 6 -> 1 7 5 5 5 7 7 8 1
deleted item: 9 -> 1 7 5 5 5 7 7 1 1
deleted item: 2 -> 1 7 5 5 5 7 7 7 1
The leader is: 8
------------------------------------------------------------------------
#define E03_32

./E03.33.exe 9 5
item[] =  9 8 7 6 5 4 3 2 1
next[] =  8 0 1 2 3 4 5 6 7
deleted item: 5 -> 8 0 1 2 3 3 5 6 7
deleted item: 1 -> 7 0 1 2 3 3 5 6 7
deleted item: 7 -> 7 0 1 1 3 3 5 6 7
deleted item: 4 -> 7 0 1 1 3 3 3 6 7
deleted item: 3 -> 7 0 1 1 3 3 3 3 7
deleted item: 6 -> 7 0 1 1 3 3 3 1 7
deleted item: 9 -> 7 7 1 1 3 3 3 1 7
deleted item: 2 -> 7 1 1 1 3 3 3 1 7
The leader is: 8
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
                             EXERCISE 4.29
------------------------------------------------------------------------
Modify Program 4.8 to use an array of structures instead of parallel
arrays for the underlying data structure.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Doesn't really add much to the learning of ADTs.
--------------------------------------------------------------------- */

#include "UF.h"
#include <stdlib.h>

typedef struct {
  int id;
  int sz;
} node;

static node *arr;

void UFinit(int N) {
  int i;
  arr = malloc(N * sizeof(*arr));
  for (i = 0; i < N; i++) {
    arr[i].id = i;
    arr[i].sz = 1;
  }
}

int find(int x) {
  int i = x;
  while (i != arr[i].id)
    i = arr[i].id;
  return i;
}

int UFfind(int p, int q) { return (find(p) == find(q)); }

void UFunion(int p, int q) {
  int i = find(p), j = find(q);
  if (i == j)
    return;
  if (arr[i].sz < arr[j].sz) {
    arr[i].id = j;
    arr[j].sz += arr[i].sz;
  } else {
    arr[j].id = i;
    arr[i].sz += arr[j].sz;
  }
}

/* ---------------------------------------------------------------------
                             EXERCISE 5.60
------------------------------------------------------------------------
Change the divide-and conquer function for finding the maximum item in
an array (Program 5.6) to divide the array into k parts that differ by
at most 1 in size, recursively find the maximum in each part, and return
the maximum of the maxima.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item max(Item a[], int l, int r, int k) {
  if (l == r)
    return a[l];

  int N = (r - l + 1);
  if (k > N)
    k = N;
  int rem = N % k;

  Item maximum = 0;
  Item m;
  int d = (r - l + 1) / k;
  int right;

  for (int i = 0; i < rem; i++) {
    right = l + d;
    m = max(a, l, right, k);
    l = right + 1;
    if (m > maximum)
      maximum = m;
  }

  for (int i = rem; i < k; i++) {
    right = l + d - 1;
    m = max(a, l, right, k);
    l = right + 1;
    if (m > maximum)
      maximum = m;
  }

  return maximum;
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  int k = atoi(argv[2]);

  Item a[N];

  printf("a[%d] = ", N);
  for (int i = 0; i < N; i++) {
    a[i] = rand() / N;
    printf("%3d ", a[i]);
  }
  printf("\n");

  printf("max:%d\n", max(a, 0, N - 1, k));
}

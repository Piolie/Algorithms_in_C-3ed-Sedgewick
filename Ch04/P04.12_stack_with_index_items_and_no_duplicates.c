/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.12
                Stack with index items and no duplicates
------------------------------------------------------------------------
This pushdown-stack implementation assumes that all items are integers
between 0 and maxN-1, so that it can maintain an array t that has
a nonzero value corresponding to each item in the stack. The array
enables STACKpush to test quickly whether its argument is already on the
stack, and to take no action if the test succeeds. We use only one bit
per entry in t, so we could save space by using characters or bits
instead of integers, if desired (see Exercise 12.12).
--------------------------------------------------------------------- */

// #define DEBUG_P04_12

#include "STACK.h" // with Item_int.h
#include <stdlib.h>

static int *s, *t;
static int N;

void STACKinit(int maxN) {
  int i;
  s = malloc(maxN * sizeof(int));
  t = malloc(maxN * sizeof(int));
  for (i = 0; i < maxN; i++)
    t[i] = 0;
  N = 0;
}

int STACKempty(void) { return !N; }

void STACKpush(Item item) {
  if (t[item] == 1)
    return;
  s[N++] = item;
  t[item] = 1;
}

Item STACKpop(void) {
  N--;
  t[s[N]] = 0;
  return s[N];
}

#ifdef DEBUG_P04_12
#include <stdio.h>

typedef struct STACKnode *link;
struct STACKnode {
  Item item;
  link prev;
  link next;
};

void STACKdump(void) {
  for (int i = 0; i < N; i++) {
    ITEMshow(s[i]);
    printf(" ");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[2];
  STACKinit(atoi(argv[1]));
  for (char c = *a; c; c = *++a) {
    if (c >= 'A' && c <= 'Z') {
      printf("%c       ", c);
      STACKpush(c);
      STACKdump();
    } else if (c == '*') {
      printf("*   %c", STACKpop());
      printf("   ");
      STACKdump();
    }
  }
}
#endif // #ifdef DEBUG_P04_12

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
I've used Item_char for demonstration purposes.
P04.12_stack_with_index_items_and_no_duplicates.exe 100 "L A * S T I * N * F I R * S T * * * O U * T * * *"
L       L
A       L A
*   A   L
S       L S
T       L S T
I       L S T I
*   I   L S T
N       L S T N
*   N   L S T
F       L S T F
I       L S T F I
R       L S T F I R
*   R   L S T F I
S       L S T F I
T       L S T F I
*   I   L S T F
*   F   L S T
*   T   L S
O       L S O
U       L S O U
*   U   L S O
T       L S O T
*   T   L S O
*   O   L S
*   S   L
--------------------------------------------------------------------- */

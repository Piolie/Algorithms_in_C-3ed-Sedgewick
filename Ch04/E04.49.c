/* ---------------------------------------------------------------------
                             EXERCISE 4.49
------------------------------------------------------------------------
Modify the standard array-based stack implementation in Section 4.4
(Program 4.4) to disallow duplicates with a forget-the-old-item policy.
Use a brute-force approach that involves scanning through, and possibly
rearranging, the whole stack.
--------------------------------------------------------------------- */

// #define DEBUG_E04_49

#include "Item.h"
#include "STACK.h"
#include <stdlib.h>

static Item *s;
static int N;

void STACKinit(int maxN) {
  s = malloc(maxN * sizeof(Item));
  N = 0;
}

int STACKempty(void) { return N == 0; }

void STACKdel(int idx) {
  N--;
  for (int i = idx; i < N; i++)
    s[i] = s[i + 1];
}

void STACKpush(Item item) {
  for (int i = 0; i < N; i++)
    if (eq(s[i], item)) {
      STACKdel(i);
      break;
    }
  s[N++] = item;
}

Item STACKpop(void) { return s[--N]; }

#ifdef DEBUG_E04_49
#include <stdio.h>

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
#endif // #ifdef DEBUG_E04_49

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Same result as E04.47:
./E04.49.exe 10 "L A * S T I * N * F I R * S T * * * O U * T * * *"
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
S       L T F I S
T       L F I S T
*   T   L F I S
*   S   L F I
*   I   L F
O       L F O
U       L F O U
*   U   L F O
T       L F O T
*   T   L F O
*   O   L F
*   F   L
--------------------------------------------------------------------- */

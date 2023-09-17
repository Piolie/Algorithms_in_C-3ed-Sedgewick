/* ---------------------------------------------------------------------
                             EXERCISE 4.48
------------------------------------------------------------------------
Modify the standard array-based stack implementation in Section 4.4
(Program 4.4) to disallow duplicates with an ignore-the-new-item policy.
Use a brute-force approach that involves scanning through the whole
stack.
--------------------------------------------------------------------- */

// #define DEBUG_E04_48

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

void STACKpush(Item item) {
  for (int i = 0; i < N; i++)
    if (eq(s[i], item))
      return;
  s[N++] = item;
}

Item STACKpop(void) { return s[--N]; }

#ifdef DEBUG_E04_48
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
#endif // #ifdef DEBUG_E04_48

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing figure 4.9:
./E04.48.exe 10 "L A * S T I * N * F I R * S T * * * O U * T * * *"
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

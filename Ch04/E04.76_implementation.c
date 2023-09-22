/* ---------------------------------------------------------------------
                             EXERCISE 4.76
------------------------------------------------------------------------
Develop an ADT that allows clients to perform addition and
multiplication of arbitrarily long integers.
--------------------------------------------------------------------- */

// #define DEBUG_E04_76

#include "BIGINT.h" // #include "E04.76_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bigint {
  int N;
  unsigned char *digits;
};

void BIGINTshow(Bigint d) {
  for (int i = d->N - 1; i >= 0; i--)
    printf("%d", d->digits[i]);
  printf("\n");
}

Bigint BIGINTinit(char *s, int minlen) {
  Bigint d = malloc(sizeof(*d));
  int len = strlen(s);
  int N = len;
  if (len < minlen)
    N = minlen;

  d->N = N;
  d->digits = malloc(N * sizeof(*d));

  for (int i = 0; i < len; i++)
    d->digits[i] = s[len - 1 - i] - '0';
  for (int i = len; i < N; i++)
    d->digits[i] = 0;

  return d;
}

Bigint BIGINTadd(Bigint u, Bigint v) {
  int N = u->N + 1;
  Bigint w = BIGINTinit("", N);
  unsigned char k = 0;
  int j;
  for (j = 0; j < N - 1; j++) {
    unsigned char ujvjk = u->digits[j] + v->digits[j] + k;
    w->digits[j] = ujvjk % 10;
    k = ujvjk / 10;
  }
  w->digits[j] = k;
  return w;
}

Bigint BIGINTmult(Bigint u, Bigint v) {
  int M = u->N;
  int N = v->N;
  Bigint w = BIGINTinit("", N + M);
  for (int j = 0; j < N; j++) {
    if (v->digits[j] == 0) {
      w->digits[j + M] = 0;
      continue;
    }
    unsigned char t, k = 0;
    for (int i = 0; i < M; i++) {
      t = u->digits[i] * v->digits[j] + w->digits[i + j] + k;
      w->digits[i + j] = t % 10;
      k = t / 10;
    }
    w->digits[j + M] = k;
  }
  return w;
}

#ifdef DEBUG_E04_76
int main(void) {
  Bigint d1 = BIGINTinit("9999", 0);
  Bigint d2 = BIGINTinit("0001", 0);
  Bigint d3 = BIGINTinit("123", 0);
  Bigint d4 = BIGINTinit("456", 0);
  BIGINTshow(d1);
  printf("+\n");
  BIGINTshow(d2);
  printf("=\n");
  BIGINTshow(BIGINTadd(d1, d2));
  printf("\n");
  BIGINTshow(d3);
  printf("*\n");
  BIGINTshow(d4);
  printf("=\n");
  BIGINTshow(BIGINTmult(d3, d4));
}
#endif // #ifdef DEBUG_E04_76

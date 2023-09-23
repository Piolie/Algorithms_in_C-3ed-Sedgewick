/* ---------------------------------------------------------------------
                             EXERCISE 4.82
------------------------------------------------------------------------
Provide an implementation for your string ADT interface from
Exercise 4.81, using the C string library where appropriate.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Just like the functions from the standard library, these implementations
don't check any bounds and don't stop until a terminating '\0' is found.
--------------------------------------------------------------------- */

// #define DEBUG_E04_82

#include "STR.h" // #include "E04.81.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
  int bufsz;
  char *s;
};

void STRshow(String str) { printf("%s\n", str->s); }

String STRinit(char *str, int minlen) {
  int bufsz = strlen(str);
  if (bufsz < minlen)
    bufsz = minlen;
  bufsz++;

  String res = malloc(sizeof(*res));
  res->bufsz = bufsz;
  res->s = malloc(bufsz * sizeof(*res->s));
  strcpy(res->s, str);
  return res;
}

int STRcompare(String lhs, String rhs) { return strcmp(lhs->s, rhs->s); }

String STRconcat(String first, String last) {
  first->s = strcat(first->s, last->s);
  return first;
}

String STRcopy(String to, String from) {
  strcpy(to->s, from->s);
  return to;
}

int STRlen(String str) { return strlen(str->s); }

#ifdef DEBUG_E04_82
int main(void) {
  String s1 = STRinit("Hello, world!", 30);
  String s2 = STRinit(" cruel world!", 30);
  STRshow(s1);
  STRshow(s2);
  printf("len s1 = %d\n", STRlen(s1));
  printf("len s2 = %d\n", STRlen(s2));
  printf("s1 == s1: %s\n", STRcompare(s1, s1) ? "NO!" : "YES!");
  printf("s1 == s2: %s\n", STRcompare(s1, s2) ? "NO!" : "YES!");
  STRshow(STRconcat(s1, s2));
  STRshow(STRcopy(s1, s2));
  STRshow(s1);
  STRshow(s2);
}
#endif // #ifdef DEBUG_E04_82

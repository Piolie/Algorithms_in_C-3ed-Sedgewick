/* ---------------------------------------------------------------------
                             EXERCISE 4.83
------------------------------------------------------------------------
Provide an implementation for your string ADT interface from
Exercise 4.81, using a linked list for the underlying representation.
Analyze the worst-case running time of each operation.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Following the lead of E04.70.

I won't analyze the running time.
--------------------------------------------------------------------- */

// #define DEBUG_E04_83

#include "STR.h" // #include "E04.81.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STRnode *link;
struct STRnode {
  char c;
  link next;
};

struct string {
  link head;
};

link NEW(char c, link next) {
  link x = malloc(sizeof *x);
  x->c = c;
  x->next = next;
  return x;
}

void STRshow(String str) {
  for (link t = str->head; t != NULL; t = t->next)
    if (t->c)
      printf("%c", t->c);
    else
      break;
  printf("\n");
}

String STRinit(char *str, int minlen) {
  int len = strlen(str);
  String s = malloc(sizeof(*s));

  s->head = NEW(str[0], NULL);
  link t = s->head;
  for (int i = 1; i < len; i++) {
    t->next = NEW(str[i], NULL);
    t = t->next;
  }

  for (int i = len; i < minlen + 1; i++) {
    t->next = NEW(0, NULL);
    t = t->next;
  }
  return s;
}

int STRcompare(String str1, String str2) {
  link t1 = str1->head;
  link t2 = str2->head;
  while (t1 != NULL && t2 != NULL) {
    if (t1->c < t2->c)
      return -1;
    if (t1->c > t2->c)
      return 1;
    t1 = t1->next;
    t2 = t2->next;
  }
  if (t2) // test!
    return 1;
  if (t1)
    return -1;

  return 0;
}

String STRconcat(String first, String last) {
  link t1;
  link t2;
  for (t1 = first->head; t1->c != 0; t1 = t1->next)
    ;
  for (t2 = last->head; t2->c != 0; t2 = t2->next) {
    t1->c = t2->c;
    t1 = t1->next;
  }
  t1->c = 0;
  return first;
}

String STRcopy(String to, String from) {
  link t1 = from->head;
  link t2 = to->head;
  while (t1->c != 0) {
    t2->c = t1->c;
    t1 = t1->next;
    t2 = t2->next;
  }
  t2->c = 0;
  return to;
}

int STRlen(String str) {
  int len = 0;
  for (link t = str->head; t != NULL; t = t->next)
    len++;
  return --len;
}

#ifdef DEBUG_E04_83
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
#endif // #ifdef DEBUG_E04_83

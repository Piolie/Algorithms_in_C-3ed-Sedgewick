/* ---------------------------------------------------------------------
                             EXERCISE 3.56
------------------------------------------------------------------------
Write a program that takes a string as argument, and that prints out a
table giving, for each character that occurs in the string, the
character and its frequency of occurrence.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I won't bother skipping already counted characters since the statement
does not require it. Also, upper and lower case letters are considered
different.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

int count_character(char c, char *s) {
  int count = 0;
  while (*s) {
    if (*s++ == c)
      count++;
  }
  return count;
}

int main(int argc, char *argv[]) {
  char *s = argv[1];
  printf("String: %s\n", s);
  printf("char count\n");
  printf("---- -----\n");
  while (*s) {
    printf("%c    %d\n", *s, count_character(*s, argv[1]));
    s++;
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.56.exe "This is the string to be counted."
String: This is the string to be counted.
char count
---- -----
T    1
h    2
i    3
s    3
     6
i    3
s    3
     6
t    4
h    2
e    3
     6
s    3
t    4
r    1
i    3
n    2
g    1
     6
t    4
o    2
     6
b    1
e    3
     6
c    1
o    2
u    1
n    2
t    4
e    3
d    1
.    1
--------------------------------------------------------------------- */

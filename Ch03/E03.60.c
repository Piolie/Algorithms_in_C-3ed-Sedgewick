/* ---------------------------------------------------------------------
                             EXERCISE 3.60
------------------------------------------------------------------------
Write a program that replaces substrings of more than one blank in a
given string by exactly one blank.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
By "blanks" I understand "spaces", that is: ' '.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

char *condense_blanks(char *s) {
  char *dest = s;
  char *ret = s;
  while ((*dest++ = *s))
    if (*s == ' ')
      while (*++s == ' ')
        ;
    else
      s++;
  return ret;
}

int main(int argc, char *argv[]) {
  (void)argc;
  printf("String           : %s\n", argv[1]);
  printf("Condensed string : %s\n", condense_blanks(argv[1]));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.60.exe "       This is a   string with      many     spaces .     ."
String           :        This is a   string with      many     spaces .     .
Condensed string :  This is a string with many spaces . .
--------------------------------------------------------------------- */

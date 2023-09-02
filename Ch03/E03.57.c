/* ---------------------------------------------------------------------
                             EXERCISE 3.57
------------------------------------------------------------------------
Write a program that checks whether a given string is a palindrome
(reads the same backward or forward), ignoring blanks. For example, your
program should report success for the string if i had a hifi.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I implemented two approaches:
  1. In-place remove the spaces in the given string. (remove_spaces
  should only be passed a pointer to char. Passing it a string literal
  invokes undefined behavior.) Then use the simple is_palindrome1.
  2. Ignore the spaces in-place with is_palindrome2.

I found the second one more pleasing.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

void remove_spaces(char *s) {
  char *dest = s;
  while (*s) {
    if (*s != ' ')
      *dest++ = *s;
    s++;
  }
  *dest = '\0';
}

int is_palindrome1(char *s) {
  size_t i, len = strlen(s);
  for (i = 0; i < len / 2; i++)
    if (s[i] != s[len - i - 1])
      return 0;
  return 1;
}

int is_palindrome2(char *s) {
  size_t len = strlen(s);
  if (len == 0)
    return 1;

  size_t i = 0, j = len - 1;
  while (j > i) {
    if (s[i] == ' ')
      i++;
    else if (s[j] == ' ')
      j--;
    else if (s[i] != s[j])
      return 0;
    else
      i++, j--;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  (void)argc;
  char *s = argv[1];
  remove_spaces(s);
  printf("Is palindrome1?: %s\n", is_palindrome1(s) ? "Yes" : "No");
  printf("Is palindrome2?: %s\n", is_palindrome2(s) ? "Yes" : "No");
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
E03.57.exe "if i had a hifi"
Is palindrome1?: Yes
Is palindrome2?: Yes

E03.57.exe "12344321"
Is palindrome1?: Yes
Is palindrome2?: Yes

E03.57.exe "123454321"
Is palindrome1?: Yes
Is palindrome2?: Yes

E03.57.exe "  1 234 543 2 1        "
Is palindrome1?: Yes
Is palindrome2?: Yes

E03.57.exe ""
Is palindrome1?: Yes
Is palindrome2?: Yes

E03.57.exe " "
Is palindrome1?: Yes
Is palindrome2?: Yes

E03.57.exe "1234567890"
Is palindrome1?: No
Is palindrome2?: No

E03.57.exe "1122"
Is palindrome1?: No
Is palindrome2?: No
--------------------------------------------------------------------- */

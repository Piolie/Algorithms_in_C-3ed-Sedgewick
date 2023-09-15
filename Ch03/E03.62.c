/* ---------------------------------------------------------------------
                             EXERCISE 3.62
------------------------------------------------------------------------
Write an efficient program that finds the length of the longest sequence
of blanks in a given string, examining as few characters in the string
as possible. Hint: Your program should become faster as the length of
the sequence of blanks increases.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Ideas brought (stolen?) from [Algorithm to find lenth of longest sequence of
blanks in a given string](https://stackoverflow.com/questions/2616932/).

Suppose the longest sequence found thus far is of length M.
0. If b > s_len - M, no longer sequence can fit in the remaining string,
so we end the search.
1. If we now find a blank at position b, we can go to b+M-1 and check if
that is also a blank.
2. If it is a blank, we have to check backwards from b+M-2 down to b.
  2a. If all chars are blanks, then we found a sequence of at least
      the same length, so we start checking forwards, incrementing M.
  2b. Otherwise, the first non-blank is the new value of b.
3. If it's not blank, then we increment b by M.

The problem with this algorithm is that it misbehaves while M < 2, since
M-1 < 0 and M-2 < 0. Thus, we have a first part that loops until it
finds a sequence of at least 2 blanks.

I'll assume the string is given in argv[1].
--------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  (void)argc;
  char *s = argv[1];
  size_t i;
  size_t M = 0;
  size_t b = 0;
  size_t s_len = strlen(s);

  /* find the first blank sequence greater than 1 */
  while (b < s_len)
    if (s[b++] == ' ') {
      M++;
      while (s[b++] == ' ')
        M++;
      if (M > 1)
        break;
    }
  while (b < s_len - M) // 0
  {
    if (s[b] == ' ')
      if (s[b + M - 1] == ' ') // 1
      {
        for (i = M - 2; i > 0; i--) // 2
          if (s[b + i] != ' ') {
            b += i + 1; // 2b
            break;
          }
        if (i == 0) // 2a
        {
          while (s[b + M] == ' ')
            M++;
          b += M;
        }
      } else
        b += M; // 3
    else
      b++;
  }
  printf("Length of the longest sequence of blanks: %zd\n", M);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.62.exe ""
Length of the longest sequence of blanks: 0

./E03.62.exe " "
Length of the longest sequence of blanks: 1

./E03.62.exe " 1  1   1    1"
Length of the longest sequence of blanks: 4

./E03.62.exe "            1                 1   1    1"
Length of the longest sequence of blanks: 17

./E03.62.exe "$(cat E03.62.c)"
Length of the longest sequence of blanks: 33
--------------------------------------------------------------------- */

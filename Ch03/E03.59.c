/* ---------------------------------------------------------------------
                             EXERCISE 3.59
------------------------------------------------------------------------
Write a program that takes a string as argument and reads a sequence of
words (sequences of characters separated by blank space) from standard
input, printing out those that appear as substrings somewhere in the
argument string.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I haven't bothered dealing with the corner cases (which makes the output
somewhat inconsistent), for example:
  - words that aren't surrounded by spaces (at the beginning/end of
    the string);
  - case sensitivity;
  - spaces other than ' ' ('\n', '\r');
  - etc.
--------------------------------------------------------------------- */

#define MAX_WORD_LENGHT 20

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  (void)argc;
  char *argument = argv[1];
  char word[MAX_WORD_LENGHT] = "\0";

  printf("Argument: %s\n", argument);
  printf("Enter sequence of words: ");
  char c = 0;
  int i = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (i == 0) // ignore words consisting only of a " "
        continue;
      word[i] = 0;
      i = 0;
      if (strstr(argument, word))
        printf("->%s\n", word);
    } else
      word[i++] = c;
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E03.59.exe "This is the argument string"
Enter sequence of words: This is the argument string 
->This
->is
->the
->argument
->string
This is the argument string 
->is
->the
->argument
->string
^Z

./E03.59.exe "This is the argument string"
Enter sequence of words: this that argument strong string 
->argument
->string
^Z
--------------------------------------------------------------------- */

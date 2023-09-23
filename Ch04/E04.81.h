/* ---------------------------------------------------------------------
                             EXERCISE 4.81
------------------------------------------------------------------------
Write an interface for a character-string ADT, which includes operations
for creating a string, comparing two strings, concatenating two strings,
copying one string to another, and returning the string length.
--------------------------------------------------------------------- */

typedef struct string *String;
void STRshow(String str);
String STRinit(char *str, int minlen);
int STRcompare(String lhs, String rhs);
String STRconcat(String first, String last);
String STRcopy(String to, String from);
int STRlen(String str);

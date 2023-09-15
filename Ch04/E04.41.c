/* ---------------------------------------------------------------------
                             EXERCISE 4.41
------------------------------------------------------------------------
Write a client that tests your deque ADTs (Exercise 4.37) by reading, as
the first argument on the command line, a string of commands like those
given in Exercise 4.34 then performing the indicated operations. Add a
function DQdump to the interface and implementations, and print out the
contents of the deque after each operation, in the style of Figure 4.6.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I've added another parameter to the command line, to specify the max
number of elements for the deque.

Notice that, because figure 4.6 illustrates a FIFO, the sequence to
reproduce it requires the string of commands to be converted to
lowercase, with '*' replaced by '+'. The reason is that in a FIFO we put
at the end and get from the beginning. Thus, according to E04.37, we
have to use lowercase and '+'.
--------------------------------------------------------------------- */

#include "DEQUE.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  DQinit(atoi(argv[1]));

  char c;
  while ((c = *argv[2]++)) {
    if (c >= 'A' && c <= 'Z') {
      DQput_beg(c);
      printf("%c       ", c);
      DQdump();
    }

    if (c >= 'a' && c <= 'z') {
      DQput_end(c);
      printf("%c       ", c);
      DQdump();
    }

    if (c == '+') {
      printf("+   %c", DQget_beg());
      printf("   ");
      DQdump();
    }

    if (c == '*') {
      printf("*   %c", DQget_end());
      printf("   ");
      DQdump();
    }
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Same as E04.34:
./E04.41.exe 5 "E A s + Y + Q U E * * + s t + * + I O * n + + *."
E       E
A       A E
s       A E s
+   A   E s
Y       Y E s
+   Y   E s
Q       Q E s
U       U Q E s
E       E U Q E s
*   s   E U Q E
*   E   E U Q
+   E   U Q
s       U Q s
t       U Q s t
+   U   Q s t
*   t   Q s
+   Q   s
I       I s
O       O I s
*   s   O I
n       O I n
+   O   I n
+   I   n
*   n

Same as figure 4.6:
./E04.41.exe 5 "f i r s + t + i n + + + f i + r s + + + t + o u t + + + + +"
f       f
i       f i
r       f i r
s       f i r s
+   f   i r s
t       i r s t
+   i   r s t
i       r s t i
n       r s t i n
+   r   s t i n
+   s   t i n
+   t   i n
f       i n f
i       i n f i
+   i   n f i
r       n f i r
s       n f i r s
+   n   f i r s
+   f   i r s
+   i   r s
t       r s t
+   r   s t
o       s t o
u       s t o u
t       s t o u t
+   s   t o u t
+   t   o u t
+   o   u t
+   u   t
+   t
--------------------------------------------------------------------- */

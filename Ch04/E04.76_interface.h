/* ---------------------------------------------------------------------
                             EXERCISE 4.76
------------------------------------------------------------------------
Develop an ADT that allows clients to perform addition and
multiplication of arbitrarily long integers.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'll keep the integers as arrays of unsigned chars, where each char will
store a digit from 0-9. Other bases could be used. The most significant
digit will be at the end of the array. All integers are assumed
nonnegative.

There is an init function, that takes a null terminated string
consisting exclusively of a sequence of digits '0' to '9' and an int
parameter a returns a Bigint with at least minlen digits.

For the addition, the number of digits in the first operand is assumed
to be the same as that of the second.

The algorithms are adapted from:
  Knuth, Donald (1998). Seminumerical Algorithms. The Art of Computer
  Programming. Vol. 2 (3rd ed.). Reading, MA: Addison-Wesley
  Professional. ISBN 978-0-201-89684-8. §4.3.1 ("The Classical
  Algorithms"), "Algorithm A" and "Algorithm M". pp. 265-268.
--------------------------------------------------------------------- */

typedef struct bigint *Bigint;
void BIGINTshow(Bigint d);
Bigint BIGINTinit(char *s, int minlen);
Bigint BIGINTadd(Bigint u, Bigint v);
Bigint BIGINTmult(Bigint u, Bigint v);

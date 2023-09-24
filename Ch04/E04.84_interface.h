/* ---------------------------------------------------------------------
                             EXERCISE 4.84
------------------------------------------------------------------------
Write an interface and an implementation for an index set ADT, which
processes sets of integers in the range 0 to M - 1 (where M is a defined
constant) and includes operations for creating a set, computing the
union of two sets, computing the intersection of two sets, computing the
complement of a set, computing the difference of two sets, and printing
out the contents of a set. In your implementation, use an array of M - 1
0-1 values to represent each set.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The addelement function returns 1 if the element wasn't already in the
set, otherwise it returns 0; while the remelement function returns 1 if
the element was present, 0 if it was not.
--------------------------------------------------------------------- */

typedef struct set *Set;
Set SETcreate(int M);
int SETaddelement(Set set, int e);
int SETremelement(Set set, int e);
Set SETunion(Set s1, Set s2);
Set SETinter(Set s1, Set s2);
Set SETcompl(Set s);
Set SETdiff(Set s1, Set s2);
void SETprint(Set s);

/* ---------------------------------------------------------------------
                             EXERCISE 4.19
------------------------------------------------------------------------
Suppose that you change the pushdown-stack interface to replace test
if empty by count, which should return the number of items currently in
the data structure. Provide implementations for count for the array
representation (Program 4.4) and the linked-list representation
(Program 4.5).
--------------------------------------------------------------------- */

// array implementation
int count(void){return N};

// linked-list implementation
int count(void) {
  int c = 0;
  for (link t = head; t; t = t->next)
    c++;
  return c;
};

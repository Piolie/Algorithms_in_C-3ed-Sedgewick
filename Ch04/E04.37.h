/* ---------------------------------------------------------------------
                             EXERCISE 4.37
------------------------------------------------------------------------
Write an interface for the deque ADT.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I've included the functions DQfull and DQdump in the interface, and will
implement them in E04.38 and E04.39, in preparation for E04.41. There is
also a "private" DQprettydump, which shows where the head and tail are,
intended for debugging.

Retrospectively, it would have been easier to keep counts of the max
number of nodes and number of nodes assigned to compute the empty and
full functions in an implementation-independent manner. As it is now,
the functions are different whether the underlying data structure is an
array, a singly or doubly linked-list (circular or not), or some other.
--------------------------------------------------------------------- */

void DQinit(int);
int DQempty(void);
int DQfull(void);
void DQput_beg(Item);
void DQput_end(Item);
Item DQget_beg(void);
Item DQget_end(void);
void DQdump(void);

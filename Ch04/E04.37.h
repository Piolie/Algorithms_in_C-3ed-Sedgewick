/* ---------------------------------------------------------------------
                             EXERCISE 4.37
------------------------------------------------------------------------
Write an interface for the deque ADT.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I've included the functions DQfull and DQdump in the interface, and will
implement them in E04.38 and E04.39, in preparation for E04.41.
--------------------------------------------------------------------- */

void DQinit(int);
int DQempty(void);
int DQfull(void);
void DQput_beg(Item);
void DQput_end(Item);
Item DQget_beg(void);
Item DQget_end(void);
void DQdump(void);

/* ---------------------------------------------------------------------
                             EXERCISE 4.66
------------------------------------------------------------------------
Write an interface for a first-class pushdown-stack ADT.
--------------------------------------------------------------------- */

typedef struct stack *Stack;
void STACKdump(Stack);
Stack STACKinit(int maxN);
int STACKempty(Stack);
void STACKpush(Stack, Item);
Item STACKpop(Stack);

/* ---------------------------------------------------------------------
                             EXERCISE 4.59
------------------------------------------------------------------------
Create a first-class ADT for use in programs that process playing cards.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The statement is too vague: what kind of cards should be available? what
operations should the interface expose? How should those work? I'll
stick to the bare minimum.

The macros from E04.04 are converted to functions here.
Since C doesn't allow forward references to enum types, so we can't do
things like:
  typedef enum rank Rank;
  typedef enum suit Suit;
and then define rank as an enum in the implementation. We'll have to be
explicit right in this header.
--------------------------------------------------------------------- */

typedef enum { Ace = 1, Jack = 11, Queen = 12, King = 13 } Rank;
typedef enum { Clubs, Diamonds, Hearts, Spades } Suit;
typedef struct card *Card;
Rank CARDrank(Card);
Suit CARDsuit(Card);
void CARDshow(Card);
int CARDeq(Card, Card);
Card CARDinit(Rank, Suit);

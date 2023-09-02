/* ---------------------------------------------------------------------
                              EXERCISE 3.6
------------------------------------------------------------------------
Define a struct suitable for representing a playing card.
--------------------------------------------------------------------- */

typedef enum { Ace = 1, Jack = 11, Queen = 12, King = 13 } RANK;
typedef enum { Clubs, Diamonds, Hearts, Spades } SUIT;

typedef struct card {
  RANK rank;
  SUIT suit;
} CARD;

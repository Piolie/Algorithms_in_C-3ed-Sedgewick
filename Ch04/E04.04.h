/* ---------------------------------------------------------------------
                              EXERCISE 4.4
------------------------------------------------------------------------
Give definitions for Item and ITEMshow (see Exercise 4.3) that might be
used in programs that process playing cards.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'm borrowing the struct from E03.06.
--------------------------------------------------------------------- */

typedef enum { Ace = 1, Jack = 11, Queen = 12, King = 13 } RANK;
typedef enum { Clubs, Diamonds, Hearts, Spades } SUIT;

typedef struct card {
  RANK rank;
  SUIT suit;
} Item;

#define eq(A, B) ((A).rank == (B).rank && (A).suit == (B).suit)
#define ITEMshow(X)                                                            \
  {                                                                            \
    switch ((X).rank) {                                                        \
    case Ace:;                                                                 \
      printf("Ace");                                                           \
      break;                                                                   \
    case Jack:                                                                 \
      printf("Jack");                                                          \
      break;                                                                   \
    case Queen:                                                                \
      printf("Queen");                                                         \
      break;                                                                   \
    case King:                                                                 \
      printf("King");                                                          \
      break;                                                                   \
    default:                                                                   \
      printf("%d", (X).rank);                                                  \
      break;                                                                   \
    };                                                                         \
    printf(" of ");                                                            \
    switch ((X).suit) {                                                        \
    case Clubs:                                                                \
      printf("Clubs");                                                         \
      break;                                                                   \
    case Diamonds:                                                             \
      printf("Diamonds");                                                      \
      break;                                                                   \
    case Hearts:                                                               \
      printf("Hearts");                                                        \
      break;                                                                   \
    case Spades:                                                               \
      printf("Spades");                                                        \
      break;                                                                   \
    }                                                                          \
  }

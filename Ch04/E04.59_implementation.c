/* ---------------------------------------------------------------------
                             EXERCISE 4.59
------------------------------------------------------------------------
Create a first-class ADT for use in programs that process playing cards.
--------------------------------------------------------------------- */

#include "CARDS.h" // #include "E04.59_interface.h"
#include <stdlib.h>
#include <stdio.h>

struct card {
  Rank rank;
  Suit suit;
};

Rank CARDrank(Card card) { return card->rank; }

Suit CARDsuit(Card card) { return card->suit; }

int CARDeq(Card A, Card B) {
  return (A->rank == B->rank) && (A->suit == B->suit);
}

void CARDshow(Card card) {
  switch (card->rank) {
  case Ace:;
    printf("Ace");
    break;
  case Jack:
    printf("Jack");
    break;
  case Queen:
    printf("Queen");
    break;
  case King:
    printf("King");
    break;
  default:
    printf("%d", card->rank);
    break;
  };
  printf(" of ");
  switch (card->suit) {
  case Clubs:
    printf("Clubs");
    break;
  case Diamonds:
    printf("Diamonds");
    break;
  case Hearts:
    printf("Hearts");
    break;
  case Spades:
    printf("Spades");
    break;
  }
}

Card CARDinit(Rank rank, Suit suit) {
  Card card = malloc(sizeof(*card));
  card->rank = rank;
  card->suit = suit;
  return card;
}

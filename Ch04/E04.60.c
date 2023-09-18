/* ---------------------------------------------------------------------
                             EXERCISE 4.60
------------------------------------------------------------------------
Write a program to determine empirically the probability that various
poker hands are dealt, using your ADT from Exercise 4.59.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Borrowing heavily from E04.45.
Borrowing heavily from E04.45.
This program generates cards at random, which entails the possibility
that a card appear twice in the same hand. It would be more realistic to
initialize a deck during each try and draw randomly from there. This
could be done using the random queue from previous exercises.
--------------------------------------------------------------------- */

#include "CARDS.h" // #include "E04.59_interface.h"
#include <stdlib.h>
#include <stdio.h>

const int STD_DECK_SIZE = 52;
const int HAND_SIZE = 5;

Card random_card(void) {
  Rank rank = rand() % 13 + 1;
  Suit suit = rand() % 3;
  return CARDinit(rank, suit);
}

int main(int argc, char *argv[]) {
  (void)argc;
  const int MAX_TRIES = atoi(argv[1]);
  printf("Generating poker hand...\n");
  Card hand[HAND_SIZE];
  for (int i = 0; i < HAND_SIZE; i++) {
    hand[i] = random_card();
    CARDshow(hand[i]);
    printf("\n");
  }

  int tries;
  int matches;
  int times = 0;
  for (tries = 0; tries < MAX_TRIES; tries++) {
    matches = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
      Card card = random_card();
      for (int j = 0; j < HAND_SIZE; j++)
        if (CARDeq(card, hand[j]))
          matches++;
    }
    if (matches == 5)
      times++;
  }
  printf("Probability of that the above hand is dealt = %d in %d\np = %f", times, tries, 1.0*times/tries);
}

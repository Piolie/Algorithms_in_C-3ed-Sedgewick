/* ---------------------------------------------------------------------
                             EXERCISE 4.45
------------------------------------------------------------------------
Write a client that takes an integer N from the first argument on the
command line, then prints out N poker hands, by putting N items on a
random queue (see Exercise 4.4), then printing out the result of picking
five cards at a time from the queue.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Instead of "putting N items on a random queue," (which ones?) I'll
simply use a standard 52-card deck and pick five cards from there, N
times.
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  const int STD_DECK_SIZE = 52;

  for (int hand = 1; hand <= N; hand++) {
    QUEUEinit(STD_DECK_SIZE);
    printf("Mixing cards...\n");
    for (RANK rank = Ace; rank <= King; rank++)
      for (SUIT suit = Clubs; suit <= Spades; suit++) {
        Item card = malloc(sizeof *card);
        card->rank = rank;
        card->suit = suit;
        QUEUEput(card);
      }

    printf("Hand %d is:\n", hand);
    for (int i = 0; i < 5; i++) {
      Item tmp = QUEUEget();
      ITEMshow(tmp);
      printf("\n");
    }
    printf("\n");
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.45.exe 3
Mixing cards...
Hand 1 is:
Jack of Diamonds
2 of Hearts
10 of Clubs
Jack of Spades
6 of Diamonds

Mixing cards...
Hand 2 is:
6 of Clubs
2 of Clubs
3 of Hearts
4 of Spades
10 of Clubs

Mixing cards...
Hand 3 is:
10 of Diamonds
Queen of Diamonds
9 of Diamonds
6 of Spades
8 of Diamonds
--------------------------------------------------------------------- */
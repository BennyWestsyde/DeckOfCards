//
// Created by Bennett Westfall on 10/17/23.
//

#ifndef DECKOFCARDS_DECK_H
#define DECKOFCARDS_DECK_H

#include "piles.h"

class Deck: public Pile {
public:
    Deck();
};

Deck::Deck() {
    for(int i = 1; i <= 13; i++){
        cards.emplace_back(static_cast<Rank>(i), Suit(SPADES));
        cards.emplace_back(static_cast<Rank>(i), Suit(HEARTS));
        cards.emplace_back(static_cast<Rank>(i), Suit(DIAMONDS));
        cards.emplace_back(static_cast<Rank>(i), Suit(CLUBS));
    }
    this->size = 52;
    this->direction = FACE_DOWN;
    shuffle();
}

#endif //DECKOFCARDS_DECK_H

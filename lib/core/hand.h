//
// Created by Bennett Westfall on 10/17/23.
//

#ifndef DECKOFCARDS_HAND_H
#define DECKOFCARDS_HAND_H

#include "piles.h"

class Hand: public Pile {
public:
    Hand();
};

Hand::Hand() {
    this->size = 0;
    this->cards = std::__1::vector<Card>();
    this->direction = FACE_DOWN;
}

#endif //DECKOFCARDS_HAND_H

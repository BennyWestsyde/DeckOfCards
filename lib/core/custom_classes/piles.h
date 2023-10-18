//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_PILES_H
#define DECKOFCARDS_PILES_H

#include <vector>
#include "../base_classes/cards.h"
#include "../base_classes/suit.h"
#include "../base_classes/set.h"


class Pile : public Set {
public:
    // Constructors and Destructor
    Pile() {
        this->size = 0;
        this->cards = std::vector<Card>();
        this->direction = FACE_UP;
    };

    // Methods



protected:
    // Variables
    Direction direction;

};

#endif //DECKOFCARDS_PILES_H

//
// Created by Bennett Westfall on 10/18/23.
//
#include "deck.h"

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
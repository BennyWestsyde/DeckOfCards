//
// Created by Bennett Westfall on 10/16/23.
//

#include "cards.h"
#include "../../piles.h"
#include <iostream>
#include <vector>
#include "suit.h"


// Constructor and Destructor

Suit::Suit(SuitType suit) : suit(suit) {
    this->suit = suit;
    if(this->suit == SPADES || this->suit == CLUBS){
        this->color = BLACK;
    } else {
        this->color = RED;
    }
}

Suit::~Suit() = default;

// Operator Overloads

bool Suit::operator==(const Suit &rhs)  const {
    return std::tie(suit, color) == std::tie(rhs.suit, rhs.color);
}

bool Suit::operator!=(const Suit &rhs) const {
    return !((Suit) rhs == *this);
}

bool Suit::operator<(const Suit &rhs) const {
    return suit < rhs.suit;
}

bool Suit::operator>(const Suit &rhs) const {
    return rhs < *this;
}

bool Suit::operator<=(const Suit &rhs) const {
    return !(rhs < *this);
}

bool Suit::operator>=(const Suit &rhs) const {
    return !(*this < rhs);
}

// Getters and Setters

SuitType Suit::getSuit() const {
    return suit;
}

Color Suit::getColor() const {
    return color;
}

void Suit::setSuit(SuitType newSuit) {
    Suit::suit = newSuit;
}

void Suit::setColor(Color newColor) {
    Suit::color = newColor;
}

std::ostream &operator<<(std::ostream &os, const Suit &suit) {
    switch (suit.getSuit()) {
        case SPADES:
            os << "Spades";
        case HEARTS:
            os << "Hearts";
        case DIAMONDS:
            os << "Diamonds";
        case CLUBS:
            os << "Clubs";
        default:
            os << "Invalid Suit";
    }
    return os;
}




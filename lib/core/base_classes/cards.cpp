//
// Created by Bennett Westfall on 10/16/23.
//

#include <vector>
#include <iostream>
#include "../custom_classes/piles.h"
#include "cards.h"
#include <string>

/*
 * Constructor and Destructor
 */

Card::Card(Rank rank, const Suit& suit) : rank(rank), suit(suit) {
    this->rank = rank;
    this->suit = suit;
}


/*
 * Methods
 */

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.rank << " of " << card.suit;
    return os;
}

/*
 * Operator Overloads
 */

bool Card::operator==(const Card &rhs) const {
    return std::tie(rank,suit) == std::tie(rhs.rank,rhs.suit);
}

bool Card::operator!=(const Card &rhs) const {
    return !(rhs == *this);
}

bool Card::operator<(const Card &rhs) const {
    if(std::tie(rank) == std::tie(rhs.rank)){
        return suit < rhs.suit;
    }
    return rank < rhs.rank;
}

bool Card::operator>(const Card &rhs) const {
    return rhs < *this;
}

bool Card::operator<=(const Card &rhs) const {
    return !(std::tie(rhs) < std::tie(*this));
}

bool Card::operator>=(const Card &rhs) const {
    return !(std::tie(*this) < std::tie(rhs));
}



/*
 * Getters and Setters
 */

Rank Card::getRank() const {
    return this->rank;
}

void Card::setRank(Rank newRank) {
    Card::rank = newRank;
}

Suit Card::getSuit() const {
    return this->suit;
}

void Card::setSuit(const Suit &newSuit) {
    Card::suit = newSuit;
}

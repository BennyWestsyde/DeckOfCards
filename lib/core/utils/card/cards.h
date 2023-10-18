//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_CARDS_H
#define DECKOFCARDS_CARDS_H

#include <tuple>
#include "suit.h"

enum Rank {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};


class Card {
public:
    // Constructor and Destructor
    Card(Rank rank, const Suit& suit);
    ~Card();

    // Methods

    friend std::ostream &operator<<(std::ostream &os, const Card &card);

    // Operator Overloads
    bool operator==(const Card &rhs) const;
    bool operator!=(const Card &rhs) const;
    bool operator<(const Card &rhs) const;
    bool operator>(const Card &rhs) const;
    bool operator<=(const Card &rhs) const;
    bool operator>=(const Card &rhs) const;

    // Getters
    [[nodiscard]] Rank getRank() const;
    [[nodiscard]] Suit getSuit() const;

protected:
    // Variables
    Suit suit;
    Rank rank;

    // Setters
    void setSuit(const Suit &newSuit);
    void setRank(Rank newRank);



};

#endif //DECKOFCARDS_CARDS_H

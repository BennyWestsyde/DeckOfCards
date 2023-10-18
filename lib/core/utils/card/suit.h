//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_SUIT_H
#define DECKOFCARDS_SUIT_H


#include <tuple>
#include <string>
#include <ostream>

enum SuitType {
    SPADES = 4,
    HEARTS = 3,
    DIAMONDS = 2,
    CLUBS = 1
};
enum Color {
    RED,
    BLACK
};

class Suit {
public:
    // Constructor and Destructor
    explicit Suit(SuitType suit);
    ~Suit();

    // Methods


    // Operator Overloads
    bool operator<(const Suit &rhs) const;
    bool operator>(const Suit &rhs) const;
    bool operator<=(const Suit &rhs) const;
    bool operator>=(const Suit &rhs) const;
    bool operator==(const Suit &rhs) const;
    bool operator!=(const Suit &rhs) const;

    // Getters
    [[nodiscard]] SuitType getSuit() const;
    [[nodiscard]] Color getColor() const;

    friend std::ostream &operator<<(std::ostream &os, const Suit &suit);

protected:
    // Variables
    SuitType suit;
    Color color;

    // Setters
    void setColor(Color newColor);
    void setSuit(SuitType newSuit);

};

#endif //DECKOFCARDS_SUIT_H

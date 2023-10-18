//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_SET_H
#define DECKOFCARDS_SET_H

#include "suit.h"
#include "cards.h"
#include <vector>



class Set {
public:
    enum Direction {
        FACE_UP,
        FACE_DOWN
    };
    // Constructors and Destructor
    Set();
    explicit Set(const std::vector<Card>& cards);

    // Methods
    void push(const Card& card);
    void push(const Set& set);
    void push(const Card& card, int index);
    void push(const Set& set, int index);
    Card pop();
    Card pop(int index);
    Set pop(int startIndex, int endIndex);
    Card peek();
    Card peek(int index);
    Set peek(int startIndex, int endIndex);
    void clear();
    int countValues();
    void shuffle();
    void sort();
    void flip();

    // Operator Overloads
    bool operator==(const Set &rhs) const;
    bool operator!=(const Set &rhs) const;
    Set operator[](size_t start, size_t end) const;
    Card operator[](size_t index) const;
    Set& operator=(const std::vector<Card> &rhs);
    Set& operator=(const Card &rhs);

    // Getters
    [[nodiscard]] const std::vector<Card> &getCards() const {
        return cards;
    }
    [[nodiscard]] int getSize() const {
        return size;
    }
    [[nodiscard]] Direction getDirection() const;

protected:
    // Variables
    std::vector<Card> cards;
    int size;
    Direction direction;

    // Methods
    void pushAt(const Card& card, int index);
    void pushAt(const Set& set, int index);
    void pushBack(const Set& set);
    void pushBack(const Card& card);
    void pushFront(const Set& set);
    void pushFront(const Card& card);
    Card popBack();
    Card popFront();
    Card popAt(int index);
    Set popAt(int startIndex, int endIndex);
    Card peekBack();
    Card peekFront();
    Card peekAt(int index);


};

#endif //DECKOFCARDS_SET_H

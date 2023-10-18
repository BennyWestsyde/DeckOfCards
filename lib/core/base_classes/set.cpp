//
// Created by Bennett Westfall on 10/17/23.
//
#include "set.h"

// Constructors and Destructor
Set::Set() {
    this->size = 0;
    this->cards = std::__1::vector<Card>();
    this->direction = FACE_DOWN;
}

Set::Set(const std::vector<Card> &cards) {
    this->size = (int) cards.size();
    this->cards = cards;
    this->direction = FACE_DOWN;
}

// Methods
void Set::push(const Card &card)  {
    if(this->direction == FACE_UP){
    pushFront(card);
    } else {
        pushBack(card);
    }
}

void Set::push(const Set &set) {
    if(this->direction == FACE_UP){
        pushFront(set);
    } else {
        pushBack(set);
    }
}

void Set::push(const Card &card, int index) {
    if(this->direction == FACE_UP){
        pushAt(card, index);
    } else {
        pushAt(card, index);
    }
}

void Set::push(const Set &set, int index) {
    if(this->direction == FACE_UP){
        pushAt(set, index);
    } else {
        pushAt(set, index);
    }
}

Card Set::pop() {
    if(this->direction == FACE_UP){
        return popFront();
    } else {
        return popBack();
    }
}

Card Set::pop(int index) {
    return popAt(index);
}

Set Set::pop(int startIndex, int endIndex) {
    return popAt(startIndex, endIndex);
}

Card Set::peek() {
    if(this->direction == FACE_UP){
        return peekFront();
    } else {
        return peekBack();
    }
}

Card Set::peek(int index) {
    return peekAt(index);
}

Set Set::peek(int startIndex, int endIndex) {
    return Set(std::vector<Card>(this->cards.begin() + startIndex, this->cards.begin() + endIndex));
}

void Set::clear() {
    this->cards = std::__1::vector<Card>();
    this->size = 0;
}

int Set::countValues() {
    int count = 0;
    for (int i = 0; i < this->size; i++) {
        count += this->cards[i].getRank();
    }
    return count;
}

void Set::shuffle() {
    for(int i = 0; i < this->size; i++){
        int random = abs((int) arc4random() % this->size);
        Card tempCard = this->cards[i];
        Card randCard = this->cards[random];
        cards.erase(cards.begin() + i);
        cards.insert(cards.begin() + i, randCard);
        cards.erase(cards.begin() + random);
        cards.insert(cards.begin() + random, tempCard);
    }
}


void Set::sort() {
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size - i - 1; j++){
            if(this->cards[j] > this->cards[j + 1]){
                Card temp = this->cards[j];
                this->cards[j] = this->cards[j + 1];
                this->cards[j + 1] = temp;
            }
        }
    }
}

void Set::flip() {
    if(this->direction == FACE_UP){
        this->direction = FACE_DOWN;
    } else {
        this->direction = FACE_UP;
    }
    for(int i = 0; i < this->size/2; i++){
        Card temp = this->cards[i];
        this->cards[i] = this->cards[this->size - i - 1];
        this->cards[this->size - i - 1] = temp;
    }
}

// Operator Overloads
Set& Set::operator=(const Card &rhs) {
    this->cards = std::__1::vector<Card>();
    this->cards.push_back(rhs);
    this->size = 1;
    return *this;
}

Set& Set::operator=(const std::vector<Card> &rhs) {
    this->cards = rhs;
    this->size = (int) rhs.size();
    return *this;
}

bool Set::operator==(const Set &rhs) const {
    for (int i = 0; i < this->size; i++) {
        if (this->cards[i] != rhs.cards[i]) {
            return false;
        }
    }
    return true;
}

bool Set::operator!=(const Set &rhs) const {
    return !(rhs == *this);
}

Set Set::operator[](size_t start, size_t end) const {
    if (end > cards.size() || start > end) {
        throw std::out_of_range("Invalid slice indices");
    }
    return Set{std::__1::vector<Card>(cards.begin() + (long) start, cards.begin() + (long) end)};
}

Card Set::operator[](size_t index) const {
    if (index >= cards.size()) {
        throw std::out_of_range("Invalid index");
    }
    return cards[index];
}

// Methods
void Set::pushAt(const Set &set, int index) {
    for(int i = 0; i < set.getSize(); i++){
        this->cards.insert(this->cards.begin() + index + i, set[i]);
    }
    this->size += set.getSize();
}

void Set::pushAt(const Card &card, int index) {
    this->cards.insert(this->cards.begin() + index, card);
    this->size++;
}

void Set::pushBack(const Set &set) {
    for(int i = 0; i < set.getSize(); i++){
        this->cards.push_back(set[i]);
    }
    this->size += set.getSize();
}

void Set::pushBack(const Card &card) {
    this->cards.push_back(card);
    this->size++;
}

void Set::pushFront(const Set &set) {
    for(int i = 0; i < set.getSize(); i++){
        this->cards.emplace(this->cards.begin(), set[i]);
    }
    this->size += set.getSize();
}

void Set::pushFront(const Card &card) {
    this->cards.insert(this->cards.begin(), card);
    this->size++;
}

Card Set::popBack() {
    Card card = this->cards.back();
    this->cards.pop_back();
    this->size--;
    return card;
}

Card Set::popFront() {
    Card card = this->cards.front();
    this->cards.erase(this->cards.begin());
    this->size--;
    return card;
}

Card Set::popAt(int index) {
    Card card = this->cards[index];
    this->cards.erase(this->cards.begin() + index);
    this->size--;
    return card;
}

Set Set::popAt(int startIndex, int endIndex) {
    Set set = Set();
    for(int i = startIndex; i < endIndex; i++){
        set.pushBack(this->cards[i]);
    }
    this->cards.erase(this->cards.begin() + startIndex, this->cards.begin() + endIndex);
    this->size -= (endIndex - startIndex);
    return set;
}

Card Set::peekBack() {
    return this->cards.back();
}

Card Set::peekFront() {
    return this->cards.front();
}

Card Set::peekAt(int index) {
    return this->cards[index];
}


Set::Direction Set::getDirection() const {
    return this->direction;
}









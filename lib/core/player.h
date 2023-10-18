//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_PLAYER_H
#define DECKOFCARDS_PLAYER_H
#include <utility>
#include <vector>
#include <string>
#include "utils/card/cards.h"
#include "piles.h"

class Player {
public:
    // Variables
    Pile hand;
    std::string name;

    // Constructor and Destructor
    explicit Player(std::string name);
    ~Player();

    // Methods
    void drawCard(const Card& newCard);
    void drawCards(const std::vector<Card>& newCards);
    Card dropCard(Card card);
    Card dropCard(int index);
    Card dropCards(std::vector<Card> cards);
    Card dropCards(std::vector<int> indices);
    Card dropCards(int start, int end);
    void sortHand();
    void sortHand(int start, int end);

};

Player::Player(std::string name) {
    this->name = std::move(name);
    this->hand = Pile();
}

void Player::drawCard(const Card& newCard) {
    this->hand.push(newCard);

}

void Player::drawCards(const std::vector<Card>& newCards) {
    for (auto & newCard : newCards) {
        this->hand.push(newCard);
    }

}

Card Player::dropCard(int i) {
    return this->hand.pop(i);
}

Player::~Player() = default;


#endif //DECKOFCARDS_PLAYER_H

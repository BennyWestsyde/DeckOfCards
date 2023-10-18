//
// Created by Bennett Westfall on 10/18/23.
//
#include "player.h"

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

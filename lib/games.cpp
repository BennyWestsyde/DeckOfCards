//
// Created by Bennett Westfall on 10/16/23.
//

#include "games.h"

Game::Game(int numPlayers) : numPlayers(numPlayers) {
    this->numPlayers = numPlayers;
    this->players = std::__1::vector<Player>();
    this->deck = Deck();
    for (int i = 0; i < this->numPlayers; i++) {
        std::string name = "Player " + std::to_string(i + 1);
        this->players.emplace_back(name);
    }
}

void Game::deal(int numCards, Player &toPlayer) {
    for (int i = 0; i < numCards; i++) {
        toPlayer.hand.push(this->deck.pop());

    }
}

void Game::deal(int numCards) {
    for (int i = 0; i < numCards; i++) {
        for (int j = 0; j < this->numPlayers; j++) {
            this->players[j].hand.push(this->deck.pop());
        }
    }
}


GinRummy::GinRummy() : Game(2) {
    this->deck = Deck();
    this->deck.shuffle();
    this->deal(10);
    this->discardPile = Pile();
}

void GinRummy::discard(Player &player, int index){
    this->discardPile.push(player.hand.pop(index));
}

void GinRummy::drawDeck(Player &player){
    player.hand.push(this->deck.pop());
}

void GinRummy::drawDiscard(Player &player){
    player.hand.push(this->discardPile.pop());
}

void GinRummy::knock(Player &player){

}
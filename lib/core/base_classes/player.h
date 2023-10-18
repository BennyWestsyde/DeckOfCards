//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_PLAYER_H
#define DECKOFCARDS_PLAYER_H
#include <utility>
#include <vector>
#include <string>
#include "cards.h"
#include "../custom_classes/piles.h"

class Player {
public:
    // Variables
    Pile hand;
    std::string name;

    // Constructor and Destructor
    explicit Player(std::string name);

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




#endif //DECKOFCARDS_PLAYER_H

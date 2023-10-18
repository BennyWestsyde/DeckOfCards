//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_GAMES_H
#define DECKOFCARDS_GAMES_H


#include <vector>
#include "core/player.h"
#include "core/deck.h"

class Game {
public:
    int numPlayers;
    std::vector<Player> players{};
    Deck deck{};
    Pile discardPile{};

    //Constructor and Destructor
    explicit Game(int numPlayers);
    ~Game() = default;

    //Methods
    void deal(int numCards, Player &toPlayer);
    void deal(int numCards);
};

class GinRummy : public Game {
public:
    //Variables


    //Constructor and Destructor
    GinRummy();
    ~GinRummy() = default;

    //Methods
    void discard(Player &player, int index);

    void drawDeck(Player &player);

    void drawDiscard(Player &player);

    void knock(Player &player);
};

#endif //DECKOFCARDS_GAMES_H

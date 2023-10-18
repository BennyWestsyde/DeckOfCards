//
// Created by Bennett Westfall on 10/16/23.
//

#include <vector>
#include <iostream>
#include "lib/core/base_classes/suit.h"
#include "lib/core/base_classes/cards.h"
#include "lib/core/base_classes/games.h"
#include "lib/core/base_classes/player.h"
#include "lib/core/base_classes/set.h"
#include "lib/core/custom_classes/piles.h"
#include "lib/core/custom_classes/hand.h"
#include "lib/core/custom_classes/deck.h"
#include "lib/core/utils/logger.h"
#include "lib/core/utils/patternChecker.h"

int main() {
    Suit suit = Suit(SuitType::SPADES);
    Rank rank = Rank::ACE;
    Card card = Card(rank, suit);
    Set set = Set();
    set.push(card);


}
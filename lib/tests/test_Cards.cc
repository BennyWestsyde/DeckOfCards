#include <gtest/gtest.h>
#include "../core/base_classes/cards.h"

TEST(Card, DefaultConstructor) {
    Card card = Card(ACE, Suit(SPADES));
    EXPECT_EQ(card.getRank(), ACE) << "Card Rank: " << card.getRank();
    EXPECT_EQ(card.getSuit(), Suit(SPADES)) << "Card Suit: " << card.getSuit();
}

TEST(Card, OperatorEquals) {
    Card card1 = Card(ACE, Suit(SPADES));
    Card card2 = Card(ACE, Suit(SPADES));
    EXPECT_TRUE(card1 == card2) << "Card1: " << card1 << " Card2: " << card2;
}

TEST(Card, OperatorNotEquals) {
    Card card1 = Card(ACE, Suit(SPADES));
    Card card2 = Card(TWO, Suit(SPADES));
    EXPECT_TRUE(card1 != card2) << "Card1: " << card1 << " Card2: " << card2;
}

TEST(Card, OperatorLessThan) {
    Card card1 = Card(ACE, Suit(SPADES));
    Card card2 = Card(TWO, Suit(SPADES));
    EXPECT_TRUE(card1 < card2) << "Card1: " << card1 << " Card2: " << card2;
}

TEST(Card, OperatorGreaterThan) {
    Card card1 = Card(ACE, Suit(SPADES));
    Card card2 = Card(TWO, Suit(SPADES));
    EXPECT_TRUE(card2 > card1) << "Card1: " << card1 << " Card2: " << card2;
}

TEST(Card, OperatorLessThanOrEqual) {
    Card card1 = Card(ACE, Suit(SPADES));
    Card card2 = Card(TWO, Suit(SPADES));
    EXPECT_TRUE(card1 <= card2) << "Card1: " << card1 << " Card2: " << card2;
    EXPECT_TRUE(card1 <= card1) << "Card1: " << card1 << " Card2: " << card1;
}

TEST(Card, OperatorGreaterThanOrEqual) {
    Card card1 = Card(ACE, Suit(SPADES));
    Card card2 = Card(TWO, Suit(SPADES));
    EXPECT_TRUE(card2 >= card1) << "Card1: " << card1 << " Card2: " << card2;
    EXPECT_TRUE(card1 >= card1) << "Card1: " << card1 << " Card2: " << card1;
}

TEST(Card, GetRank) {
    Card card = Card(ACE, Suit(SPADES));
    EXPECT_EQ(card.getRank(), ACE) << "Card Rank: " << card.getRank();
}

TEST(Card, GetSuit) {
    Card card = Card(ACE, Suit(SPADES));
    EXPECT_EQ(card.getSuit(), Suit(SPADES)) << "Card Suit: " << card.getSuit();
}
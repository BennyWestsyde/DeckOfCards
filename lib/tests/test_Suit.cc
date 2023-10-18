#include <gtest/gtest.h>
#include "../core/utils/card/suit.h"

// Test the default constructor.
TEST(Suit, DefaultConstructor) {
    Suit suit = Suit(SuitType::SPADES);
    EXPECT_EQ(suit.getSuit(), SuitType::SPADES);
    EXPECT_EQ(suit.getColor(), Color::BLACK);
}

// Test Equality Operator
TEST(Suit, EqualityOperator) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(SuitType::SPADES);
    EXPECT_EQ(suit1, suit2);
}

// Test Inequality Operator
TEST(Suit, InequalityOperator) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(SuitType::HEARTS);
    EXPECT_NE(suit1, suit2);
}

// Test Less Than Operator
TEST(Suit, LessThanOperator) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(SuitType::HEARTS);
    EXPECT_LT(suit2, suit1);
}

// Test Greater Than Operator
TEST(Suit, GreaterThanOperator) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(SuitType::HEARTS);
    EXPECT_GT(suit1, suit2);
}

// Test Less Than or Equal To Operator
TEST(Suit, LessThanOrEqualToOperator) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(SuitType::HEARTS);
    Suit suit3 = Suit(SuitType::SPADES);
    EXPECT_LE(suit2, suit1);
    EXPECT_LE(suit3, suit1);
}

// Test Greater Than or Equal To Operator
TEST(Suit, GreaterThanOrEqualToOperator) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(SuitType::HEARTS);
    Suit suit3 = Suit(SuitType::SPADES);
    EXPECT_GE(suit1, suit2);
    EXPECT_GE(suit1, suit3);
}

// Test Copy Constructor
TEST(Suit, CopyConstructor) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(suit1);
    EXPECT_EQ(suit1, suit2);
}

// Test Assignment Operator
TEST(Suit, AssignmentOperator) {
    Suit suit1 = Suit(SuitType::SPADES);
    Suit suit2 = Suit(SuitType::HEARTS);
    suit2 = suit1;
    EXPECT_EQ(suit1, suit2);
}
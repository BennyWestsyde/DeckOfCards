#include <gtest/gtest.h>
#include "../core/utils/set.h"
#include "../core/utils/card/cards.h"

// Prepare Test Environment
Set GLOBSET = Set();
Card AceSpades = Card(Rank::ACE,Suit(SuitType::SPADES));
Card TwoSpades = Card(Rank::TWO,Suit(SuitType::SPADES));
Card ThreeSpades = Card(Rank::THREE,Suit(SuitType::SPADES));
Card FourSpades = Card(Rank::FOUR,Suit(SuitType::SPADES));
Card FiveSpades = Card(Rank::FIVE,Suit(SuitType::SPADES));
std::vector<Card> GLOBVECTOR = std::vector<Card>({AceSpades, TwoSpades, ThreeSpades, FourSpades, FiveSpades});

// Test Default Constructor
TEST(Set, DefaultConstructor) {
    Set set = Set();
    EXPECT_EQ(set, GLOBSET);
}

// Test Constructor with Cards
TEST(Set, ConstructorWithCards) {
    Set set = Set(GLOBVECTOR);
    for(int i = 0; i < GLOBVECTOR.size(); i++){
        ASSERT_TRUE(set[i] == GLOBVECTOR[i]);
    }
}

// Test Push Card Face Down
TEST(Set, PushCardFaceDown) {
    Set set = Set();
    EXPECT_EQ(set.getDirection(), Set::FACE_DOWN) << "Current Direction: " << set.getDirection();
    for (auto & i : GLOBVECTOR) {
        set.push(i);
        ASSERT_EQ(set.peek(), i) << "Cards Not Being Pushed Correctly (From Back)";
    }
}

// Test Push Card Face Up
TEST(Set, PushCardFaceUp) {
    Set set = Set();
    set.flip();
    EXPECT_EQ(set.getDirection(), Set::FACE_UP) << "Current Direction: " << set.getDirection();
    for (auto & i : GLOBVECTOR) {
        set.push(i);
        ASSERT_EQ(set.peek(0), i) << "Cards Not Being Pushed Correctly (From Front)";
    }
}

// Test Push Set Face Down
TEST(Set, PushSetFaceDown) {
    Set set = Set();
    EXPECT_EQ(set.getDirection(), Set::FACE_DOWN) << "Current Direction: " << set.getDirection();
    set.push(Set(GLOBVECTOR));
    for (int i = 0; i < GLOBVECTOR.size(); i++) {
        ASSERT_EQ(set.peek(i), GLOBVECTOR[i]) << "Cards Not Being Pushed Correctly (From Back)";
    }
}

// Test Push Set Face Up
TEST(Set, PushSetFaceUp) {
    Set set = Set();
    set.flip();
    EXPECT_EQ(set.getDirection(), Set::FACE_UP) << "Current Direction: " << set.getDirection();
    set.push(Set(GLOBVECTOR));
    for (int i = 0; i < GLOBVECTOR.size(); i++) {
        ASSERT_EQ(set.peek(i), GLOBVECTOR[GLOBVECTOR.size()-i-1]) << "Cards Not Being Pushed Correctly (From Front)";
    }
}

// Test Push Card at Index Face Down
TEST(Set, PushCardAtIndexFaceDown) {
    Set set = Set();
    set.push(Set(GLOBVECTOR));
    set.shuffle();
    EXPECT_EQ(set.getDirection(), Set::FACE_DOWN) << "Current Direction: " << set.getDirection();
    for (int i = 0; i < GLOBVECTOR.size(); i++) {
        set.push(GLOBVECTOR[i], i);
        ASSERT_EQ(set.peek(i), GLOBVECTOR[i]) << "Cards Not Being Pushed Correctly (From Back)";
    }
}


// Test Push Card at Index Face Up
TEST(Set, PushCardAtIndexFaceUp) {
    Set set = Set(GLOBVECTOR);
    set.flip();
    EXPECT_EQ(set.getDirection(), Set::FACE_UP) << "Current Direction: " << set.getDirection();
    for (int i = 0; i < GLOBVECTOR.size(); i++) {
        set.push(GLOBVECTOR[i], i);
        ASSERT_EQ(set.peek(i), GLOBVECTOR[i]) << "Cards Not Being Pushed Correctly (From Front)";
    }
}

// Test Pushing From Front and Back are Different
TEST(Set, PushFromFrontAndBack) {
    Set setFront = Set();
    Set setBack = Set();
    setFront.flip();
    ASSERT_EQ(setFront.getDirection(), Set::FACE_UP) << "\"Front\" Set Direction: " << setFront.getDirection();
    ASSERT_EQ(setBack.getDirection(), Set::FACE_DOWN) << "\"Back\" Set Direction: " << setBack.getDirection();
    for (auto & i : GLOBVECTOR) {
        setFront.push(i);
        setBack.push(i);
    }
    for (int i = 0; i < GLOBVECTOR.size(); i++) {
        if (i == 2) {
            ASSERT_EQ(setFront.peek(i), setBack.peek(i)) << "Cards Not Being Pushed Correctly (From Front and Back)";
        } else {
            ASSERT_NE(setFront.peek(i), setBack.peek(i)) << "Cards Not Being Pushed Correctly (From Front and Back)";
        }
    }
}


// Test Remove Card
TEST(Set, RemoveCard) {
    Set set = Set();
    set.push(Card(AceSpades));
    EXPECT_EQ(set.getSize(), 1);
    EXPECT_TRUE(set.peek(0) == Card(AceSpades));
    set.pop(0);
    EXPECT_EQ(set.getSize(), 0);
}

// Test Check Card
TEST(Set, CheckCard) {
    Set set = Set();
    set.push(Card(AceSpades));
    EXPECT_EQ(set.getSize(), 1);
    EXPECT_TRUE(set.peek(0) == Card(AceSpades));
    EXPECT_TRUE(set.peek(0) == Card(AceSpades));
}

// Test Check Card Out of Bounds
TEST(Set, CountValues) {
    Set set = Set();
    set.push(Card(AceSpades));
    set.push(Card(TwoSpades));
    set.push(Card(ThreeSpades));
    EXPECT_EQ(set.countValues(), 6);
}

// Test Shuffle
TEST(Set, Shuffle) {
    Set set1 = Set();
    set1.push(Card(AceSpades));
    set1.push(Card(TwoSpades));
    set1.push(Card(ThreeSpades));
    set1.push(Card(FourSpades));
    Set set2 = Set();
    set2.push(Card(AceSpades));
    set2.push(Card(TwoSpades));
    set2.push(Card(ThreeSpades));
    set2.push(Card(FourSpades));
    EXPECT_TRUE(set1 == set2);
    set1.shuffle();
    EXPECT_TRUE(set1 != set2);
}

// Test Sort
TEST(Set, Sort) {
    Set set1 = Set();
    set1.push(Card(AceSpades));
    set1.push(Card(TwoSpades));
    set1.push(Card(ThreeSpades));
    set1.push(Card(FourSpades));
    set1.push(Card(FiveSpades));
    Set set2 = set1;
    EXPECT_TRUE(set1 == set2);
    set1.shuffle();
    EXPECT_FALSE(set1 == set2);
    set1.sort();
    EXPECT_TRUE(set1 == set2);
}

TEST(Set, SetAndGetDirection) {
    Set set = Set();
    set.flip();
    EXPECT_EQ(set.getDirection(), Set::FACE_UP) << "Current Direction: " << set.getDirection();
    set.flip();
    EXPECT_EQ(set.getDirection(), Set::FACE_DOWN) << "Current Direction: " << set.getDirection();
}

TEST(Set, GetCards) {
    Set set = Set();
    set.push(Card(AceSpades));
    set.push(Card(TwoSpades));
    set.push(Card(ThreeSpades));
    std::vector<Card> cards = set.getCards();
    Set set2 = Set(cards);
    EXPECT_EQ(cards.size(), 3);
    EXPECT_TRUE(cards[0] == Card(AceSpades));
    EXPECT_TRUE(cards[1] == Card(TwoSpades));
    EXPECT_TRUE(cards[2] == Card(ThreeSpades));
    EXPECT_TRUE(set == set2);
}

TEST(Set, GetSize) {
    Set set = Set();
    EXPECT_EQ(set.getSize(), 0);
    set.push(Card(AceSpades));
    EXPECT_EQ(set.getSize(), 1);
    set.push(Card(TwoSpades));
    EXPECT_EQ(set.getSize(), 2);
    set.push(Card(ThreeSpades));
    EXPECT_EQ(set.getSize(), 3);
}


// Test Clear
TEST(Set, Clear) {
    Set set = Set();
    set.push(Card(AceSpades));
    set.push(Card(TwoSpades));
    set.push(Card(ThreeSpades));
    EXPECT_EQ(set.getSize(), 3);
    set.clear();
    EXPECT_EQ(set.getSize(), 0);
}

// Test Operator Assign
TEST(Set, OperatorAssign) {
    Set set1 = Set();
    set1.push(Card(AceSpades));
    set1.push(Card(TwoSpades));
    set1.push(Card(ThreeSpades));
    Set set2 = Set();
    set2 = set1;
    EXPECT_TRUE(set1 == set2);
}

// Test Operator Assign Vector
TEST(Set, OperatorAssignVector) {
    Set set1 = Set(GLOBVECTOR);
    Set set2 = Set();
    set2 = GLOBVECTOR;
    EXPECT_TRUE(set1 == set2);
}


// Test Operator Equals
TEST(Set, OperatorEquals) {
    Set set1 = Set();
    set1.push(Card(AceSpades));
    set1.push(Card(TwoSpades));
    set1.push(Card(ThreeSpades));
    Set set2 = Set();
    set2.push(Card(AceSpades));
    set2.push(Card(TwoSpades));
    set2.push(Card(ThreeSpades));
    EXPECT_TRUE(set1 == set2);
}

// Test Operator Not Equals
TEST(Set, OperatorNotEquals) {
    Set set1 = Set();
    set1.push(Card(AceSpades));
    set1.push(Card(TwoSpades));
    set1.push(Card(ThreeSpades));
    Set set2 = Set();
    set2.push(Card(AceSpades));
    set2.push(Card(TwoSpades));
    set2.push(Card(ThreeSpades));
    EXPECT_FALSE(set1 != set2);
}

// Test Operator Slice
TEST(Set, OperatorSlice) {
    // Config
    Set set1 = GLOBSET;
    set1.push(Card(AceSpades));
    set1.push(Card(TwoSpades));
    set1.push(Card(ThreeSpades));

    // Test Basic Usage
    Set set2 = set1[0,2];
    EXPECT_EQ(set2.getSize(), 2) << "Slice: Failed (Basic Usage|Size)";
    EXPECT_TRUE(set2[0] == Card(AceSpades));
    EXPECT_TRUE(set2[1] == Card(TwoSpades));

    // Test Negative Indices
    Set set3 = set1[-2,-1];
    EXPECT_EQ(set3.getSize(), 2);
    EXPECT_TRUE(set3[0] == Card(TwoSpades));
    EXPECT_TRUE(set3[1] == Card(ThreeSpades));


    // Test Thrown Errors
    // Invalid Indices (Start > End)
    EXPECT_ANY_THROW(set1.operator[](2,0));
    // Invalid Indices (End Out of Bounds)
    EXPECT_ANY_THROW(set1.operator[](0,4));
}

// Test Operator Index
TEST(Set, OperatorIndex) {
    // Test Basic Usage
    Set set1 = Set();
    set1.push(Card(AceSpades));
    set1.push(Card(TwoSpades));
    set1.push(Card(ThreeSpades));
    for (int i = 0; i<3; i++) {
        EXPECT_TRUE(set1[i] == GLOBVECTOR[i]);
    }
    // Test Negative Index
    for (int i = 2; i>=0; i--) {
        EXPECT_TRUE(set1[-i] == GLOBVECTOR[i]);
    }

    // Test Thrown Errors
    // Invalid Index
    EXPECT_ANY_THROW(set1.operator[](3));



}
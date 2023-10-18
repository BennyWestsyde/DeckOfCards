cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)

project(DeckOfCards)

include(GoogleTest)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(Suit STATIC
        lib/core/utils/card/suit.cpp
        lib/core/utils/card/suit.h
        lib/logger.cpp
        lib/logger.h)
add_executable(testSuit lib/tests/test_Suit.cc
        lib/logger.cpp
        lib/logger.h)
target_link_libraries(testSuit gtest_main Suit)

add_library(PatternChecker STATIC
        lib/core/utils/patternChecker.cpp
        lib/core/utils/patternChecker.h
        lib/logger.cpp
        lib/logger.h)
add_executable(testPatternChecker lib/tests/test_PatternChecker.cc
        lib/logger.cpp
        lib/logger.h)
target_link_libraries(testPatternChecker gtest_main PatternChecker)

add_library(Cards STATIC
        lib/core/utils/card/cards.h
        lib/core/utils/card/cards.cpp
        lib/logger.cpp
        lib/logger.h)
add_executable(testCards lib/tests/test_Cards.cc
        lib/logger.cpp
        lib/logger.h)
target_link_libraries(testCards gtest_main Cards Suit PatternChecker)

add_library(Set STATIC
        lib/core/utils/set.cpp
        lib/core/utils/set.h
        lib/logger.cpp
        lib/logger.h)
add_executable(testSet lib/tests/test_Set.cc
        lib/logger.cpp
        lib/logger.h)
target_link_libraries(testSet gtest_main Set Cards Suit)

add_library(Piles STATIC
        lib/core/piles.h
        lib/core/piles.cpp
        lib/logger.cpp
        lib/logger.h)
add_executable(testPiles lib/tests/test_Piles.cc
        lib/logger.cpp
        lib/logger.h)
target_link_libraries(testPiles gtest_main Piles)

#add_library(Deck STATIC
#        lib/core/deck.h)
#add_executable(testDeck lib/tests/test_Deck.cc)
#target_link_libraries(testDeck gtest_main Deck Cards Piles)

#add_library(Hand STATIC
#        lib/core/hand.h)
#add_executable(testHand lib/tests/test_Hand.cc)
#target_link_libraries(testHand gtest_main)

#add_library(Player STATIC
#        lib/core/player.h)
#add_executable(testPlayer lib/tests/test_Player.cc)
#target_link_libraries(testPlayer gtest_main)

add_library(Game STATIC
        lib/games.h
        lib/games.cpp
        lib/logger.cpp
        lib/logger.h)
add_executable(testGame lib/tests/test_Game.cc
        lib/logger.cpp
        lib/logger.h)
target_link_libraries(testGame gtest_main Game)

add_executable(testAll
        lib/tests/test_Cards.cc
#        lib/tests/test_Deck.cc
        lib/tests/test_Game.cc
#        lib/tests/test_Hand.cc
        lib/tests/test_PatternChecker.cc
        lib/tests/test_Piles.cc
#        lib/tests/test_Player.cc
        lib/tests/test_Set.cc
        lib/tests/test_Suit.cc
        lib/logger.cpp
        lib/logger.h)
target_link_libraries(testAll gtest_main Cards Game PatternChecker Piles Set Suit)

add_executable(DeckOfCards main.cpp
        lib/logger.cpp
        lib/logger.h)


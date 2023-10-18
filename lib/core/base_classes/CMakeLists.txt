cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)

project(DeckOfCards)



add_library(Cards STATIC
       cards.h
        cards.cpp)
target_link_libraries(Cards logger)

add_library(Set STATIC
        set.cpp
        set.h)
target_link_libraries(Set logger)

add_library(Player STATIC
        player.cpp
        player.h)
target_link_libraries(Player logger)

add_library(Game STATIC
        games.cpp
        games.h)
target_link_libraries(Game logger Deck)

add_library(Suit STATIC
        suit.cpp
        suit.h)
target_link_libraries(Suit logger)


add_executable(testBaseClasses ../../tests/test_Cards.cc
                               ../../tests/test_Set.cc
                               ../../tests/test_Game.cc
                               ../../tests/test_Suit.cc
                               ../../tests/test_Player.cc)
target_link_libraries(testBaseClasses gtest_main Cards Set Game Suit Player logger)

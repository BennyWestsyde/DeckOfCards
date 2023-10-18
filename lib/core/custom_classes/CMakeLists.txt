cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)

project(DeckOfCards)

add_library(Piles STATIC
        piles.cpp
        piles.h)
target_link_libraries(Piles logger Set)

add_library(Deck STATIC
        deck.cpp
        deck.h)
target_link_libraries(Deck logger Piles)

add_library(Hand STATIC
        hand.cpp
        hand.h)
target_link_libraries(Hand logger Piles)

add_executable(testCustomClasses ../../tests/test_Piles.cc
                               ../../tests/test_Deck.cc
                               ../../tests/test_Hand.cc)
target_link_libraries(testBaseClasses gtest_main Piles Deck Hand logger Set)
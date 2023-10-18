cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)

project(DeckOfCards)

add_library(PatternChecker STATIC PatternChecker.cpp PatternChecker.h)

add_executable(TestUtils ../../tests/test_PatternChecker.cc)
target_link_libraries(TestUtils gtest_main PatternChecker logger)
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

add_library(logger SHARED
        lib/core/utils/logger.cpp
        lib/core/utils/logger.h)

add_subdirectory(lib/core/base_classes)
add_subdirectory(lib/core/custom_classes)
add_subdirectory(lib/core/utils)


add_executable(DeckOfCards main.cpp
        lib/core/utils/logger.cpp
        lib/core/utils/logger.h)
target_link_libraries(DeckOfCards PRIVATE logger Cards Game Player Deck Set Hand Piles PatternChecker)
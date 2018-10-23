cmake_minimum_required(VERSION 3.9)
project(TextTwist)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(TextTwist TextTwist.cpp TextTwist.h Trie.cpp Trie.h TrieNode.cpp TrieNode.h texttwistdriver.cpp)
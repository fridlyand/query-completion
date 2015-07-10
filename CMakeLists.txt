cmake_minimum_required(VERSION 3.2)
project(query_completion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(query_completion ${SOURCE_FILES} Trie.h Trie.cpp TST.h TST.cpp Tests.h Tests.cpp Query.cpp Query.h)
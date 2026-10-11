cmake_minimum_required(VERSION 3.16)
project(DSA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(dsa_core
    src/Edge.h
    src/Graph.h
    src/MSTResult.h
    src/UnionFind.h
    src/UnionFind.cpp
    src/Kruskal.h
    src/Kruskal.cpp
)
target_include_directories(dsa_core PUBLIC src)

add_executable(DSA src/main.cpp)
target_link_libraries(DSA PRIVATE dsa_core)

add_executable(DSA_tests tests/test.cpp)
target_link_libraries(DSA_tests PRIVATE dsa_core)

enable_testing()
add_test(NAME Week1Core COMMAND DSA_tests)

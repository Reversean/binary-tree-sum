project(n-ary-tree-sum)

cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")

add_subdirectory(core)
add_subdirectory(sequential)
add_subdirectory(pthread)
add_subdirectory(openmp)
add_subdirectory(test)

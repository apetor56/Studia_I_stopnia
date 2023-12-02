cmake_minimum_required(VERSION 3.0.0)
project(Zestaw03 VERSION 0.1.0)

add_compile_options(-std=c++17 -Wall -pedantic -I./include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# A
add_executable(PriorityQueue ${SRC}/PriorityQueue.cpp)

# B
add_executable(BinaryHeap ${SRC}/BinaryHeap.cpp)
add_executable(testB ${SRC}/testB.cpp)


include_directories(${INCLUDE})
cmake_minimum_required(VERSION 3.0.0)
project(Zestaw04 VERSION 0.1.0)

add_compile_options(-std=c++17 -Wall -pedantic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(SRC ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/include)

# A
add_executable(Graph ${SRC}/Graph.cpp)

# A - test
add_executable(testA ${SRC}/testA.cpp)

include_directories(${INCLUDE})
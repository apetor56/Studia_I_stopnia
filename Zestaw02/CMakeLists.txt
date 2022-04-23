cmake_minimum_required(VERSION 3.0.0)
project("Zestaw02" VERSION 0.1.0)

add_compile_options(-std=c++17 -Wall -pedantic -I./include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)

# set source files path
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#set include files path
set(INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# programs

# A - main
add_executable(Set ${SRC}/Set.cpp)

# B - main
add_executable(SetLinked ${SRC}/SetLinked.cpp)

# B - test
add_executable(testB ${SRC}/testB.cpp)


include_directories(${INCLUDE})
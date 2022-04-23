cmake_minimum_required(VERSION 3.0.0)
project("Zestaw01" VERSION 0.1.0)

add_compile_options(-std=c++17 -Wall -pedantic -I./include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)

# set source files path
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#set include files path
set(INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# programs

# A - main
add_executable(SetSimple ${SRC}/SetSimple.cpp)
# target_include_directories(SetSimple PUBLIC ${INCLUDE})
# A - test
add_executable(testA ${SRC}/testA.cpp)
# target_include_directories(testA PUBLIC ${INCLUDE})

# B - main
add_executable(SetLinked ${SRC}/SetLinked.cpp)
# target_include_directories(SetLinked PUBLIC ${INCLUDE})
# B - test
add_executable(testB ${SRC}/testB.cpp)
# target_include_directories(testB PUBLIC ${INCLUDE})

# D - main
add_executable(DictonarySample ${SRC}/DictonarySample.cpp)
# target_include_directories(DictonarySample PUBLIC ${INCLUDE})

include_directories(${INCLUDE})
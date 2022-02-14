CXX 	 :=  g++ -O2
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := BinaryTree
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean

all: ${EXE}

BinaryTree.o: BinaryTree.cpp BinaryTree.hpp
BinaryTree.x: BinaryTree.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
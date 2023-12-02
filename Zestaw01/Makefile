CXX 	 :=  g++ -O0
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := Generator Stack ONP
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean

all: ${EXE}

Generator.o: Generator.cpp
Generator.x: Generator.o

Stack.o: Stack.cpp ArrayStack.hpp LinkedStack.hpp
Stack.x: Stack.o

ONP.o: ONP.cpp ArrayStack.hpp LinkedStack.hpp
ONP.x: ONP.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
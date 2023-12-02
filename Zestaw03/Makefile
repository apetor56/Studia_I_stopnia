CXX 	 :=  g++ -O2
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := Generator LinkedList
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean

all: ${EXE}

Generator.o: Generator.cpp
Generator.x: Generator.o

LinkedList.o: LinkedList.cpp LinkedList.hpp
LinkedList.x: LinkedList.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
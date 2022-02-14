CXX 	 :=  g++ -O0
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := Generator Queue Radix
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean

all: ${EXE}

Generator.o: Generator.cpp
Generator.x: Generator.o

Queue.o: Queue.cpp ArrayQueue.hpp
Queue.x: Queue.o

Radix.o: Radix.cpp ArrayQueue.hpp
Radix.x: Radix.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
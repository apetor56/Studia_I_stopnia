CXX 	 :=  g++ -O2
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := Dict Dict2
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean

all: ${EXE}

Dict.o: Dict.cpp Dict.hpp LinkedList.hpp
Dict.x: Dict.o

Dict2.o: Dict2.cpp Dict.hpp LinkedList.hpp
Dict2.x: Dict2.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
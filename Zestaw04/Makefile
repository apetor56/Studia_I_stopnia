CXX 	 :=  g++ -O2
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := ArrayList CursorList
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean

all: ${EXE}

ArrayList.o: ArrayList.cpp ArrayList.hpp
ArrayList.x: ArrayList.o

CursorList.o: CursorList.cpp CursorList.hpp
CursorList.x: CursorList.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
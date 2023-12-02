CXX 	 :=  g++ -O2
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := Generator BubbleSort SelectionSort InsertionSort CountingSort VectorSort
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean

all: ${EXE}

Generator.o: Generator.cpp
Generator.x: Generator.o

BubbleSort.o: BubbleSort.cpp
BubbleSort.x: BubbleSort.o

SelectionSort.o: SelectionSort.cpp
SelectionSort.x: SelectionSort.o

InsertionSort.o: InsertionSort.cpp
InsertionSort.x: InsertionSort.o

CountingSort.o: CountingSort.cpp
CountingSort.x: CountingSort.o

VectorSort.o: VectorSort.cpp
VectorSort.x: VectorSort.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
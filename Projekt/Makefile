CXX 	 :=  g++ -O2
CXXFLAGS := -std=c++11 -Wall -pedantic

FILES := Points KDPoints Generator
SRC	  := ${addsuffix .cpp, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean run

all: ${EXE}

Points.o: Points.cpp Base.hpp
Points.x: Points.o

KDPoints.o: KDPoints.cpp KDBase.hpp
KDPoints.x: KDPoints.o

Generator.o: Generator.cpp
Generator.x: Generator.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

%.x: %.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} ${EXE}
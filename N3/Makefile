CC 	   := gcc -O2
CFLAGS := -Wall -pedantic

FILES := power_method
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean runN3

all: ${EXE}

runN3:
	./power_method.x < data.txt

power_method.o: power_method.c operations.h
power_method.x: power_method.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ `gsl-config --cflags --libs` 

clean:
	${RM} ${OBJ} ${EXE}
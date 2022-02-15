CC 	   := gcc -O2
CFLAGS := -Wall -pedantic

FILES := lagrange
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean runO7

all: ${EXE}

runO7:
	./lagrange.x < O7.txt

lagrange.o: lagrange.c
lagrange.x: lagrange.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ `gsl-config --cflags --libs` 

clean:
	${RM} ${OBJ} ${EXE}
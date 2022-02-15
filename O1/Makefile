CC 	   := gcc -O2
CFLAGS := -Wall -pedantic

FILES := conjugate_gradients
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean runO1_a runO1_b

all: ${EXE}

runO1_a:
	./conjugate_gradients.x < O1_a.txt

runO1_b:
	./conjugate_gradients.x < O1_b.txt

conjugate_gradients.o: conjugate_gradients.c operations.h
conjugate_gradients.x: conjugate_gradients.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ `gsl-config --cflags --libs` 

clean:
	${RM} ${OBJ} ${EXE}
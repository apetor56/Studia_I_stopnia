CC 	   := gcc -O2
CFLAGS := -Wall -pedantic

FILES := cubic_spline conjugate_gradients generator
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean runN15

all: ${EXE}

runN15:
	./generator.x < data.txt > input.txt
	./conjugate_gradients.x < input.txt > cubic_eps.txt
	./cubic_spline.x < cubic_eps.txt > cubic_output.txt

cubic_spline.o: cubic_spline.c
cubic_spline.x: cubic_spline.o

conjugate_gradients.o: conjugate_gradients.c operations.h
conjugate_gradients.x: conjugate_gradients.o

generator.o: generator.c
generator.x: generator.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ `gsl-config --cflags --libs` 

clean:
	${RM} ${OBJ} ${EXE}
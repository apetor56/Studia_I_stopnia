CC 	   := gcc -O2
CFLAGS := -Wall -pedantic

FILES := cubic_spline conjugate_gradients data_generator
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean runO7

all: ${EXE}

runO9:
	./data_generator.x 6 > O9.txt
	./conjugate_gradients.x < O9.txt > cubic_eps.txt
	./cubic_spline.x < cubic_eps.txt > cubic_output.txt

cubic_spline.o: cubic_spline.c
cubic_spline.x: cubic_spline.o

conjugate_gradients.o: conjugate_gradients.c operations.h
conjugate_gradients.x: conjugate_gradients.o

data_generator.o: data_generator.c
data_generator.x: data_generator.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ `gsl-config --cflags --libs` 

clean:
	${RM} ${OBJ} ${EXE}
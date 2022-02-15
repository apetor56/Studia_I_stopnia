CC 	   := gcc -O2
CFLAGS := -Wall -pedantic

FILES := gauss_seidel conjugate_gradients matrix_generator
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean runO2_a runO2_b

all: ${EXE}

runO2_a:
	./matrix_generator.x 128 > O2.txt
	./gauss_seidel.x < O2.txt > gauss_output.txt

runO2_b:
	./matrix_generator.x 128 > O2.txt
	./conjugate_gradients.x < O2.txt > gradients_output.txt

gauss_seidel.o: gauss_seidel.c operations.h
gauss_seidel.x: gauss_seidel.o

conjugate_gradients.o: conjugate_gradients.c operations.h
conjugate_gradients.x: conjugate_gradients.o

matrix_generator.o: matrix_generator.c
matrix_generator.x: matrix_generator.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ `gsl-config --cflags --libs` 

clean:
	${RM} ${OBJ} ${EXE}
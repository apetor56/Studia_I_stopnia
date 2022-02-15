CC 	   := gcc -O2
CFLAGS := -Wall -pedantic

FILES := lagrange data_generator
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .x, ${FILES}}

.PHONY: all clean runO7

all: ${EXE}

runN8:
	./data_generator.x 8 > N8.txt
	./lagrange.x < N8.txt

lagrange.o: lagrange.c
lagrange.x: lagrange.o

data_generator.o: data_generator.c
data_generator.x: data_generator.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.x: %.o
	${CC} ${CFLAGS} -o $@ $^ `gsl-config --cflags --libs` 

clean:
	${RM} ${OBJ} ${EXE}
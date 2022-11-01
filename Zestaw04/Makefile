CC      := gcc -std=c99 -pedantic
CFLAGS  := -Wall -O2

SOURCES := prodkons prog
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean

all: prodkons.x

prodkons.o: prodkons.c prog.h
prodkons.x: prodkons.o prog.o

prog.o: prog.c prog.h

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) -o $@ $^

clean:
	$(RM) *.x $(OBJECTS)
CC      := gcc -std=c99 -pedantic
CFLAGS  := -Wall -O2

SOURCES := fifo producent konsument a
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean

all: $(addsuffix .x, $(SOURCES))

fifo.o: fifo.c
fifo.x: fifo.o
producent.o: producent.c
producent.x: producent.o
konsument.o: konsument.c
konsument.x: konsument.o
a.o: a.c
a.x: a.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) -o $@ $^

clean:
	$(RM) *.x $(OBJECTS)


CC := gcc -std=c99 -pedantic -pthread
CFLAGS := -Wall -O2

SOURCES := wykluczanie
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean
all: wykluczanie.x

wykluczanie.o: wykluczanie.c
wykluczanie.x: wykluczanie.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.x $(OBJECTS)

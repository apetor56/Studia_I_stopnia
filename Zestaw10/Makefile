CC := gcc -std=c99 -pedantic -pthread
CFLAGS := -Wall -O2

SOURCES := piekarnia piekarnia2
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean
all: piekarnia.x piekarnia2.x

pom.o: pom.c pom.h

piekarnia.o: piekarnia.c
piekarnia.x: piekarnia.o

piekarnia2.o: piekarnia2.c
piekarnia2.x: piekarnia2.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.x $(OBJECTS)

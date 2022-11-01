CC := gcc -std=c99 -pedantic
CFLAGS := -Wall -O2
LDLIBS := -lsem -lrt

SOURCES := sem semuse powielacz prog
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean
all:  libsem.a semuse.x powielacz.x prog.x

sem.o: sem.c sem.h

semuse.o: semuse.c sem.h
semuse.x: semuse.o

powielacz.o: powielacz.c sem.h
powielacz.x: powielacz.o

prog.o: prog.c sem.h
prog.x: prog.o

libsem.a: sem.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) -pthread -L. -o $@ $^ $(LDLIBS)

lib%.a: %.o
	ar rv $@ $^

clean:
	$(RM) *.x *.a $(OBJECTS)

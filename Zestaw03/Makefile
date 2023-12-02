#Makefile

CC      := gcc -std=c99
CFLAGS  := -Wall -O2

SOURCES := obsluga procinfo wysylaj grupa
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean

all: obsluga.x wysylaj.x grupa.x

obsluga.o:	obsluga.c procinfo.h
procinfo.o: procinfo.c procinfo.h
wysylaj.o:  wysylaj.c
grupa.o:	grupa.c

obsluga.x:  obsluga.o procinfo.o
wysylaj.x:	wysylaj.o
grupa.x:	grupa.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) -o $@ $^

clean: 
	$(RM) *.x $(OBJECTS)
# Makefile

CC	:= gcc -std=c99
CFLAGS  := -Wall -O2
LDFLAGS := 
LDLIBS  :=

SOURCES := main procinfo kopiuj deskryptor procesy lider 
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean
all: main.x kopiuj.x procesy.x lider.x

main.x: main.o procinfo.o
kopiuj.x: kopiuj.o deskryptor.o
procesy.x: procesy.o procinfo.o
lider.x: lider.o procinfo.o

main.o: main.c procinfo.h
procinfo.o: procinfo.c procinfo.h
kopiuj.o: kopiuj.c deskryptor.h
deskryptor.o: deskryptor.c deskryptor.h
procesy.o: procesy.c procinfo.h
lider.o: lider.c procinfo.h

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.x $(OBJECTS)

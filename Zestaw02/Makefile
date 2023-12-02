# Makefile

CC		:= gcc -std=c99
CFLAGS  := -Wall -O2
LDFLAGS := 
LDLIBS  :=

SOURCES := procinfo procesy potomny macierzysty zombi orphan execute drzewko1 drzewko2
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean
all: potomny.x macierzysty.x zombi.x orphan.x execute.x drzewko1.x drzewko2.x

potomny.x: potomny.o procinfo.o
macierzysty.x: macierzysty.o procinfo.o
zombi.x: zombi.o
orphan.x: orphan.o
execute.x: execute.o
drzewko1.x: drzewko1.o procinfo.o
drzewko2.x: drzewko2.o procinfo.o

procinfo.o: procinfo.c procinfo.h
potomny.o: potomny.c procinfo.h
macierzysty.o: macierzysty.c procinfo.h
zombi.o: zombi.c
orphan.o: orphan.c
execute.o: execute.c
drzewko1.o: drzewko1.c procinfo.h
drzewko2.o: drzewko2.c procinfo.h

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.x $(OBJECTS)

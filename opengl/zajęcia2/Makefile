CC 	    :=  gcc -O2
CFLAGS  := -Wall -pedantic
LIBPATH := -L./lib/x64/
INCLUDE := -I./include/
LIBS    := -lfreeglut -lglu32 -lOpenGL32 -lGdi32

FILES := zad1 zad2 zad3 zad4
SRC	  := ${addsuffix .c, ${FILES}}
OBJ	  := ${addsuffix .o, ${FILES}}
EXE   := ${addsuffix .exe, ${FILES}}

.PHONY: all clean run

all: ${EXE}

zad1.o:   zad1.c
zad1.exe: zad1.o

zad2.o:   zad2.c
zad2.exe: zad2.o

zad3.o:   zad3.c
zad3.exe: zad3.o

zad4.o:   zad4.c
zad4.exe: zad4.o

zad5.o:   zad5.c
zad5.exe: zad5.o

zad6.o:   zad6.c
zad6.exe: zad6.o

%.o: %.c
	${CC} -c -o ./obj/$@ $< ${CFLAGS} ${INCLUDE}

%.exe: %.o
	${CC} ${CFLAGS} -o ./bin/$@ ./obj/$^ ${LIBPATH} ${LIBS} -Wl,--subsystem,windows

clean:
	for file in ${OBJ} ; do \
		${RM} ./obj/$$file ; \
	done
	for file in ${EXE} ; do \
		${RM} ./bin/$$file ; \
	done
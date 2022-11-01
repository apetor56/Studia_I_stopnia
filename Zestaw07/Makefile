CC := gcc -std=c99 -pedantic
CFLAGS := -Wall -O2
LDLIBS := -lsem -lshmem -lrt 

SOURCES := sem shmem shmuse glowny producent konsument
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean
all: libsem.a libshmem.so shmuse.x shmuse1.x shmuse2.x glowny.x producent.x konsument.x 

sem.o: sem.c sem.h
libsem.a: sem.o
libshmem.so: shmem.c

shmuse.o: shmuse.c shmem.h sem.h
shmuse.x: shmuse.o
shmuse1.x: shmuse.o
shmuse2.x: shmuse.o



glowny.o: glowny.c shmem.h sem.h bufor.h
glowny.x: glowny.o

producent.o: producent.c shmem.h sem.h bufor.h
producent.x: producent.o

konsument.o: konsument.c shmem.h sem.h bufor.h
konsument.x: konsument.o

lib%.a: %.o
	ar rv $@ $^

lib%.so: %.c
	gcc -c -O -fPIC $<
	gcc -shared -o $@ shmem.o

%1.x: %.o
	$(CC) -pthread -L. -o $@ $^ $(LDLIBS)

%2.x: %.o
	$(CC) -pthread -L. -o $@ $^ $(LDLIBS) -Wl,-rpath ./

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) -pthread -L. -o $@ $^ $(LDLIBS)

clean:
	$(RM) *.x *.so *.a $(OBJECTS)

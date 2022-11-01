CC := gcc -std=c99 -pedantic
CFLAGS := -Wall -O2
LDLIBS := -lmsg -lrt 

SOURCES := msg serwer klient
OBJECTS := $(addsuffix .o, $(SOURCES))

.PHONY: all clean
all: libmsg.a libmsg.so serwer.x klient.x

sem.o: sem.c sem.h
libmsg.a : msg.o
libmsg.so: msg.o

msg.o: msg.c msg.h

serwer.o: serwer.c msg.h nazwy.h
serwer.x: serwer.o

klient.o: klient.c msg.h nazwy.h
klient.x: klient.o

lib%.a: %.o
	ar rv $@ $^

lib%.so: %.c
	gcc -c -O -fPIC $<
	gcc -shared -o $@ msg.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) -pthread -L. -o $@ $^ $(LDLIBS)

clean:
	$(RM) *.x *.so *.a $(OBJECTS)

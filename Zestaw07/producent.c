#define _XOPEN_SOURCE 500

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sem.h"
#include "shmem.h"
#include "bufor.h"

#define BUFFER_SIZE (1 * sizeof(char))                                   // rozmiar bufora

semid semProd;
semid semCons;
bufor *ptr;
int fd;
int size;

void push(towar znak) {
    semP(semProd);
    (ptr->buf)[(ptr->tail)] = znak;
    (ptr->tail)++;
    if((ptr->tail) == SIZE) (ptr->tail) = 0;
    semV(semCons); 
}

void end() {
    semClose(semProd);
    semClose(semCons);    
    shmClose(ptr, fd, size);
}

int main(int argc, const char* argv[]) {
    semProd = semOpen(argv[1]);
    semCons = semOpen(argv[2]);

    fd = shmOpen(argv[3]);
    size = shmSize(fd);
    ptr = (bufor *)shmMap(fd, size);
    ptr->head = 0;
    ptr->tail = 0;

    atexit(end);
    
    int des = open("magazyn.txt", O_RDONLY);
    towar *znak = (towar *)malloc(sizeof(towar));

    int odczyt = 0;
    while ((odczyt = read(des, znak, BUFFER_SIZE)) > 0) {
        push(*znak);
        printf("producent: umiescilem w buforze znak %c\n", *znak);
    }
    push('\0');

    if(odczyt == -1) {
        perror("(producent) read error");
        exit(1);
    }

    close(des);
    free(znak);
}
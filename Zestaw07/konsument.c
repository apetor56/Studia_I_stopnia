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

semid semProd, semCons;
bufor *ptr;
int fd, size;
int des;
towar *znak;

towar pop() {
    semP(semCons);
    towar x = (ptr->buf)[(ptr->head)];
    (ptr->head)++;
    if((ptr->head) == SIZE) (ptr->head) = 0;
    semV(semProd);

    return x;
}

void end() {
    close(des);
    free(znak);
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

    des = open("schowek.txt", O_WRONLY);
    int rozmiar = sizeof(towar);
    znak = (towar *)malloc(rozmiar);

    *znak = pop();
    printf("konsument: pobralem znak %c\n", *znak);
    int w;
    while ( (w = write(des, znak, rozmiar)) != -1 ) {
        *znak = pop();
        if(*znak == '\0') break;
        printf("konsument: pobralem znak %c\n", *znak);
    }

    atexit(end);
    
    if(w == -1) {
        perror("write error");
        exit(1);
    }
}
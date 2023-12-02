#include <stdio.h>
#include "sem.h"

int main(int argc, const char *argv[]){         // w każdej opcji, poza inicjalizacją, używam
    const char *semName = "/semafor";           // semClose(), by pod koniec zamknąc semafor dla 
    semid sem, sem_opened;                      // dla danego procesu

    switch(argv[1][0]){
        case 'i':
        sem = semCreate(semName, 1);
        semInfo(sem);
        break;

        case 'r':
        sem_opened = semOpen(semName);
        semClose(sem_opened);
        semRemove(semName);
        break;

        case 'p':
        sem_opened = semOpen(semName);
        semP(sem_opened);
        semInfo(sem_opened);
        semClose(sem_opened);
        break;

        case 'v':
        sem_opened = semOpen(semName);
        semV(sem_opened);
        semInfo(sem_opened);
        semClose(sem_opened);
        break;

        case 'q':
        sem_opened = semOpen(semName);
        semInfo(sem_opened);
        semClose(sem_opened);
        break;
    }
}
#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "sem.h"

int main(int argc, const char *argv[]){
    int num_iter = atoi(argv[1]);       // liczba sekcji krytycznych == liczbie iteracji
    int pid = getpid();
    printf("%c[%dm PID %d: Jestem przed sekcja krytyczna\n", 0x1B, 0, pid);

    const char *sem_name = "/semafor", *plik = "numer.txt";
    semid sem_opened = semOpen(sem_name);       // otworznie semafora dla procesu

    for(int i = 0; i < num_iter; i++){
    usleep(rand() % 10);    // uśpienie przed wejściem do sekcji krytycznej
    semP(sem_opened);

    int *buf = (int*)malloc(sizeof(int));       // dynamiczne zaalokowanie pamięci
        printf("\t%c[%dm PID %d: Wszedlem do sekcji krytycznej nr. %d\n", 0x1B, 31, pid, i);

        int des = open(plik, O_RDONLY);     // otworznie pliku z którego mamy pobrać liczbę
        if(des == -1){
            perror("open error");
            semClose(sem_opened);       // w razie błędu zamykam semafor dla tego procesu
            exit(1);
        }

        int rd = read(des, buf, sizeof(int));   // odczytanie wartości
        if(rd == -1){
            perror("read error");
            semClose(sem_opened);       // zamknięcie semafora w razie błędu
            exit(2);
        }
        printf("\t%c[%dm PID %d: Odczytana liczba: %d\n", 0x1B, 31, pid, *buf);
        (*buf)++;       // zwiększenie wartości odczytaniej liczby
        close(des);     // zamknięcie deskryptora

        usleep(rand() % 10);    // uśpienie przed zapisaniem do pliku

        int des2 = open(plik, O_WRONLY, 0644);      // otworzenie pliku
        int wr = write(des2, buf, sizeof(int));     // i zapisanie do niej zwiększonej wartości
        if(wr == -1){
            perror("write error");
            semClose(sem_opened);       // zamknięcie semafora w razie błedu
            exit(3);
        }
        close(des2);    // zamknięcie deskryptora
    
    free(buf);      // po wszystkich iteracjach zwolnienie pamięci

    semV(sem_opened);
    printf("%c[%dm PID %d: Wyszedlem z sekcji krytycznej\n", 0x1B, 34, pid);
    }
    semClose(sem_opened);       // zamknięcie semafora
}
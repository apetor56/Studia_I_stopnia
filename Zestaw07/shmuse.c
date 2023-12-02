#include <stdio.h>
#include <string.h>
#include "sem.h"
#include "shmem.h"

#define BUF_SIZE (1024 * sizeof(char))

void info() {
    printf("./shmuse.x c size - Tworzy segment pamięci dzielonej o rozmiarze size bajtów.\n"
            "./shmuse.x d - Usuwa segment pamięci dzielonej.\n"
            "./shmuse.x r - Wypisuje zawartość pamięci dzielonej na standardowe wyjście.\n"
            "./shmuse.x w < input.txt - Kopiuje zawartość standardowego wejścia do pamięci dzielonej.\n");
}
int main(int argc, const char *argv[]) {
    const char *name = "/shared_memory";
    int size = 0;           // rozmiar utworzonego segmentu pamięci dzielonej (jeśli został podany w linii komend)
    int fd, shm_size;       // fd, shm_size i ptr służą do przechowywania danych
    char *ptr;              // zwracanych przez funkcje w bibliotece libshmem.so

    if(argc == 1) {
        info();
        return 0;
    }

    switch(argv[1][0]) {
        case 'c':
        size = atoi(argv[2]);
        shmCreate(name, size);      // stworzenie segmentu pam. dziel.
        break;

        case 'd':
        shmRm(name);        // usunięcie segmentu pam. dzielonej
        break;

        case 'r':
        fd = shmOpen(name);             // otworzenie segmentu, sprawdzenie jego rozmiaru i odwzorowanie
        shm_size = shmSize(fd);         // go w wirtualnej przestrzeni adresowej procesu
        ptr = shmMap(fd, shm_size);
        printf("%s\n", ptr);            // wypisanie zawartości segmentu
        shmClose(ptr, fd, shm_size);    // zamknięcie segmentu dla tego procesu
        break;

        case 'w':
        fd = shmOpen(name);                 // otworzenie segmentu, sprawdzenie jego rozmiaru i odwzorowanie
        shm_size = shmSize(fd);             // go w wirtualnej przestrzeni adresowej procesu
        ptr = shmMap(fd, shm_size);

        char *buf = malloc(BUF_SIZE);
        int r1;
        while( (r1 = read(0, buf, BUF_SIZE)) > 0) {
            if(r1 > shm_size) {
                printf("rozmiar danych z pliku jest wieksza od rozmiaru pamieci dzielonej\n");
                break;
            }
            else {
                strcpy(ptr, buf);
                shm_size -= r1;
            }
            free(buf);
        }
        if(r1 == -1) {
            perror("read error");
            exit(1);
        }
        shmClose(ptr, fd, shm_size);
        break;

        case 'i':                       
        fd = shmOpen(name);             // otworzenie segmentu, sprawdzenie jego rozmiaru i odwzorowanie
        shm_size = shmSize(fd);         // go w wirtualnej przestrzeni adresowej procesu
        ptr = shmMap(fd, shm_size);
        shmInfo(fd);                    // wyświetlenie o nim informacji
        shmClose(ptr, fd, shm_size);    // zamknięcie segmentu
        break;
    }
}
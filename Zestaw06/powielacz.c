#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "sem.h"

semid sem;              // deklaruję zmienne globalne, ponieważ są potrzebne do
const char* sem_name;   // wywołania funkcji end(), która jest zarejestowana
                        // przez atexit()
void end() {
    semClose(sem);          // zamknięcie oraz ununięcie semafora
    semRemove(sem_name);
}

void handler(int signum){   // obsługa sygnału (SIGINT), w razie gdyby trzeba było
    semClose(sem);          // zakończyć program za pomocą CTRL-C
    semRemove(sem_name);
    printf("Zamknieto i usunieto semafor\n");
    _exit(0);    
}

int main(int argc, const char *argv[]) {

    sem_name = "/semafor";
    sem = semCreate(sem_name, 1);               // stworzenie semafora z wartością początkową 1
    semInfo(sem);
    printf("Adres semafora: %p\n", (void*)sem);
    atexit(end);

    if(signal(SIGINT, handler) == SIG_ERR){
        perror("signal error");
        exit(-1);
    }

    const char *plik = "./numer.txt";                   // stworzenie nowego pliku, do którego
    int des = open(plik, O_WRONLY | O_CREAT, 0644);     // zapiszemy wartość 0
    if(des == -1) {                                     // + obsługa błędu
        perror("open error");
        exit(1);
    }

    int *buf = (int*)malloc(sizeof(int));           // dynamiczne zaalokowanie pamięci
    *buf = 0;                                       // przypisanie zmiennej wartości 0
    int wr = write(des, buf, sizeof(int));          // i zapisanie jej do pliku o nazwie "numer.txt"
    if(wr == -1) {                                  // + obsługa błędu
        perror("write error");
        exit(2);
    }
    close(des);     // zamknięcie deskryptora i zwolnienie pamięci
    free(buf);

    int num_proc = atoi(argv[2]);           // liczba procesów potomnych
    for(int i = 0; i < num_proc; i++) {
        const char *path;                   
        switch(fork()){
            case -1:
            perror("fork error");
            exit(3);

            case 0:
            path = "./prog.x";
            execl(path, argv[1], argv[3], NULL);   // uruchomienie programu prog.x (argv[1])
            perror("execl error");                 // z liczbą sekcji krytycznych procesu (argv[3])
            _exit(4);                              // wykonujemy _exit() zamiast exit(), ponieważ przy
                                                   // przy wielekrotnych błedach wywołania execl() usunęlibyśmy
            default:                               // semafor więcej niż jeden raz
            break;
        }
    }
    for(int i = 0; i < num_proc; i++) {   // proces macierzysty czeka na swoje procesy potomne
        int status;
        if(wait(&status) == -1) {         // + obsługa błędu
            perror("wait error");
            exit(5);
        }
    }

    int des2 = open(plik, O_RDONLY);    // po zakończeniu pracy p. potomnych
    if(des2 == -1){                     // otwieramy wcześniej utworzony plik
        perror("open error");
        exit(6);
    }

    int *buf2 = (int*)malloc(sizeof(int));      // i odczytujemy z niego liczbę
    int rd = read(des2, buf2, sizeof(int));
    if(rd == -1){
        perror("read error");
        exit(7);
    }

    printf("%c[%dmKoncowa liczba: %d\n", 0x1B, 0, *buf2);
    int num_sk = atoi(argv[3]);
    if(*buf2 == num_proc * num_sk) printf("Otrzymano poprawna liczbe\n");
    else printf("Otrzymano zla liczbe\n");
}
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>

const char* fifo_name;              // stała zawierająca nazwę potoku, potrzebna do poniższej funkcji 

void end()                          // funkcja wykonywana przy zakończeniu procesu
{                                   // usuwająca potok nazwany
    if(unlink(fifo_name) == -1)
    {
        perror("unlink error");
        exit(1);
    }
}

void handler(int signum)                    // obsługa sygnału (konkretnie SIG_INT)
{                                           // w razie gdyby trzeba było zakończyć proces
    if(unlink(fifo_name) == -1)             // za pomocą CTRL-C
    {
        perror("(handler) unlink error");
        exit(1);
    }
    else printf("Usunieto potok\n");
    _exit(0);
}

int main(int argc, const char *argv[])
{
    fifo_name = argv[5];                    // stała globalna przyjmuje nazwę potoku
    int fifo = mkfifo(argv[5], 0644);       // stworzenie fifo
    if(fifo == -1)                          // + obsługa błędu
    {
        perror("mkfifo error");
        exit(1);
    }

    if(signal(2, handler) == SIG_ERR)       // własna obsługa sygnału SIG_INT
    {                                       // + obsługa błędu
        perror("signal error");
        exit(1);
    }

    for(int i = 0; i < 2; i++)
    {
        switch(fork())
        {
            case -1:
            perror("fork error");
            _exit(1);               // _exit() nie wywoła funkcji zarejestrowanej przez
                                    // atexit(), więc unikniemy kilkukrotnego usunięcia potoku

            case 0:
            execl(argv[i + 1], argv[i + 1], argv[5], argv[i + 3], NULL);
            /* wywołanie dwóch programów, kolejno producent.x, konsument.x z potrzebnymi
            argumentami tj. nazwami plików .txt (argv[i + 3]) oraz nazwą potoku (argv[5]) */

            perror("execl error"); // + obsługa błędu
            _exit(1);              // _exit() nie wywoła funkcji zarejestrowanej przez
        }                          // atexit(), więc unikniemy kilkukrotnego usunięcia potoku
    }

    for(int i = 0; i < 2; i++)
    {
        int status;                     // proces macierzysty czeka na swoje 2 procesy potomne
        if(wait(&status) == -1)         // + obsługa błedu funkcji wait()
        {
            perror("wait error");
            exit(1);
        }
    }

    if(atexit(end) == -1)           // zarejestrowanie funkcji end()
    {                               // + obsługa błędu
        perror("atexit error");
        exit(1);
    }

    exit(0);                       // po poprawnym działaniu programu
                                   // zostanie uruchomiona funkcji end()
}
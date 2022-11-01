#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, const char* argv[])
{
    if(argc != 3){                                                      // sprawdzenie liczby argumentow
        printf("Podano zla liczbe argumentow\n");
        exit(EXIT_FAILURE);
    }

    int pid_potomny = fork();
    switch(pid_potomny)
    {
        case 0:
        execl("./obsluga.x", "obsluga.x", argv[1], argv[2], NULL);      // wykonanie programu obsluga.x z argumentami
        perror("execl");                                                // podanymi w linii komend
        _exit(EXIT_FAILURE);
        break;

        case -1:
        perror("fork error");
        exit(EXIT_FAILURE);

        default:
        sleep(1);                                               // sleep jest po to, by sie upewnic, ze
                                                                // sygnal zostanie wyslany do p.potomnego,
                                                                // ktory wykonuje program obsluga.x, a nie wysylaj.x
        if(kill(pid_potomny, 0) == -1){                         
            perror("kill && PID error");                        // sprawdzenie, czy m.in. istnieje proces o danym PID                  
            exit(EXIT_FAILURE);
        }

        int k = kill(pid_potomny, atoi(argv[2]));               // wyslanie do p.potomnego sygnalu o numerze              
        if(k == -1){                                            // podanym w linii komend
            perror("kill error");
            exit(EXIT_FAILURE);
        }

        int status;                                             // oczekiwanie procesu na zakonczenie jego
        pid_t w_status = wait(&status);                         // p.potomnego
        if(w_status == -1){
            perror("wait error");
            exit(EXIT_FAILURE);
        }
    }
}
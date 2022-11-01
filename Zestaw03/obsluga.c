#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "procinfo.h"

//typedef void (*sighandler_t)(int);
//sighandler_t signal(int sig, sighandler_t handler);

void my_signalhandler(int sig){                 // funkcja do obslugi sygnalu
    printf("Numer sygnalu: %d\n", sig);
}

int main(int argc, const char* argv[])
{
    if(argc != 3 || strlen(argv[1]) != 1){      // wyjscie z programu w wypadku zle podanych
        printf("Podano zle argumenty.\n");      // argumentow
        exit(EXIT_FAILURE);
    }
    procinfo(argv[0]);
    int sig = atoi(argv[2]);                    // liczba, ktora zostala podana w linii komend,
                                                // lecz jest typu int, a nie const char*
    switch(argv[1][0])
    {
        case 'd':
        if(signal(sig, SIG_DFL) == SIG_ERR){    // ustawienie domyslnej obslugi
            perror("sig error");                // dla sygnalu
            exit(EXIT_FAILURE);
        }                   
        break;                                  

        case 'i':
        if(signal(sig, SIG_IGN) == SIG_ERR){   // zignorowanie synalu
            perror("sig error");
            exit(EXIT_FAILURE);
        }                   
        break;

        case 'p':
        if(signal(sig, my_signalhandler) == SIG_ERR){    // wlasne ustawienia obslugi sygnalu
            perror("sig error");
            exit(EXIT_FAILURE);
        }         
        break;

        default:
        printf("Podano zle argumenty\n");       // podanie niezdefiniowanej obslugi sygnalu
        exit(EXIT_FAILURE);
        break;
    }
    pause();                                    // oczekiwanie na przyjscie sygnalu
}
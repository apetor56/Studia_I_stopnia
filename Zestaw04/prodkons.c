#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "prog.h"

int main(int argc, const char* argv[])
{
    int file_des[2];
    int my_pipe = pipe(file_des);       // utworzenie potoku nienazwanego
    if(my_pipe == -1)                   // + obsługa błedu
    {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    switch(fork())
    {
        case -1:
        perror("fork error");
        exit(EXIT_FAILURE);

        case 0:                            // w konsumencie tylko pobieramy dane z potoku,
        close(file_des[1]);                // więc zamykamy deskryptor do zapisu
        fun(file_des[0], 2);               // działanie dla konsumenta, funkcja w konsument.c
        break;

        default:                           // w producencie tylko zapisujemy dane do potoku
        close(file_des[0]);                // więc zamykamy deskryptor do odczytu                
        fun(file_des[1], 1);               // funkcja dla producenta, definicja w producent.c

        int status;                         // następnie proces macierzyty czeka na swój proces
        if(wait(&status) == -1)             // potomny
        {                                   // + obsługa błedu funkcji wait()
            perror("wait error");
            exit(EXIT_FAILURE);
        }
        break;
    }
}
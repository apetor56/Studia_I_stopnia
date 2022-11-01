#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "deskryptor.h"

#define BUFFOR_SIZE (sizeof(char) * 1024)

int main(int argc, const char* argv[])
{
    arg_error(argc, argv[0]);                              // sprawdzenie, czy podano odpowiednią liczbę argumentów  

    int original = open_original(argv[1]);                 // otworzenie originalnego pliku
    int copy = open_copy(argv[2]);                         // utworzenie kopii

    char* buf = (char*)malloc(BUFFOR_SIZE);
    
    ssize_t d1 = 0, d2 = 0;
    while((d1 = read(original, buf, BUFFOR_SIZE)) > 0)     // odczytywanie z originalnego pliku max 1024kB do buffora
    {
        d2 = write(copy, (const char*)buf, d1);            // wypisanie zawartości buffora do pliku o nazwie argv[2]
        if(d2 == -1)
        {
            perror("Blad zapisu");
            exit(1);
        }
    } 
     
    close(d1);
    close(d2);  
    close(original);
    close(copy);

    free(buf);

    return 0;
}

#define _XOPEN_SOURCE 500

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "prog.h"

#define BUFFER_SIZE (10 * sizeof(char))              // rozmiar bufora, 5 bajtów

void fun(int pipe_des, int option) 
{
    const char *name = NULL, *komunikat = NULL;
    int id_odczytu = 0;
    int docelowy_zapis = 0;

    switch(option)              // ustalenie plików do odczytu/zapisu, w zależności od tego,
    {                           // czy dany proces to producent, czy konsument
        case 1:
        komunikat = "Producent: ";
        name = "magazyn.txt";                   // 1 oznacza producenta, będzie on pracował na pliku "magazyn.txt".
        id_odczytu = open(name, O_RDONLY);      // jedynie odczytuje z niego dane (więc flaga O_RDONLY)     
        if(id_odczytu == -1)
        {
            perror("(magazyn) open error");
            exit(1);
        }
        docelowy_zapis = pipe_des;               // a odczytane dane zapisuje w potoku
        break;

        case 2:
        komunikat = "Konsument: ";               // 2 oznacza konsumenta, zapisuje dane w pliku "schowek.txt"
        name = "schowek.txt";
        id_odczytu = pipe_des;                   // po wcześniejszym odczytaniem ich z potoku
        docelowy_zapis = open(name, O_WRONLY); 
        if(docelowy_zapis == -1)
        {
            perror("(schowek) open error");
            exit(1);
        }
        break;
    }                   
    
    char* buf = (char*)malloc(BUFFER_SIZE);         // utworzenie bufora znaków
    int odczyt = 0, zapis = 0;                      // odczyt - liczba odczytanych bajtów, zapis - zapisanych

    while( (odczyt = read(id_odczytu, buf, BUFFER_SIZE)) > 0)  // dopóki można coś odczytywać z pliku 
    {
        usleep(rand() % 10);  
        zapis = write(docelowy_zapis, buf, odczyt);    // zapisanie odczytanych bajtów do danego pliku
        if(zapis == -1)                                // + obsługa błędu funkcji write()
        {
            perror("write error");
            exit(1);
        }

        int kom = write(STDOUT_FILENO, komunikat, 12);
        int wys = write(STDOUT_FILENO, buf, zapis);         // wypisanie zapisanej zawartości na ekran
        int endl = write(STDOUT_FILENO, "\n", 2);           // + obsługa błędu                                
        if(kom == -1 || wys == -1 || endl == -1)                                   
        {
            perror("blad wyswietlenia");
            exit(1);
        }
    }

    if(odczyt == -1)                        // jeśli pojawił się jakiś błąd przy odczycie z pliku
    {
        perror("read error");
        exit(1);
    }

    close(id_odczytu);         // zamknięcie deskryptorów i zwolnienie pamięci
    close(pipe_des);
    free(buf);
}


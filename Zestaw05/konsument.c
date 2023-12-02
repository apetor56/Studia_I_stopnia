#define _XOPEN_SOURCE 500

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE (10 * sizeof(char))                                   // rozmiar bufora

int main(int argc, const char* argv[])
{
    int id_fifo = open(argv[1], O_RDONLY);              // otworzenie kolejki fifo wyłącznie do odczytu
    if(id_fifo == -1)                                   // + obsługa błędu
    {
        perror("(konsument) fifo error");
        exit(1);
    }

    int id_schowka = open(argv[2], O_WRONLY, 0644);     // otworzenie pliku, w którym będzie zapisywana 
    if(id_schowka == -1)                                // zawartość fifo
    {                                                   // + obsługa błędu
        perror("(konsument) open error");
        exit(1);
    }

    char* buf = (char*)malloc(BUFFER_SIZE);             // utworzenie bufora na znaki
    int odczyt = 0, zapis = 0;                          // odczyt - odczytane bajty, zapis - zapisane

    while( (odczyt = read(id_fifo, buf, BUFFER_SIZE)) > 0)  // dopóki można odczytywać jakieś dane z fifo
    {
        usleep(2000);
        zapis = write(id_schowka, buf, odczyt);             // to zapisujemy je do pliku
        if(zapis == -1)                                     // + obsługa błędu
        {
            perror("(producent) write error");
            exit(1);
        }

        int kom = write(STDOUT_FILENO, "konsument: ", 12);
        int wys = write(STDOUT_FILENO, buf, zapis);         // wyświetlenie zawartości zapisanej do pliku
        int endl = write(STDERR_FILENO, "\n", 1);           // (lub inaczej pobranej z fifo)
        if(kom == -1 || wys == -1 || endl == -1)            // + obsługa błedu    
        {                                                   
            perror("blad wyswietlenia");
            exit(1);
        }
    }

    close(id_schowka);      // zamknięcie deskryptorów i zwolnienie pamięci
    close(id_fifo);
    free(buf);
}
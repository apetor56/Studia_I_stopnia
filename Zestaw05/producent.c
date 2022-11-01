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
    int id_fifo = open(argv[1], O_WRONLY);              // otworzenie pliku fifo tylko do zapisu
    if(id_fifo == -1)                                   // + obsługa błędu
    {
        perror("fifo open error");
        exit(1);
    }
    
    int id_magazynu = open(argv[2], O_RDONLY);          // otworzenie pliku, z którego będziemy pobierać dane
    if(id_magazynu == -1)                               // + obsługa błędu
    {
        perror("(producent) open error");
        exit(1);
    }

    char* buf = (char*)malloc(BUFFER_SIZE);             // stworzenie bufora znaków
    int odczyt = 0, zapis = 0;                          // odczyt - odczytane bajty, zapis - zapisane

    while( (odczyt = read(id_magazynu, buf, BUFFER_SIZE)) > 0)      // dopóki można coś odczytać z pliku
    {
        usleep(1000);
        zapis = write(id_fifo, buf, odczyt);                        // to zapisujemy to do kolejki fifo
        if(zapis == -1)                                             // + obsługa błędu
        {
            perror("(producent) write error");
            exit(1);
        }

        int kom = write(STDOUT_FILENO, "producent: ", 12);
        int wys = write(STDOUT_FILENO, buf, zapis);
        int endl = write(STDERR_FILENO, "\n", 1);                   // wypisanie na ekran zawartosci
        if(kom == -1 || wys == -1 || endl == -1)                    // zapisanej do kolejki fifo
        {                                                           // + obsługa błędu
            perror("blad wyswietlenia");
            exit(1);
        }
    }   

    if(odczyt == -1)                        // jeśli pojawił się w którymś momencie błąd odczytu
    {
        perror("(producent) read error");
        exit(1);
    }

    close(id_magazynu);         // zamknięcie deskryptorów i zwolnienie pamięci
    close(id_fifo);
    free(buf);
}
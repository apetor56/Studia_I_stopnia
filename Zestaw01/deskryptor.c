#include "deskryptor.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int open_original(const char* name)
{
    int original = open(name, O_RDONLY);
    if(original == -1)
    {
        perror(name);
        exit(1);
    }

    return original;
}

int open_copy(const char* name)
{
    int copy = open(name, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);  // O_CREAT i O_EXCL pozwalają ustalić
    if(copy < 0)                                                            // czy istnieje już plik o nazwie name
    {                                                                       // S_IRUSR | S_IWUSR - umożliwa odczyt
        perror(name);                                                       // oraz modyfikację utworzonej kopii
        exit(1);
    }

    return copy;
}

void arg_error(int count, const char* name)
{
    if(count != 3)
    {
        printf("%s: Uzyto nieprawidlowej liczby argumentow.\nPoprawne wywolanie programu: ./kopiuj.x <pelna_sciezka_originalu> <nazwa kopii>\n", name);
        exit(1);
    }
}
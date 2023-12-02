#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "procinfo.h"



int main(int argc, const char* argv[])
{
    procinfo(argv[0]);
    sleep(2);
    
    int tmp = 0;                                // zmienna pomocnicza, która później pozwoli określić, ile razy 
                                                // proces macierzysty ma wykonać funkcję wait()
    for(int i = 0; i < 3; i++)
    {                                           
        switch (fork())                         
        {
            case -1:
            perror("fork() error");
            exit(1);
    
            case 0:
            tmp = i + 1;                        // zapamiętujemy, w której iteracji został utworzony dany proces potomny oraz dodajemy 1. Gdy od 3 odejmiemy
                                                // 3 - tmp: liczba procesów potomnych naszego nowo utworzonego procesu
            procinfo("Proces potomny");
            sleep(2);                           // proces potomny jest uśpiony, by nie wywołał funkcji fork()
            break;                              // oraz żeby jego proces macierzysty utworzył pozostałe procesy potomne
                                                // które są w tym samym pokoleniu
            default:
            if(i == 2)                          // "jeśli proces macierzy utworzył już wszystkie swoje procesy potomne"
            {
                int f;
                for(int j = 3 - tmp; j > 0; j--)    // wykonujemy 3 - tmp razy funkcję wait(). Np. nasz pierwszy proces wykona wait()
                {                                   // 3 razy, jego pierwszy proces potomny 3 - tmp(tutaj 1) = 2 razy, jego drugi proces
                    pid_t w = wait(&f);             // potomny 3 - tmp(tutaj 2) = 1 raz, a jego trzeci proces potomny 3 - tmp(tutaj 3) = 0 razy,
                    if(w == -1)                     // co by odpowiadało liczbie procesów potomnych tych procesów
                    {
                        perror("wait() error");
                        exit(1);
                    }
                }
            }                             
            break;                        
        }
    }


    return 0;
}
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
    
    int tmp = 0;                                
                                                
    for(int i = 0; i < 3; i++)
    {                                           
        switch (fork())                         
        {
            case -1:
            perror("fork() error");
            exit(1);
    
            case 0:
            tmp = i + 1;                    // numer iteracji (wartość zmiennej i), w której proces potomny                  
            procinfo("Proces potomny");     // po raz pierwszy wywoła funkcję fork()
            sleep(2);
            break;                              
                                                
            default:
            i = 2;                         // proces macierzysty nie utworzy już nowych procesów potomnych,                   
            break;                         // więc każdy proces wywołujący funkcję fork() będzie miał dokłanie jednego potomka,                       
        }                                  // czyli trzeba będzie wykonać funkcję wait() jeden raz
    }

    if(tmp != 3){                           // proces potomny, który wykonałby po raz pierwszy funckję fork()
        int f;                              // w iteracji i == 3 nie będzie miał dzieci, więc nie powinien wywoływać                          
        pid_t w = wait(&f);                 // funkcji wait()
        if(w == -1)                     
        {
            perror("wait() error");
            exit(1);
        }
    }
    
            
    return 0;
}
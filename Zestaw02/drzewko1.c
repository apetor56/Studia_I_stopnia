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
            i = 2;                          // proces potomny nie wykona już funkcji fork(), ponieważ złamie warunek pętli (i < 3),
            tmp = i + 1;                    // a poniżej nie wykona również funckji wait()    
            procinfo("Proces potomny");
            sleep(2);
            break;                              
                                                
            default:                            
            break;                        
        }
    }

    int f;
    for(int j = 3 - tmp; j > 0; j--)       // 3 - tmp -> licznik procesów potomnych danego procesu
    {                                   
        pid_t w = wait(&f);             
        if(w == -1)                     
        {
            perror("wait() error");
            exit(1);
        }
    }
            
    return 0;
}
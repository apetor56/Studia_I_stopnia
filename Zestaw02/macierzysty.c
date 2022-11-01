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
    char* const tab[] = {"potomny.x", NULL};        // utworzenie tablicy, której adres przekazywany
                                                    // jest do funkcji execv()
    for(int i = 0; i < 3; i++)
    {                                           
        switch (fork())                         
        {
            case -1:
            perror("fork() error");
            exit(1);
    
            case 0:
            tmp = i + 1;                        
                                                
            int e = execv("potomny.x", tab);        // przerwanie bieżącego procesu i rozpoczęcie
            if(e == -1)                             // wykonywania programu potomny.x
            {
                perror("execv");
                exit(1);
            }
            sleep(2);                           
            break;                              
                                                
            default:                            
            break;                        
        }
    }

    int f;
    for(int j = 3 - tmp; j > 0; j--)    
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
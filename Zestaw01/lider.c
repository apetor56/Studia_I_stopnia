#define _XOPEN_SOURCE 500

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

    int f;
    int tmp = 0;
    for(int i = 0; i < 3; i++)
    {
        switch (fork())
        {
            case -1:
            perror("Fork error");
            exit(1);
            
            case 0:
            tmp = i + 1;

            f = setpgid(getpid(), 0);           // getpid() -> ID obecnego procesu potomnego. Gdy drugi argument funkcji
            if(f == -1)                         // setpgid() jest równy 0, to obecny proces potomny staje się liderem
            {                                   // nowej grupy
                perror("Setpgid error");
                exit(1);
            }   

            procinfo("Proces potomny");     
            sleep(2);                       
            break;                          
                                            
            default:
            if(i == 2)                         
            {
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
            }                             
            break;                          
        }
    }

    return 0;
}
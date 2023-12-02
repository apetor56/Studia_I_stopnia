#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }
    
    else if(pid == 0){                      // proces potomny niemalże od razu kończy działanie
        ;
    }
    else if(pid != 0){                     // lecz proces macierzysty "zwkleka" z odebraniem statusu (poprzez funkcję wait())
        int f;                             // procesu potomnego, co powoduje, że proces potomny nadal istnieje w tablicy
        sleep(5);                          // procesów, mimo że zakończył swoje działanie

        pid_t s = wait(&f);
        if(s == -1){
            perror("wait error");
            exit(1);
        }
    }

    return 0;
}
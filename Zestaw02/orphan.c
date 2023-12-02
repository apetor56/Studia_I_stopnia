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
    
    else if(pid != 0){                                          // proces macierzysty niemalże od razu zakończy
        printf("Proces macierzysty bez funkcji wait()\n");      // swoje działanie
    }

    else if(pid == 0){
        sleep(10);                                             // natomiast proces potomny zakończy się dopiero po 
        printf("Proces osierocony\n");                         // 10 sekundach (po swoim "ojcu")
    }                                                     

    return 0;
}
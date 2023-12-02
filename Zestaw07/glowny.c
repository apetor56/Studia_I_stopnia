#include <stdio.h>
#include <sys/wait.h>
#include "sem.h"
#include "shmem.h"
#include "bufor.h"

const char *semProd_name = "/sem_prod";
const char *semCons_name = "/sem_cons";
const char *shm_name = "/shared_memory";

void end() {
    semRemove(semProd_name);
    semRemove(semCons_name);
    shmRm(shm_name);
}

int main(int argc, const char *argv[]) {
    int shm_size = sizeof(bufor);
    shmCreate(shm_name, shm_size);

    semCreate(semProd_name, SIZE - 1);
    semCreate(semCons_name, 0);

    atexit(end);

    const char *path[] = {"./producent.x", "./konsument.x"};
    for(int i = 0; i < 2; i++) {
        switch(fork()) {
            case -1:
            perror("fork error");
            exit(1);

            case 0:
            execl(path[i], argv[i], semProd_name, semCons_name, shm_name, NULL);
            perror("exelc error");
            _exit(2);

            default:
            break;
        }
    }

    int status;
    for(int i = 0; i < 2; i++) {
        if(wait(&status) == -1) {
            perror("wait error");
            exit(3);
        }
    }

    return 0;
}
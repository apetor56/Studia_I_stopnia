#include "sem.h"

semid semCreate(const char *name, int val){     //  /samename
    semid sem = sem_open(name, O_CREAT | O_EXCL, 0666, val);
    if(sem == SEM_FAILED){
        perror("semCreate error");
        exit(1);
    }

    return sem;
}

void semRemove(const char *name){
    int delete = sem_unlink(name);
    if(delete == -1){
        perror("semRemove error");
        exit(2);
    }
}

semid semOpen(const char *name){
    semid open = sem_open(name, O_RDWR);
    if(open == SEM_FAILED){
        perror("semOpen error");
        exit(3);
    }

    return open;
}

void semClose(semid sem){
    int close = sem_close(sem);
    if(close == -1){
        perror("semClose error");
        exit(4);
    }
}

void semP(semid sem){
    int wait = sem_wait(sem);
    if(wait == -1){
        perror("semP error");
        exit(5);
    }
}

void semV(semid sem){
    int post = sem_post(sem);
    if(post == -1){
        perror("semV error");
        exit(5);
    }
}

void semInfo(semid sem){
    int sval;
    int info = sem_getvalue(sem, &sval);
    if(info == -1){
        perror("semInfo error");
        exit(6);
    }

    printf("Wartosc semafora: %d\n", sval);
}
#include <stdio.h>      // perror
#include <stdlib.h>     // exit
#include "shmem.h"

int shmCreate(const char* name, int size) {
    int fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0666);
    if(fd == -1) {
        perror("shmCreat error");
        exit(1);
    }

    int ftrun = ftruncate(fd, size);
    if(ftrun == -1) {
        perror("ftruncate error");
        exit(2);
    }

    return fd;
}

int shmOpen(const char* name) {
    int fd = shm_open(name, O_RDWR, 0000);
    if(fd == -1) {
        perror("shmOpen error");
        exit(3);
    }

    return fd;
}

void shmRm(const char* name) {
    int rm = shm_unlink(name);
    if(rm == -1) {
        perror("shmRm error");
        exit(4);
    }
}

void* shmMap(int fd, int size) {
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(ptr == MAP_FAILED) {
        perror("shmMap error");
        exit(5);
    }

    return ptr;
}

void shmClose(void *ptr, int fd, int size) {
    int mmap = munmap(ptr, size);
    if(mmap == -1) {
        perror("shmClose error");
        exit(6);
    }

    int cl = close(fd);
    if(cl == -1) {
        perror("shared memory's descriptor close error");
        exit(7);
    }
}

int shmSize(int fd) {
    struct stat statbuf;
    int fs = fstat(fd, &statbuf);
    if(fs == -1) {
        perror("fstat error");
        exit(8);
    }

    return (int)statbuf.st_size;
}

void shmInfo(int fd) {
    struct stat statbuf;
    int fs = fstat(fd, &statbuf);
    if(fs == -1) {
        perror("fstat error");
        exit(8);
    }

    printf("User ID of owner: %d\nFile type and mode: %o\nTotal size, in bytes: %ld\n",
           statbuf.st_uid, statbuf.st_mode, statbuf.st_size);
}
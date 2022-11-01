#ifndef SHMEM_H
#define SHMEM_H

#define _XOPEN_SOURCE 500   // fstat
#include <sys/mman.h>       // shm
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>         // ftruncate
#include <sys/types.h>

// export LD_LIBRARY_PATH=.

int shmCreate(const char* name, int size);

int shmOpen(const char* name);

void shmRm(const char* name);

void* shmMap(int fd, int size);

void shmClose(void *ptr, int fd, int size);

int shmSize(int fd);

void shmInfo(int fd);

#endif // SHMEM_H
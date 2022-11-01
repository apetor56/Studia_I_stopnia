#ifndef MSG_H
#define MSG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>           
#include <sys/stat.h>
#include <string.h>        
#include <mqueue.h>
// export LD_LIBRARY_PATH=.

#define BUFSIZE 10240

typedef struct komunikat {
    int pid;
    int a, b;
    char o;
} komunikat;

typedef struct mq_attr mq_attr;

mqd_t msgCreate(const char *name);

mqd_t msgOpen(const char *name, int oflag);

void msgClose(int msgid);

void msgRm(const char *name);

void msgSend(int msgid, komunikat *msg);
    
void msgRecv(int msgid, komunikat *msg);

void msgInfo(int msgid);

#endif // MSG_H
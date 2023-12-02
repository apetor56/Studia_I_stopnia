#include "msg.h"

mqd_t msgCreate(const char *name) {
    mqd_t mqdes = mq_open(name, O_RDWR | O_CREAT | O_EXCL, 0644, NULL);
    if(mqdes == (mqd_t)-1) {
        perror("creat MQ error");
        exit(1);
    }

    return  mqdes;
}

mqd_t msgOpen(const char *name, int oflag) {
    mqd_t mqdes = mq_open(name, oflag);
    if(mqdes == (mqd_t)-1) {
        perror("open MQ error");
        exit(2);
    }

    return mqdes;
}

void msgClose(int msgid) {
    int mqClose = mq_close(msgid);
    if(mqClose == -1) {
        perror("close MQ error");
        exit(3);
    }
}

void msgRm(const char *name) {
    int mqRm = mq_unlink(name);
    if(mqRm == -1) {
        perror("unlink MQ erorr");
        exit(4);
    }
}

void msgSend(int msgid, komunikat *msg) {
    char buf[BUFSIZE];
    unsigned int prio = 1;
    sprintf(buf, "PID %d: %d%c%d", msg->pid, msg->a, msg->o, msg->b);
    int send = mq_send(msgid, buf, strlen(buf) + 1, prio);
    if(send == -1) {
        perror("send MQ error");
        exit(5);
    }
}
    
void msgRecv(int msgid, komunikat *msg) {
    unsigned int prio;
    char buf[BUFSIZE];
    int receive = mq_receive(msgid, buf, BUFSIZE, &prio);
    if(receive == -1) {
        perror("receive MQ error");
        exit(6);
    }

    sscanf((const char*)buf, "PID %d: %d%c%d", &(msg->pid), &(msg->a), &(msg->o), &(msg->b));
}

void msgInfo(int msgid) {
    mq_attr attr;
    int info = mq_getattr(msgid, &attr);
    if(info == -1) {
        perror("get info MQ error");
        exit(7);
    }

    printf("mq_flags  : %lX\n", attr.mq_flags);
    printf("mq_maxmsg : %ld\n", attr.mq_maxmsg);
    printf("mq_msgsize: %ld\n", attr.mq_msgsize);
    printf("mq_curmsgs: %ld\n", attr.mq_curmsgs);
}
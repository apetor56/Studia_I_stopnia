#ifndef BUFOR_H
#define BUFOR_H

#define SIZE 8
typedef char towar;
typedef struct bufor bufor;

struct bufor {
    int size, head, tail;
    towar buf[SIZE];
};

#endif // BUFOR_H
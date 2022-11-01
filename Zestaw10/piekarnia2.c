#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

#define THREADS 5
#define CRITICAL_SECTION 3

typedef enum{ BEFORE = 0, PENDING = -1, AFTER = 1 } state;

volatile int val = 0;
volatile int num[THREADS];
volatile state pick[THREADS];

volatile int max(volatile int num[]) {
    int m = INT_MIN;
    for(int i = 0; i < THREADS; i++) {
        if(m < num[i])
            m = num[i];
    }
    return m;
}

void lock(int i) {
    for(int j = 0; j < THREADS; j++) {
        while(pick[j] != AFTER); // wait
        while(num[j] != 0 && (num[j] < num[i] || (num[j] == num[i] && j < i)) ); // wait
    }
}

void unlock(int i) {
    num[i] = 0;
}

void *fun(void *arg) {
    int  i = *(int *)arg;
    
    for(int l = 0; l < CRITICAL_SECTION; l++) {
        pick[i] = PENDING;
        num[i] = max(num) + 1;
        pick[i] = AFTER;

        lock(i);
            val++;
        unlock(i);
    }
    
    printf("%d\n", val);  
    free(arg);
    return NULL;
}

int main() {
    pthread_t th[THREADS];

    for(int i = 0; i < THREADS; i++) {
        int *arg = (int *)malloc(sizeof(int));
        *arg = i;
        if( pthread_create(th + i, NULL, fun, arg) != 0 ) {
            printf("pthread_creat error\n");
            exit(1);
        }
    }

    for(int i = 0; i < THREADS; i++) {
        if( pthread_join(th[i], NULL) != 0 ) {
            printf("pthread_join error\n");
            exit(2);
        }
    }
}
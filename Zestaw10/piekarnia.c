#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

#define THREADS 5
#define CRITICAL_SECTION 3

typedef enum{ BEFORE = 0, PENDING = -1, AFTER = 1 } state;

typedef struct position {
    int x, y;
} position;

void set_xy(int x, int y) {                 
    printf("\033[%d;%dH\033[2K", y, x);
    printf("\033[%dm", 30 + y);
}

volatile int val = 0;
volatile int num[THREADS];
volatile int copy[THREADS];
volatile state pick[THREADS];

volatile int max(volatile int tab[]) {
    int m = INT_MIN;
    for(int i = 0; i < THREADS; i++) {
        if(m < num[i])
            m = num[i];
    }
    return m;
}

void lock(int i) {
    for(int j = 0; j < THREADS; j++) {
        /*if(i != 3)*/ while(pick[j] != AFTER); // wait
        while(num[j] != 0 && (num[j] < num[i] || (num[j] == num[i] && j < i)) ); // wait
    }
}

void unlock(int i) {
    num[i] = 0;
}

void *fun(void *arg) {
    position a = *(position *)arg;
    int i = a.y - 1;
    int x = a.x, y = a.y;
    
    for(int l = 0; l < CRITICAL_SECTION; l++) {
        //if(i != 3) {
        pick[i] = PENDING;
            num[i] = max(num) + 1;
            set_xy(0, y);                       // wyświetlenie komunikatu po lewej stronie
            printf("thread no. %d", y);         // przed sekcją krytyczną 
            copy[i] = num[i];
        pick[i] = AFTER;
        //}
        //else num[i] = max(num) + 1;

        lock(i);
            val++;
            set_xy(x, y);
            printf("Critical section (%d)\n", y);   // wyświetlenie komunikatu po prawej stronie,
            sleep(1);                       
            set_xy(0, y);                   // przed wyjściem czyszczę aktualną linię
        unlock(i);
    }
    
    set_xy(0, y);                     // pod koniec wyświetlam końcowy komunikat
    printf("thread no. %d - END", y);  
    free(arg);
    return NULL;
}

int main() {
    printf("\033c");            // wyczyszczenie całej konsoli
    pthread_t th[THREADS];

    for(int i = 0; i < THREADS; i++) {
        position *arg = (position *)malloc(sizeof(position));
        arg->y = i + 1;
        arg->x = 25;
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

    set_xy(0, THREADS + 4);
    printf("\033[0m");      // ustawienie normalnego tekstu
    //for(int i = 0; i < THREADS; i++) printf("%d ", copy[i]);
    //printf("\n");
}
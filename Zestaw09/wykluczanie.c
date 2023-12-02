#define _POSIX_C_SOURCE 200808L
#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5               // liczba wątków
#define CRITICAL_SECTION 3      // liczba sekcji krytycznych dla każdego wątku

pthread_mutex_t mutex;
volatile int val = 0;

typedef struct position {
    int x, y;
} position;

void set_xy(int x, int y) {                 
    printf("\033[%d;%dH\033[2K", y, x);
    printf("\033[%dm", 30 + y);
}

void *fun(void *arg) {
    position a = *(position *)arg;
    int x = a.x, y = a.y;
    int val_pri;

    for(int i = 0; i < CRITICAL_SECTION; i++) {
        set_xy(0, y);                       // wyświetlenie komunikatu po lewej stronie
        printf("thread no. %d", y);         // przed sekcją krytyczną  

        sleep(1);
        pthread_mutex_lock(&mutex);
            val_pri = val;
            val_pri++;
            usleep(10);
            val = val_pri;
            set_xy(x, y);
            printf("Critical section (%d)\n", y);   // wyświetlenie komunikatu po prawej stronie,
            sleep(1);                       
            set_xy(0, y);                   // przed wyjściem czyszczę aktualną linię
        pthread_mutex_unlock(&mutex);

        set_xy(0, THREADS + 2);         // wyświetlam zwiększoną liczbę
        printf("Value: %d\n", val);
    }

    set_xy(0, y);                     // pod koniec wyświetlam końcowy komunikat
    printf("thread no. %d - END", y);   
    free(arg);      // zwolnienie dynamicznie zaalokowanego zasobu

    return NULL;
}

int main(void) {
    printf("\033c");            // wyczyszczenie całej konsoli

    pthread_t th[THREADS];
    int mInit_value = pthread_mutex_init(&mutex, NULL);     // utworzenie mutexu
    if(mInit_value != 0) {
            printf("pthread_mutex_init error no. %d\n", mInit_value);
            exit(1);
    }
    
    for(int i = 0; i < THREADS; i++) {
        position *arg = (position *)malloc(sizeof(position));
        arg->x = 25;            // ustawienie kolomny/wiersza dla danego wątku
        arg->y = i + 1;
        
        int creat_value = pthread_create(th + i, NULL, fun, arg);   // stworzenie wątku
        if(creat_value != 0) {
            printf("pthread_creat error no. %d\n", creat_value);
            exit(2);
        }
    }

    for(int i = 0; i < THREADS; i++) {
        int join_value = pthread_join(th[i], NULL);             // proces główny czeka na zakończenie
        if(join_value != 0) {                                   // wszystkich wątków
            printf("pthread_join error no. %d\n", join_value);
            exit(3);
        }
    }

    pthread_mutex_destroy(&mutex);      // usunięcie mutexu

    set_xy(0, THREADS + 4);
    printf("\033[0m");      // ustawienie normalnego tekstu
}
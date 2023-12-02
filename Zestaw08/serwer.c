#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "msg.h"
#include "nazwy.h"

mqd_t open_mq;

void signal_handler() {         // w razie użycia CTRL-C proces
    msgClose(open_mq);          // zamknie kolejkę serwera i ją usunie
    msgRm(serwer);
}

int main() {
    mqd_t mq_ser = msgCreate(serwer);               // stworzenie kolejki dla serwera
    msgInfo(mq_ser);                                // wyświetlenie o nim danych
    open_mq = msgOpen(serwer, O_RDONLY);            // otworzenie tej kolejki tylko do odczytu

    if(signal(2, signal_handler) == SIG_ERR) {      // obsługa sygnału SIGINT
        perror("signal error");
        exit(1);
    }

    while(1) {
        komunikat kom;              // proces będzie czekał na komunikat ze swojej kolejki
        msgRecv(open_mq, &kom);     // i zapisze go w pod adresem &kom                   
                                                    
        char klient[10];                            // utworzenie bufora znakowego
        sprintf(klient, "/%d", kom.pid);            // zapisanie w nim PID klienta, który wysłał komunikat
        mqd_t mq_kli = msgOpen(klient, O_WRONLY);   // oraz otworzenie kolejki klienta
        
        switch(kom.o) {     // w zależności od operatora
            case '+':
            printf("serwer dla klienta(%d): %d %c %d = %d\n", kom.pid, kom.a, kom.o, kom.b, kom.a+kom.b);
            kom.a+=kom.b;       // w kom.a zapisuję wynik działania, podobnie jak poniżej
            break;

            case '-':
            printf("serwer dla klienta(%d): %d %c %d = %d\n", kom.pid, kom.a, kom.o, kom.b, kom.a-kom.b);
            kom.a-=kom.b;
            break;

            case '*':
            printf("serwer dla klienta(%d): %d %c %d = %d\n", kom.pid, kom.a, kom.o, kom.b, kom.a*kom.b);
            kom.a*=kom.b;
            break;

            case '/':
            if(kom.b != 0) {
                printf("serwer dla klienta(%d): %d %c %d = %d\n", kom.pid, kom.a, kom.o, kom.b, kom.a/kom.b);
                kom.a/=kom.b;
            }   
            else
                printf("Nie mozna dzielic przez 0\n");
            break;
        }
        
        sleep(rand() % 2);          // proces czeka na wysłanie komunikatu z wynikiem do klienta
        
        msgSend(mq_kli, &kom);     
        msgClose(mq_kli);           // po wysłaniu zamyka tę kolejkę u siebie
    }
}
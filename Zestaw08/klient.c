#include <stdio.h>
#include <unistd.h>
#include "msg.h"
#include "nazwy.h"

mqd_t mq_ser;
mqd_t open_mq;
char klient[10];

void fun() {
    printf("Prosze podac wyrazenie z jednym z podanych dzialan: +, -, *, /\n");
}

void end() {                
    msgClose(mq_ser);       // zamknięcie kolejki serwera
    msgClose(open_mq);      // zamknięcie kolejki klienta
    msgRm(klient);          // usunięcie kolejki klienta
}

int main() {
    atexit(end);

    int pid = getpid();             // uzyskanie PIDu procesu
    sprintf(klient, "/%d", pid);    // przeformatowany PID jest zapisany do bufora znakowego

    mqd_t mq_kli = msgCreate(klient);       // stworzenie kolejki klienta o nazwie /PID
    msgInfo(mq_kli);                        // wyświetlenie informacji o kolejce
    open_mq = msgOpen(klient, O_RDONLY);    // otworzenie kolejki klienta do odczytu

    char buf[BUFSIZE];
    fun();
    while( fgets(buf, BUFSIZE, stdin) != NULL ) {       // zapisanie wyrażenia z stdin do bufora
        komunikat kom;          // utworzenie komunikatu
        kom.pid = pid;          // przypisanie do jednego z atrybutów komunikatu wartości PID procesu
        sscanf( (const char*)buf, "%d%c%d", &kom.a, &kom.o, &kom.b);        // zapisanie przeformatowanych danych z równania do komunikatu

        mq_ser = msgOpen(serwer, O_WRONLY);     // otwarcie kolejki serwera do zapisu
        msgSend(mq_ser, &kom);                  // wysłanie komunikatu

        sleep(rand() % 3);                      // proces czeka przed otrzymaniem komunikatu

        msgRecv(open_mq, &kom);
        if(kom.o == '/' && kom.b != 0)
            printf("klient %d: otrzymany wynik to %d\n", pid, kom.a);

        fun();
    }
}
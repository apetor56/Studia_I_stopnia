<div align="center"><h1>Zestaw 8 - Kolejki komunikatów</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Zadanie 1: biblioteka statyczna i dzielona: `msg.o msg.h`
Zadanie 2: serwer i klient_: `serwer.c klient.c nazwy.h`  

Ponadto tworzona jest biblioteka statyczna `libmsg.a` która zawiera plik obiektowy `msg.o` oraz biblioteka dynamiczna `libmsg.so`, zawierająca plik `msg.o`.
Plik `nazwy.h` zawiera nazwę kolejki serwera.

* * *

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x, .a, .so lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

- _serwer oraz klient_
  - w jednym terminalu uruchamiany jest proces serwera: `./serwer.x`
  - w innych terminalach uruchamiany jest proces klienta: `./klient.x`

***

## 3. Działanie programów ##

_serwer.x_:
	Proces tworzy kolejkę serwera o nazwie podanej w pliku `nazwy.h` oraz otwiera go w trybie wyłącznie do odczytu. Następnie oczekuje na przyjście komunikatu (od klienta) do tej kolejki. Gdy go otrzyma, to otwiera kolejkę klienta, o nazwie jego PIDu (podanego w komunikacie). Po tym wykonuje działanie zadane w komunikacie, a rezultat odsyła do kolejki klienta. Po udanym wysłaniu proces serwera zamyka otwartą u siebie kolejkę klienta. Wszystkie te działania wykonywane są w nieskończonej pętli `while(1)`, więc aby zakończyć proces, należy użyć sekwencji `CTRL-C`. W programie ustawiono obsługę sygnału `SIGINT` - gdy ten sygnał zostanie wysłany do procesu, to zamknie on swoją kolejkę komunikatów oraz następnie ją usunie.

_klient.x_:
	Proces klienta tworzy kolejkę komunikatów o nazwie jego PIDu. Następnie otwiera ją wyłącznie do odczytu. Dla ułatwienia używam tutaj funkcji `sprintf()`.  Następnie, dopóki pobieram działanie z linii komend, otwieram kolejkę serwera wyłącznie do zapisu i wysyłam do niego komunikat. Gdy proces klienta kończy swoje działanie, to dzięki funkcji `end()`,  zarejestrowanej przez `atexit()`,  zamyka otwartą kolejkę komunikatów serwera, klienta oraz usuwa kolejkę klienta.

***

## 4. Odpowiedzi na pytania.

**Opisać działanie, argumenty i wartość zwracaną przez funkcję `mq_open`**

​	`mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);` - jeśli jedna z wartości `oflag` jest ustawiona na `O_CREAT`, to `mq_open()` tworzy nową kolejkę o nazwie `name`. Jeśli dodatkowo w oflag mamy `O_EXCL` to sprawdzane jest, czy istnieje dana kolejka o nazwie `name`. Inne z opcji `oflag` to np. `O_RDWR`, `O_RDONLY`, `O_WRONLY`. W argumencie `mode` przechowywane są prawa dostępu, z jakimi zostanie utworzona kolejka. `attr` to wskaźnik na strukturę atrybutów kolejki. Jeśli jest równy `NULL`, to tworzona jest kolejka z domyślnymi ustawieniami dla danej implementacji.
​	W razie powodzenia funkcji `mq_open()` zwracany jest deskryptor utworzonej kolejki, w razie błędu zwracany jest `-1`.

​	`mqd_t mq_open(const char *name, int oflag);` - otwiera kolejkę o nazwie `name` z opcjami `oflag`. W razie powodzenia funkcji `mq_open()` zwracany jest deskryptor otwartej kolejki, w razie błędu zwracany jest `-1`.



**Opisać działanie, argumenty i wartość zwracaną przez funkcję `mq_send` i `mq_receive`**

​	`mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);` - dodaje komunikat `msq_ptr` o długości `msg_len` do kolejki o deskryptorze `mqdes`. Priorytet tego komunikatu jest przechowywany w `msg_prio`. W razie powodzenia zwraca `0`, natomiast w razie błędu zwraca `-1`.

​	`mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio)`; - usuwa z kolejki o deskryptorze `mqdes` najstarszy komunikat o najwyższym priorytecie. Komunikat umieszczany jest w buforze `msg_ptr` o rozmiarze `msg_len`. Jeśli `msg_prio` jest różny od `NULL`, to pod tym adresem zapisywany jest priorytet otrzymanego komunikatu. W razie powodzenia `mq_receive` zwraca `0`, w razie błędu - `-1`.



**Czy kolejki komunikatów standardu POSIX są widoczne w systemie plików, gdzie?**

​	Tak, są tworzone w wirtualnym systemie plików, najczęściej widoczne w `/dev/mqueue`.



**Jak otrzymać informacje o parametrach kolejki komunikatów?**

​	Należy użyć w funkcji `mq_getattr(mqd_t mqdes, struct mq_attr *attr)`. Wszystkie atrybuty kolejki o deskryptorze `mqdes` zostaną zapisane pod adresem `attr`.

* * *
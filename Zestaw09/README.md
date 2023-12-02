<div align="center"><h1>Zestaw 9 - Wątki</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Zadanie 1: Wzajemne wykluczanie wątków: `wykluczanie.c`

***

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x, .a, .so lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

- _wykluczanie_: `./wykluczanie.x`

***

## 3. Działanie programów ##

_wykluczanie.x_:
	Program na samym początku czyści okno terminala (w celu wyświetlenie późniejszych sformatowanych danych) oraz tworzy mutex za pomocą funkcji `pthread_mutex_creat()`. Następnie tworzę określoną liczbę wątków i dla każdego z nich dynamicznie alokuję pamięć dla danych typu `struct position`, w których przechowuję zmienne `int x` (oznacza nr kolumny w terminalu) oraz `int y` (nr wiersza). Następnie po utworzeniu wszystkich wątków wywołuję funkcję `pthread_join()` (tyle razy, ile jest wątków), by proces zaczekał na wykonanie się wszystkich swoich wątków.
	Funkcja, której adres wraz z odpowiednim argumentem przekazujemy do funkcji `pthread_mutex_creat()`, ma za zadanie wyświetlać odpowiednie komunikaty dla danych wątków: po lewej stronie wyświetlany jest komunikat, gdy wątek nie jest w sekcji krytycznej, natomiast gdy się w niej znajduje, to wyświetla komunikat po prawej stronie. Dla każdego wątku zarezerwowane są linia w terminalu oraz kolor komunikatu.

***

## 4. Odpowiedzi na pytania.

**Czym się różni wątek od procesu?**

​	Wszystkie wątki, działające w danym procesie, współdzielą przestrzeń adresową oraz inne dane, natomiast procesy mają niezależne zasoby.



**Opisać działanie, argumenty i wartość zwracaną przez funkcję `pthread_create()`.**

`	int pthread_create(pthread_t *pthreadID, const pthread_attr_t *attr, void * (*start_fun) (void *), void *arg);`

- `pthreadID` - wskaźnik na obiekt typu `pthread_t`, pod którym zostanie zapisany niepowtarzalne ID wątku (w razie `NULL` identyfikator nie będzie zapisany),
- `attr` - wskaźnik na dynamicznie zarezerwowaną strukturę atrybutów wątku (w razie `NULL` będziemy mieli domyślne atrybuty),
- `start_fun` - wskaźnik na zdefiniowaną przez programistę funkcję. Przyjmuje wskaźnik na `void` i zwraca wskaźnik na `void`,
- `arg` - wskaźnik na argument, który będziemy chcieli przekazać do funkcji `start_fun()`.

Funkcja ta tworzy nowy wątek i od razu zaczyna wykonywać funkcję, której adres przekazaliśmy. W razie powodzenie `pthread_create()` zwraca wartość `0`, w innym wypadku zwraca niezerową watość.



**Funkcja `pthread_join()` jest odpowiednikiem której funkcji dla procesów?**

​	Jest odpowiednikiem dla `wait()`.



**Czym się różnią muteksy od semaforów?**

​	Mają odwrotną konwencję do semaforów: `0` w muteksie oznacza, że wątek może wejść do sekcji krytycznej, natomiast `1` zablokuje dany wątek.



**Jak stworzyć muteks (dwa sposoby)?**

- `pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;`
- `pthread_mutex_t myMutex;
  pthread_mutex_init(&myMutex, NULL);`



**Opisać działanie operacji, które możemy wykonać na muteksach.**

- `pthread_mutex_lock(&mutex);` - zmieniamy wartość muteksa na 1 - jeden wątek działa w sekcji krytycznej, a reszta jest zablokowana,
- `pthread_mutex_unlock(&mutex);` - zmieniamy wartość muteksa na 0 - wątek wychodzi z sekcji krytycznej, odblokowując tym samym inne wątki



**Dlaczego musimy zdefiniować makro `_REENTRANT`?**
	Dajemy wtedy znak kompilatorowi, że proces będzie obsługiwany przez więcej niż jeden wątek.



**Co oznacza typ `void * (*) ()`?**
	Wskaźnik na `void`, który nie przyjmuje żadnych argumentów.



**Co to są operacje atomowe? Czy są konieczne?**
	Są to operacje niepodzielne, tzn. że muszą być wykonane w całości bez przerwania. Oznacza to, że tylko jeden wątek jednocześnie może coś wykonać.

* * *
<div align="center"><h1>Zestaw 6 - Semafory</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Potoki nazwane_: `sem.c, sem.h, semuse.c, powielacz.c, prog.c, numer.txt`,
ponadto tworzona jest biblioteka `libsem.a` która zawiera plik obiektowy `sem.o`.

* * *

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x, .a lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

*   _semuse.x_: `./semuse.x <operacja>`, gdzie `operacja` to:
    - `i` - Inicjuje semafor i wypisuje o nim informacje,
    - `r` - Usuwa semafor,
    - `p` - Opuszcza semafor i wypisuje o nim informacje,
    - `v` - Podnosi semafor i wypisuje o nim informacje,
    - `q` - Wypisuje informacje o semaforze.
*   _powielacz.x_: `./powielacz.x prog.x <liczba_procesów> <liczba_sekcji_krytyczych>`,
    gdzie `<liczba_procesów>` to liczba użycia `fork() + execl()`.

***

## 3. Działanie programów ##

_semuse.x_:
	W tym programie wykonywane są określone czynności na semaforze. We wszystkich przypadkach, oprócz inicjalizacji semafora, używam funkcji `semClose()` do zamknięcia semafora dla danego procesu.

_powielacz.x_:
	W tym programie tworzona jest liczba procesów potomnych, których liczba podana jest w linii komend, a następnie te procesy uruchamiają program `prog.x`. Program ten pobiera pewną liczbę z pliku tekstowego `numer.txt`, zwiększa ją o 1, a następnie nadpisuje w tym samym pliku. Wszystkie te czynności odbywają się w sekcji krytycznej semafora, których liczba podana jest w linii komend. Program `prog.x` wypisuje również odpowiednie komunikaty przed, w trakcie oraz po sekcji krytycznej.
	Proces macierzysty czeka na zakończenie działania wszystkich swoich procesów potomnych. Semafor zamykany jest za pomocą funkcji `end()`, która jest zarejestrowana przez `atexit()`. W razie, gdyby trzeba było ręcznie zamknąć i usunąć semafor, dodałem obsługę sygnału `SIGINT`. Po wciśnięciu sekwencji CTRL-C zostaną wykonane powyższe czynności. 

***

## 4. Odpowiedzi na pytania 

**Do czego służą *semafory* w systemach UNIX?**

Służą do synchronizacji procesów, poprzez wprowadzenie wyłącznego dostępu do pewnego zasobu dzielonego.



**Opisz operacje, które można wykonać na semaforach.**

`sem_open(name, O_CREAT | O_EXCL, mode, val)` - stworzenie (o ile nie istnieje) nowego semafora o nazwie `name`, z prawami dostępu `mode` oraz wartością początkową `val`,

`sem_open(name, flag)` - otworzenie semafora o nazwie `name`,

`sem_unlink(name)` - usunięcie semafora o nazwie `name,`

`sem_close(sem)` - zamknięcie semafora, poprzez podanie jego adresu,

`sem_wait(sem)` - zmniejszenie wartości semafora o adresie `sem` o 1,

`sem_post(sem)` - zwiększenie wartości semafora o adresie `sem` o 1,

`sem_getvalue(sem, &sval)` - otrzymanie wartości semafora o adresie `sem`, która jest zapisywana w zmiennej `sval`.



**W jaki sposób niezależne procesy mogą korzystać ze wspólnych semaforów?**

Poprzez przekazanie nazwy istniejącego semafora do funkcji `sem_open()`. W ten sposób proces może korzystać z semafora, utworzonego przez inny proces.



**Czym jest biblioteka statyczna? Jakie są jej zalety?**

Jest to archiwum plików obiektowych. Gdy kompilujemy jakiś plik rodzaju `.c` i załączymy do niego bibliotekę (za pomocą `-l`), to do tego pliku załączane są tylko potrzebne pliki obiektowe, a nie wszystkie.



**Jak utworzyć bibliotekę statyczną? Jak jej używać?**

Na przykładzie zadań z tego zestawu:
1) Najpierw tworzę plik obiektowy `sem.o`: `gcc -c -o sem.c sem.o`.
2) Następnie tworzę bibliotekę oraz dodaję do niej utworzony plik obiektowy: `ar rv libsem.a sem.o`.
3) Przy kompilacji programu do pliku wykonywalnego dodaję tę bibliotekę po podaniu pliku źródłowych:
	`gcc -std=c99 -pedantic -pthread -L. -o $@ $^ -lsem -lrt` 

* * *
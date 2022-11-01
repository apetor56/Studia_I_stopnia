<div align="center"><h1>Zestaw 4 - Potoki nienazwane</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Potoki nienazwane_: prodkons.c, prog.c, prog.h

prog.c - zawiera definicję funkcji, która wykonuje określone działania na potoku nienazwanym, w zależności od tego, czy proces jest producentem/konsumentem.

* * *

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

*   _Potoki nienazwane_: ./prodkons.x
    

***

## 3. Działanie programów ##

_prodkons.x_:
	W tym programie tworzony jest potok nienazwany, który do tablicy `file_des[2]` zwraca numery deskryptorów. Następnie wywołuję funkcję `fork()` do utworzenie procesu potomnego. W procesie macierzystym, za pomocą funkcji `fun()` wykonuję działanie dla producenta, więc zamykam deskryptor potoku do odczytu. W procesie potomnym wykonywane są działania dla konsumenta, więc zamykam w nim deskryptor potoku do zapisu.

***

## 4. Odpowiedzi na pytania z zestawu 4 . i 5.

**Co zwraca funkcja `pipe()`?**

W razie powodzenia zwraca 0, a w razie porażki -1.



**Czym się różni funkcja `pipe()` od `mkfifo()`? Co robią te funkcje?**

`pipe()` tworzy potok nienazwany, a `mkfifo()` potok nazwany. Ponadto funkcja `pipe()` łączy tylko procesy pokrewne, np. "ojciec" z "synem", "prawnuk" z "dziadkiem", natomiast `mkfifo()` może łączyć ze sobą niezależne procesy. Potoki FIFO (nazwane) można również tworzyć z poziomu powłoki. 



**Co oznacza akronim FIFO?**

FIFO - _first in first out_: dane, które zostały zapisane jako pierwsze, zostaną również pierwsze odczytane. 



**Co to jest deskryptor?**

Jest to identyfikator pliku dla danego procesu.



**Jak i dlaczego zamykamy deskryptory w zadaniu 1.?**

Za pomocą funkcji `close()` zamykamy odpowiednie deskryptory w procesie potomnym i macierzystym. Należy tak zrobić, ponieważ funkcja `pipe()` tworzy domyślnie jednokierunkowy potok, więc nie chcemy, by jakiś proces jednocześnie odczytywał/zapisywał dane z/do potoku.



**Proszę sprawdzić co się stanie jeżeli nie zamkniemy deskryptorów w zadaniu 1.?**

Proces nie zakończy swojego działania.



**Jak utworzyć i usunąć potok nazwany z linii komend a jak z poziomu programu?**

`mkfifo [-m mode] filename` - utworzenie z poziomu powłoki,
`unlink filename` - usunięcie z poziomu powłoki,
`mkfifo(const char *path, modetmode)` - utworzenie z poziomu programu,
`unlink(const char *pathname)` - usunięcie z poziomu powłoki.

* * *
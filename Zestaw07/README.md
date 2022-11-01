<div align="center"><h1>Zestaw 7 - Pamięć dzielona</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Zadanie 1: biblioteka dzielona: `shmem.h sem.h`
Zadanie 2: shmuse.c_: `shmuse.c shmem.h sem.h`  
_Zadanie 3: producent i konsument_: `glowny.c producent.c konsument.c shmem.h sem.h bufor.h`

Ponadto tworzona jest biblioteka statyczna `libsem.a` która zawiera plik obiektowy `sem.o` oraz biblioteka dynamiczna `libshmem.so`, zawierająca plik `shmem.o`.
Plik `bufor.h` zawiera strukturę bufora cyklicznego.

* * *

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x, .a lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

*   _Zadanie 2_: 
    - `./shmuse.x c size` - Tworzy segment pamięci dzielonej o rozmiarze `size` bajtów.
    - `./shmuse.x d` - Usuwa segment pamięci dzielonej
    - `./shmuse.x r` - Wypisuje zawartość pamięci dzielonej na standardowe wyjście.
    - `./shmuse.x w < input.txt` - Kopiuje zawartość standardowego wejścia do pamięci dzielonej. Sprawdzić rozmiar segmentu.
    - `./shmuse.x i` - Wypisuje informacje o pamięci dzielonej.
    - `./shmuse.x` - Wypisuje informacje o użyciu tego programu.
*   _Zadanie 3_: `./glowny.x producent.x konsument.x`

***

## 3. Działanie programów ##

_shmuse.x_:
	Tak jak opisano wyżej w opcjach programu.

_glowny.x_:
	Tworzy segment pamięci oraz dwa semafory, które dbają o to, by nie wpisywać danych do pełnego bufora oraz by ich nie odczytywać, gdy bufor jest pusty. Za wpisywanie danych z pliku `magazyn.txt` do bufora odpowiedzialny jest program `producent.x`, a za odczyt danych i zapisanie ich w pliku `schowek.txt` - `konsument.x`. Oba te programy uruchamiane są w programie `glowny.x` (2x funkcja `fork()` + `execl()`). `glowny.x` czeka na swoje dzieci (2x funkcja `wait()`), a po zakończeniu ich pracy proces macierzysty usuwa utworzone wcześniej semafory oraz segment pamięci dzielonej.

***

## 4. Odpowiedzi na pytania.

**Szczegółowo opisz działanie semaforów z zadaniu 3.**

​	W programie `producent.x` na początku funkcji `push()` obniżamy wartość semafora producenta o 1 (jego początkowa wartość wynosi liczbę wolnych miejsc), co oznacza, że w buforze jest 1 miejsce mniej do zapisu. Następnie podnosimy wartość semafora konsumenta o 1 (jego początkowa wartość to 0), co z kolei oznacza zwiększoną o 1 liczbę miejsc w buforze, z których konsument może pobrać dane i zapisać je w pliku tekstowym.
​	W programie konsumenta sytuacja wygląda podobnie. W funkcji `push()` obniżamy wartość semafora konsumenta o 1, co oznacza, że ma do odczytu o 1 mniej danych. Następnie, gdy pobierze już dane z bufora, to podnosi wartość semafora producenta o 1. Wtedy program producenta wie, że zwolniło się jedno miejsce z bufora, gdzie może zapisać następne dane.



**W jaki sposób niezależne procesy mają dostęp do tego samego segmentu pamięci dzielonej?**

​	Poprzez funkcję `mmap()`. Dzięki niej procesy odwzorowują segment pamięci dzielonej w swoją wirtualną przestrzeń adresową.



**Czym jest biblioteka dynamiczna? Jakie są jej zalety?**

​	Jest to biblioteka, która dołączana jest jest do programu dopiero w chwili jego wykonania. Dane z tych bibliotek mogą być używane przez różne programy jednocześnie. Ponadto biblioteki te ładowanie są do pamięci tylko raz, nawet jeśli są razem współużytkowane.



**Jak utworzyć bibliotekę dynamiczną? Jak jej używać? Jakie są nazwy plików, które są bibliotekami dynamicznymi?**

Aby utworzyć bibliotekę dynamiczną, należy wpisać poniższe komendy:

-  `gcc -c -O -fPIC shmem.c` - czyli skompilować plik `shmem.c` do pliku obiektowego z opcją `-fPIC`
- `gcc -shared -o libshmem.so shmem.o` - utworzyć bibliotekę dynamiczną

Aby korzystać z tej biblioteki należy ją dodać z opcją `-l`:

- `gcc shmemuse.c -L. -lshmem`

Nazwy bibliotek dynamicznych zaczynają się przyrostkiem `lib`, a ich rozszerzenie to `.so`. lub `.dll`.

* * *
<div align="center"><h1>Zestaw 5 - Potoki nazwane</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Potoki nazwane_: fifo.c, producent.c, konsument.c 
dodatkowo pliki tekstowe: magazyn.txt, schowek.txt 

* * *

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

*   _Potoki nazwane_: ./fifo.x producent.x konsument.x magazyn.txt schowek.txt _fifoname_
    fifoname: nazwa potoku

***

## 3. Działanie programów ##

_fifo.x_:
	Na początku tworzony jest potok o nazwie podanej w linii komend. Następnie tworzone są 2 procesy potomne, które za pomocą funkcji `exel()` uruchamiają odpowiednio programy `producent.x` oraz `konsument.x`. Proces macierzysty czeka na swoje procesy potomne (2x `wait()`) a następnie, za pomocą (zarejestrowanej przez `atexit()`)  funkcji `end()` , proces potomny usuwa potok nazwany. W razie jakiś błędu została dodana obsługa sygnału `SIGINT`, w razie gdyby trzeba było usunąć potok i zakończyć proces za pomocą sekwencji CTRL-C.

 _producent.x_, _konsument.x_:
	Podobnie jak w poprzednim zestawie odpowiadają za konkretną obsługę potoku nazwanego. Producent otwiera potok wyłącznie do zapisu, zaś konsument tylko do odczytu.

* * *
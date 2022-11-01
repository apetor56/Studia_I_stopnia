<div align="center"><h1>Zestaw 2 - Execute</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Zadanie 1_

*   drzewko1.c
*   drzewko2.c
*   procinfo.c
*   procinfo.h

_Zadanie 2_

*   macierzysty.c
*   potomny.c
*   procinfo.c
*   procinfo.h

_Zadanie 3_

*   zombi.c
*   orphan.c
*   execute.c

***

## 2. Wyniki programów

Zadanie 1:

- _drzewko1.x_: Dla głównego procesu wyświetla wszystkie jego dzieci (w tym zadaniu powstaną łącznie 4 procesy),
- _drzewko2.x_: Dla głównego procesu wyświetla jego pierwsze dziecko, dla tego dziecka też wyświetla jego pierwsze dziecko itd, aż do momentu, gdzie dany proces nie ma dziecka (w tym programie powstaną łącznie 4 procesy).

Zadanie 2:

- _macierzysty.x_: Program wywołuje funkcję fork(), nowo utworzony proces wykonuje funkcję execv(), który kończy bieżący proces potomny i uruchamia program _potomny.x_. W tym zadaniu powstają 4 procesy,
- _potomny.x_: wyświetla za pomocą funkcji `procinfo()` informacje o poszczególnych ID danego procesu.

Zadanie 3:

- _zombi.x_: tworzy proces zombi za pomocą funkcji `sleep()` użytej w przypadku procesu macierzystego,
- _orphan.x_: tworzy proces osierocony za pomocą funkcji `sleep()` użytej w przypadku procesu potomnego,
- _execute.x_: demonstruje właściwości funkcji `execv()` , a dokładnie to, że ta funkcja kończy działanie bieżącego procesu.

***

## 3. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x lub .o należy wydać komendę `make clean`.

Uruchamianie programów w wierszu polecań dla poszczególnych zadań:

*   Zadanie 1: 
    ./drzewko1.x 
    ./drzewko2.x
*   Zadanie 2:
    ./macierzysty.x
*   Zadanie 3:
    ./zombi.x
    ./orphan.x
    ./execute.x

***

## 4. Odpowiedzi na pytania

**Ile teraz powstaje procesów w zadaniu 2. i dlaczego?**

W tym zadaniu powstają 4 procesy - jeden macierzysty i trzy potomne. Dzieje się tak, ponieważ w przypadku procesu potomnego wywoływana jest funkcja `execv()`, która kończy działanie procesu potomnego, uniemożliwiając mu wywołanie funkcji `fork()`.
Natomiast proces macierzysty nadal jest wykonywany i tworzy łącznie 3 procesy potomne



**Ile procesów powstanie przy *n*-krotnym wywołaniu funkcji `fork-exec` jak w zadaniu 2. i dlaczego?**

Powstanie wtedy _n_ procesów. Proces macierzysty utworzy _n_ procesów potomnych, które z kolei wywołują funkcję `execv()`. Tym samym zakończy się działanie tych procesów potomnych.  



**Co robi funkcja `execl()`? Czym się różni od funkcji `execv()`?**

Funkcja `execl()` uruchamia dany program wraz z argumentami, które zostały przekazane do tej funkcji. Może to wyglądać m. in. tak:
`execl("/home/user/program.x", "program.x", arg1, arg2, arg3, NULL)`, 
gdzie pierwszy argument to ścieżkowa nazwa pliku wykonawczego, drugi argument to nazwa programu, następnie są podawane argumenty dla programu o nazwie `program.x`, które muszą być zakończone wartością `NULL`. 
W przypadku funkcji `execv()` takie parametry jak nazwa programu i jego argumenty przechowywane są w tablicy, a w funkcji podajemy adres do tej tablicy, np:
`char* const tab[] = {"potomny.x", arg1, arg2, NULL};`
`execv("potomny.x", tab);` 



**Jaką rolę pełni proces _init_ lub _systemd_?**

Procesy te przejmują procesy osierocone.



**Co to są procesy _zombi_?**

Są to procesy potomne, które po zakończeniu swojego działania nadal istnieją w tablicy procesów, ponieważ oczekują na zwrócenie swojego statusu do procesu macierzystego, który "zwleka" z przyjęciem tego statusu za pomocą funkcji `wait()`.



**Co to są procesy _osierocone_?**

Są to procesy, których proces macierzysty wykonał i zakończył się wcześniej (procesy, "na które nikt nie czeka").

* * *
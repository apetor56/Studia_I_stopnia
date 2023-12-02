<div align="center"><h1>Zestaw 3 - Sygnały</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Obsługa_: obsluga.c, procinfo.c, procinfo.h

_Wysyłaj_: wysylaj.c 

_Grupa_: grupa.c

* * *

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

*   _Obsługa_: ./obsluga.x _<opcja obsługi>_  _<numer sygnału>_,
    gdzie opcja obsługi to "d" (domyślne), "i" (ignorowanie), "p" (własna obsługa)

*   _Wysyłaj_: ./wysyłaj.x <_opcja obsługi_> <_numer sygnału_>,
    tak jak powyżej

*   _Grupa_: ./grupa.x <_opcja obsługi_> <_numer sygnału_>,
    tak jak powyżej

***

## 3. Działanie programów ##

_obsluga.x_:
	Na początku sprawdzam, czy podano prawidłowe argumenty w linii komend (czy ich liczba wynosi 3 oraz czy opcja obsługi zawiera wyłącznie 1 znak). Następnie wyświetlam dane o procesie oraz tworzę zmienną typu `int` (za pomocą `atoi()`), która jest równa liczbie podanej w linii komend. Następnie w instrukcji `switch`, w zależności od `argv[1][0]`, ustawiam konkretną obsługę dla danego sygnału. Na samym końcu wywołuję funkcję `pause()`, która sprawia, że proces czeka na przyjście sygnału.

_wysylaj.x_:
	W tym zadaniu również sprawdzam, czy w prawidłowy sposób podano argumenty w terminalu. Następnie wywołuję raz funkcję `fork()`, a wartość przez nią zwracaną zapisuję w zmiennej `int pid_potomny`.
	 Gdy wartość tej zmiennej jest równa 0 (gdy dany proces jest procesem potomnym) to uruchamiam program `obsluga.x` za pomocą funkcji `execl()`, wraz z argumentami podanymi w linii komend (sposób obsługi oraz numer sygnału). W razie błędu funkcji `execl()` program wypisze komunikat i zakończy działanie. 
	W przypadku `default` w instrukcji `switch` (czyli w głównym procesie) wywołuję funkcję `sleep(1)`, by się upewnić, że sygnał zostanie wysłany do p.potomnego wykonującego program `obsługa.x`, a nie `wysylaj.x`. Następnie za pomocą funkcji `kill(pid_potomny, 0)`sprawdzam, czy istnieje dany proces. Jeśli tak, to wysyłam do niego sygnał, którego numer został podany w linii komend. Mogę tutaj wykorzystać `pid_potomny`, ponieważ p.potomny, który uruchomi inny program za pomocą `execl()`nadal ma ten sam PID. Na samym końcu p.główny czeka na zakończenie p.potomnego za pomocą funkcji `wait()`.

_grupa.x_:
	W tym zadaniu wykonuję dwie osobne instrukcje `switch`: 

- pierwszą dla głównego procesu, który raz wywołuje funkcję `fork()`. Następnie nowo utworzony p.potomny ustawiam na lidera swojej nowej grupy za pomocą funkcji `setpgid()`. Później uodparniam go na przychodzący do niego sygnał, którego numer jest podany w linii komend, za pomocą funkcji `signal(atoi(argv[2]), SIG_IGN)`,

- drugi `switch` jest zarezerwowany dla p.potomnego, który jest liderem swojej grupy. Wywołuję w nim 3 razy funkcję `fork()`. W `case 0`(czy w następnych p.potomnych) uruchamiam program `obsluga.x` za pomocą funkcji `execl()` wraz z odpowiednimi argumentami podanymi w linii komend. Programy te będą "zawieszone", dopóki nie dostaną sygnału od głównego procesu. Gdy zostaną utworzone wszystkie (łączne 3) p.potomne, to "potomny lider" ma wywołać łącznie 3 razy funkcję `wait()`, a później wyświetli otrzymane statusy. 

  

Gdy to jednak nastąpi, należy uśpić główny proces, by wysłał sygnały (numer sygnału podany w linii komend) do p.potomnych wykonujących program `obsluga.x`, a nie `grupa.x`. Następnie sprawdzam, czy docelowa grupa istnieje. Jeśli tak, to wysyłam do nich sygnał. "Lider potomny" będzie ignorował ten sygnał, więc nie zakończy swego działania oraz otrzyma status swoich zakończonych p.potomnych i je na końcu wyświetli.

***

## 3. Opis wybranych sygnałów ##

Przechwytywalne:

- SIGINT: przerwanie (zabicie) bieżącego procesu,
- SIGQUIT :zakończenie bieżącego procesu z zapisaniem obrazu pamięci, 

Nieprzechwytywalne:

- SIGSTOP: zawieszenie bieżącego procesu,
- SIGKILL: bezwarunkowe zakończenie procesu.

***

## 4. Sygnały za pomocą skrótów klawiszowych ##

1. Ctrl + z: zawieszenie bieżącego procesu (SIGSTOP)
2. Ctrl + c: przerwanie (zabicie) bieżącego procesu (SIGINT)
3. Ctrl + \: zakończenie bieżącego procesu z zapisaniem obrazu pamięci (SIGQUIT)

***

## 5. Odpowiedzi na pytania

**Do czego służą sygnały?**

Sygnały służą do komunikacji międzyprocesowej. Umożliwiają asynchroniczne przerwanie procesu przez inny proces, by zareagować na dane zdarzenie.



**Co robi a czego nie robi funkcja `signal()`?**

​	`signal(signum, handler)` służy do obsługi sygnału o numerze `signum`. `handler` może być ustawiony na `SIG_DFL`, wtedy proces przechwytujący ten sygnał wykona operację domyślną. Jeśli `handler == SIG_IGN`, to wtedy proces ignoruje przychodzący do niego sygnał o numerze `signum`. Można również napisać własną funkcję do obsługi danego sygnału.
​	`signal(signum, handler)` natomiast nie tworzy oraz nie wysyła sygnału do procesu.



**Jak działa funkcja `kill()`? Podaj trzy przykłady uwzględniające rolę pierwszego argumentu.**

Funkcja `kill()` służy do wysyłania sygnału do procesu/grupy procesów oraz do sprawdzania, czy dany proces/grupa procesów istnieje. Przykłady z pierwszym argumentem:

- `kill(100, 2)` - do procesu o `PID == 100` wysyłany jest sygnał o numerze 2,
- `kill(-100, 2)` - sygnał o numerze 2 jest wysyłany do grupy procesów, której PGID jest równy 100,
- `kill(0, 2)` - sygnał o numerze 2 jest wysyłany do grupy procesów procesu, który wywołał tę funkcję.



**Jak sprawdzić czy istnieje proces `pid` lub grupa `pgid` i czy możemy do nich wysyłać sygnały?**

- `kill(pid, 0)` - sprawdzenie, czy istnieje proces, którego PID jest równy `pid`,
- `kill(-pgid, 0)` - sprawdzenie, czy istnieje grupa procesów, których PGID jest równy `pgid`.



**Jaki sens ma wywołanie `kill(0, 0)`?**

`kill(0, 0)` sprawdza, czy istnieje grupa procesów wywołującego tę funkcję procesu. Funkcja ta zwróci wartość 0, czy sukces.



**Jak i dlaczego należy uodpornić proces macierzysty w programie `grupa.c` na sygnał?**

W tym procesie należy wykonać funkcję `signal(signum, SIG_IGN)`, gdzie `sig` jest numerem przychodzącego później sygnału. Gdyby ten proces nie byłby uodporniony na przychodzący sygnał, to w większości przypadków po otrzymaniu tego sygnału zakończyłby swoje działanie i nie wypisałby otrzymanych przez funkcję `wait()` statusów.



**Jak wznowić proces zatrzymany sygnałem `SIGSTOP`?**

Można go wznowić za pomocą sygnału `SIGCONT`, np. `kill -18 <ID_zatrzynamego_procesu>`, gdzie `-18` oznacza właśnie ten sygnał.



**Opisać sygnał `SIGCHLD`.**

Sygnał ten wysyłany jest do procesu macierzystego wtedy, gdy zakończy się działanie jego procesu potomnego. W systemie Linux sygnał ten wskazuje też, że zmienił się status procesu potomnego. Domyślnie `SIGCHLD` jest ignorowany.



**Jak działa funkcja `pause()`?**

Funkcja `pause()` zawiesza działanie danego procesów w oczekiwaniu na przyjście sygnału, który nie został zignorowany. W razie sukcesu zwraca -1, w razie porażki nic.

* * *
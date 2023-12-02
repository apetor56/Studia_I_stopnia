<div align="center"><h1>Zestaw 1 - Procesy</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Procinfo_

*   main.c
*   procinfo.c
*   procinfo.h

_Kopiowanie_

*   kopiuj.c
*   deskryptor.c
*   deskryptor.h

_Procesy_

*   procesy.c
*   procinfo.c
*   procinfo.h

_Lider_

*   lider.c
*   procinfo.c
*   procinfo.h

**procinfo.c** - zawiera definicje funkcji `procinfo()`, która służy do wyświetlania poszczególnych ID danego procesu

**deskryptor.c** - zawiera definicje trzech funkcji:

*   `open_original()`: służy do otwarcia pliku o podanej nazwie (wyłącznie do odczytu) oraz zwraca wartość przypisanego mu deskryptora. Funkcja ta wyposażona jest w obsługę błędów,
*   `open_copy()`: służy do utworzenia kopii pliku, który został otwarty w poprzedniej funkcji. Kopii przypisywany jest deskryptor. Funkcja ta wyposażona jest w obsługę błędów,
*   `arg_error()`: sprawdza, czy wprowadzono prawidłową liczbę argumentów. W przypadku błędnego podania argumentów program wyświetla prawidłowy sposób ich wpisania a następnie kończy działanie.

**lider.c** - kopia pliku _kopia.c_ z modyfikacją PGID procesów potomnych

* * *

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

*   Procinfo: ./main.x
*   Kopiowanie: ./kopiuj.x ścieżka_oryginału ścieżka_kopii
*   Procesy: ./procesy.x
*   Lider: ./lider.x

***

## 3\. Odpowiedzi na pytania

**Opisać dokładnie jak działa funkcja `fork()`?**

Funkcja `fork()` tworzy proces potomny danego procesu, który jest niemalże identyczną kopią procesu macierzystego, z tą jednak różnicą, że proces potomny wykonuje polecenia, które wykonywane są po funkcji `fork()`, nie zaś cały blok kodu. Proces po wywołaniu funkcji `fork()` otrzymuje wartość PID procesu potomnego, a procesowi potomnemu zwracane jest 0. W razie jakiegoś błędu funkcja `fork()` zwraca wartość -1 do procesu macierzystego.



**Ile powstaje procesów w zadaniu _procesy_ i dlaczego?**

W tym zadaniu powstaje 8 procesów. Na początku mamy proces macierzysty, który tworzy 3 procesy potomne: P0, P1, P2 (cyfra oznacza, w której iteracji powstał proces potomny). Proces P0 używa funkcji `fork()` już przy iteracji i==1, więc utworzy 2 procesy potomne: P0_1, P0_2. Proces P0_1 używa funkcji `fork()` już w iteracji i==2, więc utworzy jeden proces potomny. Proces P0_2 zakończy swoje działanie (użyłby`fork()`przy i==3, lecz w pętli ustalony jest warunek i < 3). Więc w tej gałęzi otrzymaliśmy 4 procesy potomne. Analogicznie robimy dla pozostałych procesów potomnych naszego głównego procesu macierzystego. W ten sposób otrzymujemy w kolejnych gałęziach 2 + 1 procesów potomnych. Czyli łącznie mamy 1 proces główny + 7 procesów potomnych.



**Ile procesów powstanie przy _n-krotnym_ wywołaniu funkcji `fork()` i dlaczego?**

Powstanie wtedy 2<sup>n</sup> procesów. Jest to związane z dwumianem Newtona. Najstarszy proces ("pokolenie zerowe") jest jeden, co da się zapisać jako "n po 0". Procesów z pierwszego pokolenia jest n, czyli "n po 1". Analogicznie robimy dla pozostałych pokoleń. Wiadomo zaś, że suma tych wszystkich dwumianów Newtona wynosi 2<sup>n</sup>.



**Jak używając funkcji `sleep()` i bez odwoływania się do funkcji `wait()` zapewnić aby procesy macierzyste kończyły się dopiero po procesach potomnych?**

Należy na tak długi czas uśpić wszystkie procesy macierzyste, by ich procesy potomne wykonały się wcześniej. Funkcji `sleep()` najlepiej użyć w ostatniej iteracji pętli procesu macierzystego. W zadaniu <em>procesy</em> można procesy macierzyste uśpić na 7 sekund oraz procesy potomne na 2 sekundy, a otrzymamy otrzymamy identyczny rezultat w wyświetlaniu pokoleń jak przy użyciu funkcji `wait()`.



**Jaką wartość zwraca `open()`?**

`Open()` zwraca liczbę całkowitą, która jest nazywana deskryptorem danego pliku. Jeśli ta liczba jest równa -1 to oznacza, że wystąpił błąd przy otwieraniu pliku.



**Jaką wartość zwraca `read()`i `write()`?**

`Read()`/`write()`zwraca liczbę wczytanych/zapisanych bajtów z bufora. Jeśli ta liczba jest równa -1 to oznacza, że wystąpił błąd przy wczytywaniu/zapisywaniu.

* * *
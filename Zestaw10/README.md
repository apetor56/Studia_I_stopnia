<div align="center"><h1>Zestaw 10 - Wątki</h1></div>

<div align="center"><h3>Łukasz Tenerowicz</h3></div>

* * *

## 1\. Pliki do poszczególnych zadań:

_Zadanie 1: piekarnia: `piekarnia.c`
_Zadanie 2: piekarnia v2: `piekarnia2.c`

***

## 2\. Kompilacja i uruchamianie programów

Sposób kompilacji programów jest zapisany w pliku _Makefile_. Aby skompilować wszystkie pliki należy w wierszu poleceń wydać komendę `make`. Aby usunąć wszystkie pliki z rozszerzeniem .x, .a, .so lub .o należy wydać komendę `make clean`.

Uruchamianie programów dla poszczególnych zadań:

- _piekarnia_: `./piekarnia.x`
- _piekarnia v2_: `./piekarnia2.x`

***

## 3. Działanie programów ##

​	Obydwa programy działają na podobnej zasadzie - wykorzystują algorytm piekarni w celu synchronizacji wątków. Pierwszy program ma działanie podobne jak zadanie z poprzedniego zestawu, tzn. wyświetlanie danych wątków w odpowiednich wierszach i kolorze wraz z określonymi komunikatami, natomiast drugi program wypisuję wartość końcową zmiennej globalnej dla danego wątku (gdy zakończy on swoje działanie).

***

## 4. Odpowiedzi na pytania.

**Dlaczego dwa procesy nie mają jednocześnie dostępu do sekcji krytycznej?
Przedstawić dowód poprawności algorytmu.
Wprowadzić drobną zmianę, która zepsuje tą właściwość i podać przykład.**

Na samym początku wszystkim wątkom przydzielana jest pewna liczba naturalna - gdy nie jest ona przydzielona lub jest w trakcie przydzielania do wątku, to reszta ma zaczekać na taki wątek. W programie użyłem w tym celu własnego typu `state` który przyjmuje 3 wartości:

- `BEFORE`(0), która mówi, że liczba nie zaczęła być przydzielana do danego wątku,
- `PENDING`(-1), która oznacza, że wątek jest w trakcie przydzielania do liczby,
- `AFTER`(1) oznacza, że liczba została przydzielona do wątku.

Wprowadziłem tutaj 3 różne stany (a nie `false` i `true`, jak jest w originalnym algorytmie), ponieważ gdybym ustawiał `false` przed przypisaniem liczby i po przypisaniu, to mogła by nastąpić sytuacja, że któryś wątek mógłby nie poczekać na inny wątek, który nie wybrał jeszcze swojej liczby, a miałby status `false`, czyli identyczny jak po wybraniu liczby. Te trzy powyższe stany gwarantują, że wszystkie wątki poczekają na siebie przy wybieraniu liczby.

Następnie wprowadzany jest warunek na to, który wątek ma wejść do sekcji krytycznej. Gdy wykona swoją pracę, to ustawia przydzieloną mu liczbę na `0`, odblokowując tym samym inny wątek, który będzie mógł teraz wejść do sekcji krytycznej.

Aby to popsuć, tzn. wprowadzić kilka wątków do sekcji krytycznej, to jeden z wątków można pominąć w powyżej przedstawionych warunkach, dzięki czemu w pewnym momencie będziemy mieli 2 wątki w sekcji krytycznej. 



**Dlaczego algorytm nie prowadzi do *zakleszczenia*?
Wprowadzić drobną zmianę, która zepsuje tą właściwość i podać przykład..**

W algorytmie nie pojawia się sytuacja, gdzie wątek nr 1 musi czekać na zakończenie pracy wątku nr 2 przy jednoczesnym czekaniu wątku nr 2 na zakończenie pracy wątku nr 1. Gwarantują to dobrze napisane warunki, tj. czekanie wszystkich wątków na przydzielenie liczby do danego wątku oraz warunek na wejście do sekcji krytycznej. Można popsuć tę funkcjonalność np. przypisując jednemu wątkowi określoną liczbę, a nie zmieniać mu statusu na `AFTER`, tylko pozostawić na `BEFORE`. Zróbmy taki manewr na wątku nr 3. Reszta wątków będzie oczywiście bez końca czekać na zmienienie statusu wątku nr 3 na `AFTER`, a wątek nr 3 też będzie czekał na skończenie wcześniejszych wątków, którym przydzielono mniejszą liczbę (zgodnie z algorytmem, te wątki, które mają przydzieloną mniejszą liczbę, mają wykonać się wcześniej od innych). W ten sposób wszystkie pozostałe wątki czekają na wątek nr 3, a wątek nr 3 czeka, aż wcześniejsze wątki zakończą swą pracę, czyli dochodzi do zakleszczenia.



**Dlaczego algorytm nie prowadzi do *zagłodzenia*?
Wprowadzić drobną zmianę, która zepsuje tą właściwość i podać przykład.**

W algorytmie nie ma sytuacji, gdzie do sekcji krytycznej może wejść więcej niż jeden wątek - zawsze taką możliwość ma tylko i wyłącznie jeden wątek. Gwarantują to warunki algorytmu wejścia do sekcji krytycznej. Aby doprowadzić do zagłodnienia wątku, należy wprowadzić taką funkcjonalność, by np. dwa wątki na raz miały dostęp do sekcji krytycznej, natomiast jeden z nich czekałby w nieskończoność, ustępując innym wątkom.

* * *
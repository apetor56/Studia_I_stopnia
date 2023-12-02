<div align="center" > <h1> Zestaw 1 - Stos </h1> </div>

<div align="center"> Łukasz Tenerowicz </div>

## 1. Programy

- __Stack.x__: Korzysta z jednej z możliwych implementacji stosu (z _ArrayStack.hpp_ lub _LinkedStack.hpp_) a jako dane wejściowe przyjmuje dane ze standardowego wyjścia programu _Generator.x_. _ArrayStack.hpp_ zawiera tablicową reprezentację stosu (wykorzystywane są szablony klas i funkcji), a _LinkedStack_ zawiera wskaźnikową reprezentację stosu (wyłącznie dla danych typu <code> int </code>). 
- __Generator.x__: Generuje dane dla programu _Stack.x_. W linii komend należy podać liczbę operacji, jakie mają być wykonane na stosie.
- __ONP.x__: Zamienia klasyczne wyrażenia arytmetyczne na zapis odwrotnej notacji polskiej. Dane pobierane są za pomocą standardowego wejścia (<code> std::cin </code>)

---

## 2. Sposób wywołanie programów

- __Zadanie 3 - Stos__

  ```shell
  ./Generator.x liczba_operacji | ./Stack.x
  ```

- __Zadanie 5 - ONP__

  ```
  ./ONP.x
  ```

---

## 3. Odpowiedzi na pytania

__Omów przykłady zastosowania stosu.__

- Procesory: chwilowe zapamiętywanie stanów procesora,
- Przechowywanie zmiennych lokalnych,
- ONP.


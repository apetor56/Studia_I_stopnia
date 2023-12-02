<div align = "center"> <h1>
    Zestaw 2 - Kolejki
    </h1> </div> 

<div align = center> <h3>
    Łukasz Tenerowicz
    </h3> </div>

---

## 1. Programy

- **Queue.x**: Składa się z plików _Queue.cpp_ oraz _ArrayQueue.hpp_ / _LinkedQueue.hpp_. _Queue.cpp_ wykonuje operacje wygenerowane przez program _Generator.x_, a _ArrayQueue.hpp_ oraz _LinkedQueue.hpp_ implementują odpowiednio reprezentację tablicową i wskaźnikową kolejki. Pierwsza z nich wykorzystuje bufor cykliczny a druga operuje na węzłach zmodyfikowanej listy jednokierunkowej. Zarówno jedna jak i druga implementacja wykorzystuje szablony klas.

- **Generator.x**: Generuje dane dla programu _Queue.x_. Dane mogą mieć postać:

  ` A x - dodaj element x do kolejki,` 
  `D - usuń i zwróc element z kolejki,`

  `S - wyświetl liczbę elementów w kolejce.` 

  Sposób wywołania:
  `./Generator.x liczba_operacji`

- **Radix.x**: Program wykonuje sortowanie pozycyjne za pomocą kolejki.

---

## 2. Odpowiedzi na pytania

- **Opisz trzy sposoby obsługi cykliczności bufora.**

  1) Sprawdzanie za każdym razem, czy zwiększenie `head` lub `tail` wykracza poza zakres bufora. Jeśli tak, to należy zmienić wartość `head` lub `tail` na 0.

  ```c++
  if(tail + 1 == buffer_size)
      tail = 0;
  else tail++;
  ```

  

  2) Sposób z operacją module:

  ```c++
  tail = (tail + 1) % buffer_size
  ```

  

  3) Gdy rozmiar bufora jest potęgą liczby 2, to można zastosować koniunkcję bitową:

  ```c++
  tail = (tail + 1) & (buffer_size - 1)
  ```

  

- **Omów przykłady zastosowania kolejki.**
  - Priorytetowa kolejka komunikatów



- **Co oznaczają akronimy LIFO i FIFO**
  - LIFO - _last in first out_
  - FIFO - _first in first out_
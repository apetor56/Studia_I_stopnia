<div align = "center"> <h1>
    Zestaw 6 - Drzewo binarne
    </h1> </div> 


<div align = center> <h3>
    Łukasz Tenerowicz
    </h3> </div>


---

## 1. Odpowiedzi na pytania

- **Jakie operacje są relatywnie szybko wykonywane na drzewie BST, porównaj złożoności czasowe z innymi strukturami danych.**

  W drzewie BST szybką operacją jest wyszukiwanie danego elementu - ma ona złożoność O(log_2(n)). W innych strukturach, np. w liście tablicowej, wskaźnikowej czy w stosach i kolejkach taka operacja ma złożoność O(n). Podobna sytuacja ma miejsce przy operacji wstawiania elementu - w drzewie binarnym dodawanie każdego elementu to złożoność O(log_2(n)), natomiast w listach taka operacja może mieć złożoność O(n).

  ---

- **Na czym polega iteracyjne przechodzenie drzewa bez użycia rekurencji?**

  Polega na odpowiednim wykorzystaniu stosu - za każdym razem gdy idziemy na lewo wstawiamy węzeł na stos, a gdy nie ma prawego dziecka zdejmujemy.

  ---

- **W jaki sposób można użyć drzewo BST do sortowania elementów?   Wskaż podobieństwo do wcześniej poznanego algorytmu sortowania. Omów wady takiego rozwiązania.**

  Przechodzenie drzewa sposobem _in order_ pozwala na wypisanie wszystkich elementów drzewa od najmniejszego do największego. Metoda ta ma złożoność O(log_2(n)). Wadą takiego rozwiązania jest to, że tak na prawdę nie sortujemy drzewa, tylko wypisujemy jego elementy, więc potrzebna nam jest jest dodatkowa pamięć, by zapisać wypisane w kolejności elementy drzewa.

  ---

- **Na czym polega przechodzenie drzewa preorder?**

  Najpierw wyświetlamy wartość danego węzła. Potem odwiedzamy lewe poddrzewo danego węzła aż do momentu napotkania liścia a potem przechodzimy do prawego poddrzewa węzła.

  ---

- **Na czym polega przechodzenie drzewa inorder?  Jaka będzie kolejność wypisywanych elementów?**

  Najpierw przechodzimy do lewego poddrzewa danego węzła -> następnie wyświetlamy wartość węzła -> na koniec przechodzimy prawe poddrzewo. Taka kolejność wyświetla elementy drzewa od najmniejszego do największego.

  ---

  

  

  

  
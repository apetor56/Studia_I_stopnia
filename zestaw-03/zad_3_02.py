# Co jest złego w kodzie: 

# Do listy L przypisane jest wartość zwracana
# przez funckję list.sort(), czyli 'None'
L = [3, 5, 4] ; L = L.sort()

# Poniższy fragment: próba przypisania trzech wartości
# do dwóch zmiennych
x, y = 1, 2, 3


# Błąd: poniższa struktura danych jest immutable,
# czyli nie można zmieniać w niej wartości
X = 1, 2, 3 ; X[1] = 4

# Błąd: index '3' odnosi się do czwartego elementu
# w liście, a lista ma tylko 3 elementy (out of range)
X = [1, 2, 3] ; X[3] = 4

# String nie ma metody 'append'
X = "abc" ; X.append("d")

# Funkcja 'pow' wymaga podania przynajmniej dwóch
# argumentów, a nie jednego
L = list(map(pow, range(8)))
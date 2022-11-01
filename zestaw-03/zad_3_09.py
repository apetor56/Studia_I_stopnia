# Mamy daną listę sekwencji (listy lub krotki) różnej długości zawierających liczby. Znaleźć listę zawierającą sumy liczb z tych sekwencji.
# Przykładowa sekwencja [[],[4],(1,2),[3,4],(5,6,7)], spodziewany wynik [0,4,3,7,18].

A = [[1, 3], (0, 7, 3), [100, -100, 12], (), (83, 17, 1, 1), [4, 2], [1]]
result = list(sum(i) for i in A)
print(result)
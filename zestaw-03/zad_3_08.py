# Dla dwóch sekwencji liczb lub znaków znaleźć:
a = [1, 2, 3, 3, 3, 4, 4, 5]
b = [3, 3, 4, 5, 5, 5, 6, 7]

# (a) listę elementów występujących jednocześnie w obu sekwencjach (bez powtórzeń),
print(list(set(a) | set(b)))

# (b) listę wszystkich elementów z obu sekwencji (bez powtórzeń).
print(list(set(a) & set(b)))




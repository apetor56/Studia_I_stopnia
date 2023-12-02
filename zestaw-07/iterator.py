# Stworzyć następujące iteratory nieskończone:
# (a) zwracający 0, 1, 0, 1, 0, 1, ...,
# (b) zwracający przypadkowo jedną wartość z ("N", "E", "S", "W") [błądzenie przypadkowe na sieci kwadratowej 2D],
# (c) zwracający 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, ... [numery dni tygodnia]. 

import itertools
import random

# (a)
it = itertools.cycle([0, 1])

for i in range(0, 10):
    print(next(it), end=' ')
print('\n')

# (b)
word = "NESW"
it = (word[random.choice(range(len(word)))] for _ in iter(int, 1))
for i in range(0, 30):
    print(next(it), end=' ')
print('\n')

# (c)
it = itertools.cycle([0, 1, 2, 3, 4, 5, 6])

for i in range(0, 15):
    print(next(it), end=' ')
print('\n')
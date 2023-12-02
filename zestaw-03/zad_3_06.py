# Napisać program rysujący prostokąt zbudowany z małych kratek. Należy zbudować pełny string, a potem go wypisać.
#  Przykładowy prostokąt składający się 2x4 pól ma postać:
# +---+---+---+---+
# |   |   |   |   |
# +---+---+---+---+
# |   |   |   |   | 
# +---+---+---+---+

def plus_minus(x):
    for i in range(0, x):
        print('+---', end='')
    print('+')

def rest(x):
    for i in range(0, x):
        print('|   ', end='')
    print('|')


x, y = int(input('Podaj szerokość kratki: ')), int(input('Podaj wysokość kratki: '))

for i in range(0, y):
    plus_minus(x)
    rest(x)
plus_minus(x)
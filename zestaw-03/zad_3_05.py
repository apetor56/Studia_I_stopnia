# Napisać program rysujący "miarkę" o zadanej długości. Należy prawidłowo obsłużyć liczby składające się z kilku cyfr
# (ostatnia cyfra liczby ma znajdować się pod znakiem kreski pionowej). Należy zbudować pełny string, a potem go wypisać.

size = int(input('Podaj rozmiar miarki: '))
miarka = '|'
num = '0'

for i in range(1, size + 1):
    miarka += '....|'
    num += str(i).rjust(5)

print(miarka)
print(num)
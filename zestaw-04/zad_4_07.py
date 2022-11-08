# Mamy daną sekwencję, w której niektóre z elementów mogą okazać się podsekwencjami,
# a takie zagnieżdżenia mogą się nakładać do nieograniczonej głębokości.
# Napisać funkcję flatten(sequence), która zwróci spłaszczoną listę wszystkich elementów sekwencji.
# Wskazówka: rozważyć wersję rekurencyjną, a sprawdzanie czy element jest sekwencją, wykonać przez isinstance(item, (list, tuple)).

def flatten(sequence):
    L = []
    for i in sequence:
        if isinstance(i, (list, tuple)):
            L += flatten(i)
        else:
            L.append(i)

    return L

seq = [1,(2,3),[],[4,(5,6,7)],8,[9]]
print(flatten(seq))
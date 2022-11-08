# Napisać funkcję sum_seq(sequence) obliczającą sumę liczb zawartych w sekwencji, która może zawierać zagnieżdżone podsekwencje.
# Wskazówka: rozważyć wersję rekurencyjną, a sprawdzanie, czy element jest sekwencją, wykonać przez isinstance(item, (list, tuple)). 

def sum_seq(sequence):
    s = 0
    for i in sequence:
        if isinstance(i, (list, tuple)):
            s += sum_seq(i)
        else:
            s += i

    return s


seq = [1,(2,3),[],[4,(5,6,7)],8,[9]]
print(sum_seq(seq))
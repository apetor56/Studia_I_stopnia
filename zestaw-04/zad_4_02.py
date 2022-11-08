# Rozwiązania zadań 3.5 i 3.6 z poprzedniego zestawu zapisać w postaci funkcji, które zwracają pełny string przez return.
# Funkcje nie powinny pytać użytkownika o dane, tylko korzystać z argumentów.

def make_ruler(n):
    miarka = '|'
    num = '0'

    for i in range(1, n + 1):
        miarka += '....|'
        num += str(i).rjust(5)

    return miarka + '\n' + num

def make_grid(rows, cols):
    s = ''

    for j in range(rows):
        for i in range(0, cols):
            s += '+----'
        s += '+\n'

        for i in range(0, cols):
            s += '|    '
        s += '|\n'

    for i in range(0, cols):
            s += '+----'
    s += '+' + '\n'   

    return s;


print(make_ruler(5))
print(make_grid(4, 2))
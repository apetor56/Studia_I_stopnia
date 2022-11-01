# Stworzyć słownik tłumaczący liczby zapisane w systemie rzymskim (z literami I, V, X, L, C, D, M) na liczby arabskie (podać kilka sposobów tworzenia takiego słownika).
# Mile widziany kod tłumaczący całą liczbę [funkcja roman2int()].

# Sposób I
D = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

# # Sposób II
L = [('I', 1), ('V', 5), ('X', 10), ('L', 50), ('C', 100), ('D', 500), ('M', 1000)]
D = dict(L)

# Sposób III
D = dict()
for pair in L:
    D[pair[0]] = pair[1]

# konwersja liczb rzymskich na arabskie
def roman2int(roman):
    arabic = 0
    f = False
    for i in range(0, len(roman)):
        if f == True:
            f = False
            continue

        if i != len(roman) - 1 and D[roman[i]] < D[roman[i + 1]]:
            arabic += (D[roman[i + 1]] - D[roman[i]])
            f = True
        else:
            arabic += D[roman[i]]

    return arabic

print(roman2int('LXI'))
print(roman2int('MMMXLVII'))
print(roman2int('CMXXXI'))
print(roman2int('MCMLXXXIV'))
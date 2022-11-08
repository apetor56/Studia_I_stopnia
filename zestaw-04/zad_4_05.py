# Napisać funkcję odwracanie(L, left, right) odwracającą kolejność elementów na liście od numeru left do right włącznie. Lista jest modyfikowana w miejscu (in place).
# Rozważyć wersję iteracyjną i rekurencyjną. 

def odwracanie_iter(L, left, rigth):
    k = 0
    for i in range(left, rigth):
        if rigth - k <= left + k:
            break

        else:
            L[left + k], L[rigth - k] = L[rigth - k], L[left + k]
            k += 1
    
    return L

def odwracanie_rek(L, left, rigth):
    if left < rigth:
        L[left], L[rigth] = L[rigth], L[left]
        odwracanie_rek(L, left + 1, rigth - 1)

    return L


L = [1, 2, 3, 4, 5, 6, 7, 8]
print(odwracanie_iter(L, 2, 5))

L = [1, 2, 3, 4, 5, 6, 7, 8]
print(odwracanie_rek(L, 2, 5))

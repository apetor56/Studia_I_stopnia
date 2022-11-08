from unittest import result


# Napisać iteracyjną wersję funkcji fibonacci(n) obliczającej n-ty wyraz ciągu Fibonacciego. 

def fibonacci(n):
    f1 = 0
    f2 = 1

    for i in range(n):
        last_f1 = f1
        f1 = f2
        f2 = f2 + last_f1

    return f2


print(fibonacci(5))
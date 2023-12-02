# Napisać program pobierający w pętli od użytkownika liczbę rzeczywistą x (typ float)
# i wypisujący x oraz trzecią potęgę x. Zatrzymanie programu następuje po wpisaniu z klawiatury stop.
# Jeżeli użytkownik wpisze napis zamiast liczby, to program ma wypisać komunikat o błędzie i kontynuować pracę.

while True:
    try:   
        x = input('Wprowadź liczbę: ')
        if x == 'stop':
            break
        x = float(x)
    except ValueError:
        print('Wprowadzono nieodpowiednie dane.')
        continue

    print(f'{x} ---> {pow(x, 3)}')
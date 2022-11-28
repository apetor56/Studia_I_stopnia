# Czy podany kod jest poprawny składniowo w Pythonie? Jeśli nie, to dlaczego?

# Ten fragment jest poprawny: zastosowano odpowiednie wcięcie (tabulację)
x = 2; y = 3; 
if (x > y):
    result = x;
else:
    result = y;

# Ten fragment nie jest poprawny: nie zastosowano nowej linii i znaku tabulacji
# for i in "axby": if ord(i) < 100: print (i)

# To już jest poprawne
for i in "axby":
    if ord(i) < 100: print (i)

# Ten fragment jest poprawny
for i in "axby": print (ord(i) if ord(i) < 100 else i)

line = '''jakies losowe slowa
do rozwiazania tego zadania'''

first_letter = []
last_letter = []

for word in list(line.split()):
    first_letter.append(word[0])
    last_letter.append(word[-1])

print(first_letter,'\n', last_letter)
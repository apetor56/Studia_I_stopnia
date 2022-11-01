from posixpath import split


line = '''jakies losowe slowa
do rozwiazania tego zadania'''

count = 0
for word in line.split():
    count += len(word)

print(count)
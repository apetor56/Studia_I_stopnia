line = '''jakies losowe slowa
do rozwiazania tego zadania'''

print(sorted(line.split()))
print(sorted(line.split(), key=len))
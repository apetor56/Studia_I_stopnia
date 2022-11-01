line = '''jakies losowe slowa
do rozwiazania tego zadania'''

longest = max(line.split(), key=len)
print(longest, '\n', len(longest))
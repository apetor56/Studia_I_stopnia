list = [123, 32, 2, 75, 241, 31, 77, 4, 1, 18]

numbers = []
for num in list:
    numbers.append(str(num).zfill(3))

print(numbers)
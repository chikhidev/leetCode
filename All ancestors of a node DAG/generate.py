import random
array_length = 1000

array = []
for _ in range(array_length):
    num1 = random.randint(0, 999)
    num2 = random.randint(0, 999)
    if num1 != num2:
        if [num1, num2] not in array: array.append([num1, num2])
    else:
        if [num1, num2 + 1] not in array: array.append([num1, num2 + 1])

print(array)

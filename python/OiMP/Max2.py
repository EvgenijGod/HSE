a = int(input())
b = int(input())
maxNumber = int((a + b + ((a - b) ** 2) ** 0.5) / 2)
print(maxNumber)

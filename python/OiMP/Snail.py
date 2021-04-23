h = int(input())  # distance
a = int(input())  # meters up per day
b = int(input())  # meters down per day
print((h - b - 1) // (a - b) + 1)

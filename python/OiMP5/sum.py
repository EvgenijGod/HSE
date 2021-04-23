a = int(input())
b = int(input())


def sum(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    if a == 1:
        return b + 1
    else:
        return sum(a - 1, b) + 1


print(sum(a, b))

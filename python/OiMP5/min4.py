a = int(input())
b = int(input())
c = int(input())
d = int(input())


def min4(a, b, c, d):
    return min(min(a, b), min(c, d))


print(min4(a, b, c, d))

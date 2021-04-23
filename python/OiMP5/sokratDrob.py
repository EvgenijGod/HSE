a = int(input())
b = int(input())


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def ReduceFraction(n, m):
    return n // gcd(n, m), m // gcd(n, m)


res = ReduceFraction(a, b)
print(res[0], res[1], sep=' ')

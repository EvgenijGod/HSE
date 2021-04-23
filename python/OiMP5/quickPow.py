a = float(input())
n = int(input())


def quickPow(a, n):
    if n == 0:
        return 1
    if n == -1:
        return 1 / a
    if n % 2 == 0:
        return quickPow(a ** 2, n // 2)
    else:
        return a * quickPow(a ** 2, n // 2)


res = quickPow(a, n)
if res == int(res):
    print(int(res))
else:
    print(res)

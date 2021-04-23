n = int(input())
k = int(input())


def combination(n, k):
    if k == 0 or n == 0 or n == k:
        return 1
    if k == 1:
        return n
    return combination(n - 1, k - 1) + combination(n - 1, k)


print(combination(n, k))

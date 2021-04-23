number = int(input())


def MinDivisor(n):
    cnt = 2
    while cnt <= n ** 0.5:
        if n % cnt == 0:
            return cnt
        else:
            cnt += 1
    return n


print(MinDivisor(number))

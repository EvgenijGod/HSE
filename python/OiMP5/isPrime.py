number = int(input())


def MinDivisor(n):
    cnt = 2
    while cnt <= n ** 0.5:
        if n % cnt == 0:
            return cnt
        else:
            cnt += 1
    return n


def IsPrime(n):
    if MinDivisor(n) == n:
        return True
    else:
        return False

if IsPrime(number):
    print('YES')
else:
    print('NO')

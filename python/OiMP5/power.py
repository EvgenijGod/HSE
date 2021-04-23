a = float(input())
n = int(input())


def power(a, n):
    now = a
    if n == 0:
        return 1
    cnt = 1
    while cnt < abs(n):
        now *= a
        cnt += 1
    if n > 0:
        return now
    else:
        return 1 / now


res = power(a, n)
if res == int(res):
    print(int(res))
else:
    print(res)

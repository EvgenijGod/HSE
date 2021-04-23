a = float(input())
n = int(input())


def power(a, n):
    if n == 0:
        return 1
    now = a
    cnt = 1
    while cnt < n:
        now *= a
        cnt += 1
    return now

res = power(a, n)
if res == int(res):
    print(int(res))
else:
    print(res)

def sumNear(n):
    cntSum = 0
    for i in range(1, n):
        cntSum += i * (i + 1)
        if i != 1:
            print('+', end='')
        print(i, i + 1, sep='*', end='')
        if i == n - 1:
            print('=', end='')
    print(cntSum)


def main():
    n = int(input())
    sumNear(n)


main()

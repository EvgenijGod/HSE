import sys


def readArray(file):
    n = int(file.readline())
    arr = []
    for i in range(n):
        arr.append(int(file.readline()))
    return arr


def isFib(n):
    f0 = 1
    f1 = 1
    f = 1
    while f < n:
        f = f0 + f1
        f0 = f1
        f1 = f
    return n == f


def main():
    arr = readArray(sys.stdin)
    for num in arr:
        if isFib(num):
            print('Yes')
        else:
            print('No')


main()

import sys


def readMatrix(file, n, m):
    mtrx = []
    for i in range(n + 1):
        mtrx.append([0] * (m + 1))
    for i in range(1, n + 1):
        mtrx[i] = [0] + list(map(int, file.readline().split()))
    return mtrx


def chess(avlbl, n, m):
    table = []
    for i in range(n + 1):
        table.append([0] * (m + 1))
    for j in range(1, m + 1):
        if avlbl[1][j] == 0:
            table[1][j] = 0
        else:
            table[1][j] = 1
    for i in range(1, n + 1):
        if avlbl[i][1] == 0:
            table[i][1] = 0
        else:
            table[i][1] = 1
    for i in range(2, n + 1):
        for j in range(2, m + 1):
            if avlbl[i][j] == 0:
                table[i][j] = 0
            else:
                table[i][j] = table[i][j - 1] + table[i - 1][j]
    if table[n][m] == 0:
        print('Impossible')
    else:
        print(table[n][m])


def main():
    n, m = map(int, sys.stdin.readline().split())
    avlbl = readMatrix(sys.stdin, n, m)
    chess(avlbl, n, m)


main()

import sys


def readMatrix(file, n, m):
    mtrx = []
    for i in range(n):
        mtrx.append(list(map(int, file.readline().split())))
    return mtrx


def getAway(mtrx, n, m):
    for j in range(1, m):
        if mtrx[0][j] != 0:
            mtrx[0][j] = mtrx[0][j - 1]
    for i in range(1, n):
        if mtrx[i][0] != 0:
            mtrx[i][0] = mtrx[i - 1][0]
    for i in range(1, n):
        for j in range(1, m):
            if mtrx[i][j] != 0:
                mtrx[i][j] = mtrx[i - 1][j] + mtrx[i][j - 1]
    if mtrx[n - 1][m - 1] == 0:
        print('Impossible')
    else:
        print(mtrx[n - 1][m - 1])


def main():
    n, m = map(int, sys.stdin.readline().split())
    mtrx = readMatrix(sys.stdin, n, m)
    getAway(mtrx, n, m)


main()

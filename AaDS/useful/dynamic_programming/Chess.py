import sys


def chess(n, m):
    table = []
    for i in range(n + 1):
        table.append([0] * (m + 1))
    table[1][1] = 1
    for i in range(2, n + 1):
        for j in range(2, m + 1):
            table[i][j] = table[i - 1][j - 2] + table[i - 2][j - 1]
    print(table[n][m])


def main():
    n, m = map(int, sys.stdin.readline().split())
    chess(n, m)


main()

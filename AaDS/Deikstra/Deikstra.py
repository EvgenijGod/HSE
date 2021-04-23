import sys


def readMatrix(file, n):
    matrix = []
    for i in range(n):
        line = list(map(int, file.readline().split()))
        matrix.append(line)
    return matrix


def findMin(dscvrd, dstnce, n):
    findmin = -1
    min = 10000
    for i in range(n):
        if not dscvrd[i] and dstnce[i] < min:
            min = dstnce[i]
            findmin = i
    return findmin


def dijkstra(matrix, s, f, n):
    dscvrd = [False] * n
    dstnce = [100000] * n
    dstnce[s] = 0
    while findMin(dscvrd, dstnce, n) != -1:
        u = findMin(dscvrd, dstnce, n)
        for i in range(n):
            if matrix[u][i] != -1:
                dstnce[i] = min(dstnce[i], dstnce[u] + matrix[u][i])
        dscvrd[u] = True
    if dstnce[f] == 100000:
        return -1
    else:
        return dstnce[f]


def main():
    n, s, f = map(int, sys.stdin.readline().split())
    matrix = readMatrix(sys.stdin, n)
    print(dijkstra(matrix, s - 1, f - 1, n))


main()

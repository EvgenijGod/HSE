import sys


def readMatrix(file, n):
    matrix = []
    for i in range(n):
        line = list(map(int, file.readline().split()))
        matrix.append(line)
    return matrix


def findmin(dstnc, dscvrd, n):
    min_index = -1
    min = 1000000
    for i in range(n):
        if dstnc[i] < min and not dscvrd[i]:
            min = dstnc[i]
            min_index = i
    return min_index


def dijkstra(matrix, n, s, f):
    dscvrd = [False] * n
    dstnc = [1000000] * n
    dstnc[s] = 0
    while findmin(dstnc, dscvrd, n) > -1:
        u = findmin(dstnc, dscvrd, n)
        for i in range(n):
            if matrix[u][i] != -1:
                dstnc[i] = min(dstnc[i], dstnc[u] + matrix[u][i])
        dscvrd[u] = True
    if dstnc[f] == 1000000:
        return -1
    else:
        return dstnc[f]


def main():
    n, s, f = map(int, sys.stdin.readline().split())
    matrix = readMatrix(sys.stdin, n)
    print(dijkstra(matrix, n, s - 1, f - 1))


main()

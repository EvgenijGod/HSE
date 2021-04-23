import sys

sys.setrecursionlimit(10000000)


def readList(file):
    n, m = map(int, file.readline().split())
    listEdge = []
    for i in range(m):
        listEdge.append(list(map(int, file.readline().split())))
    return n, listEdge


def matrixN(listEdge, n):
    m = []
    for i in range(n):
        m.append([])
        for j in range(n):
            m[i].append(False)
    for el in listEdge:
        a = el[0] - 1
        b = el[1] - 1
        m[a][b] = True
        m[b][a] = True
    return m


def dfs(res, m, d, n, s):
    d[s] = True
    for i in range(n):
        if m[i][s] and not d[i]:
            dfs(res, m, d, n, i)
    res.append(s + 1)


def main():
    n, l = readList(sys.stdin)
    m = matrixN(l, n)
    discovered = [False] * n
    res = []
    dfs(res, m, discovered, n, 0)
    print(len(res))
    print(*sorted(res))


main()

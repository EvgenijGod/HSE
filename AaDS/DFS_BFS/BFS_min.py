import sys


def readM(file):
    n = int(file.readline())
    res = []
    for i in range(n):
        line = list(map(int, file.readline().split()))
        res.append(line)
    return n, res


def findVertex(n, m, s, d, k):
    for i in range(n):
        if m[i][s] == 1 and d[i] == k:
            return i


def minWay(n, m, s, e):
    d = [101] * n
    dscvrd = [False] * n
    d[s] = 0
    dscvrd[s] = True
    queue = [s]
    while queue:
        u = queue[0]
        queue = queue[1:]
        for i in range(n):
            if m[i][u] == 1 and not dscvrd[i]:
                dscvrd[i] = True
                queue.append(i)
                d[i] = d[u] + 1
    if d[e] > 100:
        print(-1)
    elif d[e] == 0:
        print(d[e])
    else:
        print(d[e])
        k = d[e] - 1
        way = []
        way.append(e + 1)
        ss = e
        while k >= 0:
            u = findVertex(n, m, ss, d, k)
            ss = u
            way.append(u + 1)
            k -= 1
        print(*reversed(way))


def main():
    n, m = readM(sys.stdin)
    start, end = map(int, sys.stdin.readline().split())
    minWay(n, m, start - 1, end - 1)


main()

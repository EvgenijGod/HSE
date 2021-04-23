import sys

sys.setrecursionlimit(1000000000)


def readList(file):
    n, m = map(int, file.readline().split())
    neighbList = []
    for i in range(n):
        neighbList.append([])
    for i in range(m):
        s, e = map(int, file.readline().split())
        neighbList[s - 1].append(e - 1)
        neighbList[e - 1].append(s - 1)
    return n, neighbList


def dfs(dscvrd, s, n, neighb, clr):
    dscvrd[s] = clr
    for neighbour in neighb[s]:
        if dscvrd[neighbour] == 0:
            if clr == 1:
                newClr = -1
            else:
                newClr = 1
            dfs(dscvrd, neighbour, n, neighb, newClr)
        if dscvrd[neighbour] == clr:
            return False
    return True


def graphCanBeParted(neighb, n):
    dscvrd = [0] * n
    for i in range(n):
        if dscvrd[i] == 0:
            canBeParted = dfs(dscvrd, i, n, neighb, 1)
    if canBeParted:
        print('YES')
    else:
        print('NO')


def main():
    n, neighb = readList(sys.stdin)
    graphCanBeParted(neighb, n)


main()

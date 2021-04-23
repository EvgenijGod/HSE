import sys

sys.setrecursionlimit(1000000000)


def readList(file):
    n, m = map(int, file.readline().split())
    neighb = []
    for i in range(n):
        neighb.append([])
    for i in range(m):
        s, e = map(int, file.readline().split())
        neighb[s - 1].append(e - 1)
        neighb[e - 1].append(s - 1)
    return n, neighb


def dfs(dscvrd, comp, neighb, s):
    dscvrd[s] = True
    comp.append(s + 1)
    for neighbour in neighb[s]:
        if not dscvrd[neighbour]:
            dfs(dscvrd, comp, neighb, neighbour)


def findCmpnts(neighb, n):
    dscvrd = [False] * n
    cmpnts = []
    for i in range(n):
        if not dscvrd[i]:
            comp = []
            dfs(dscvrd, comp, neighb, i)
            cmpnts.append(comp)
    print(len(cmpnts))
    for comp in cmpnts:
        print(len(comp))
        print(*comp)


def main():
    n, neighb = readList(sys.stdin)
    findCmpnts(neighb, n)


main()

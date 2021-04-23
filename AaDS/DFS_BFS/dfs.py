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


def dfs(dscvrd, comp, s, n, neighb):
    dscvrd[s] = True
    comp.append(s + 1)
    for neighbour in neighb[s]:
        if not dscvrd[neighbour]:
            dfs(dscvrd, comp, neighbour, n, neighb)


def findComponents(neighb, n):
    dscvrd = [False] * n
    cmpntns = []
    for i in range(n):
        if not dscvrd[i]:
            comp = []
            dfs(dscvrd, comp, i, n, neighb)
            cmpntns.append(comp)
    print(len(cmpntns))
    for comp in cmpntns:
        print(len(comp))
        print(*sorted(comp))


def main():
    n, neighb = readList(sys.stdin)
    findComponents(neighb, n)


main()

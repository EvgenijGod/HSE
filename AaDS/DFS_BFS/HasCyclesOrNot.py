import sys

sys.setrecursionlimit(1000000000)


def readList(file):
    n = int(file.readline())
    neighbList = []
    for i in range(n):
        neighbList.append([])
    for i in range(n):
        l = list(map(int, file.readline().split()))
        for j in range(len(l)):
            if l[j] == 1:
                neighbList[j].append(i)
                neighbList[i].append(j)
    return n, neighbList


def dfs(dscvrd, comp, s, n, neighb, hasCycles):
    dscvrd[s] = -1
    comp.append(s + 1)
    for neighbour in neighb[s]:
        if dscvrd[neighbour] == 0:
            dfs(dscvrd, comp, neighbour, n, neighb, hasCycles)
        if dscvrd[neighbour] == -1:
            hasCycles = True
    dscvrd[s] = 1
    hasCycles = False


def findComponents(neighb, n):
    dscvrd = [0] * n
    ##cmpntns = []
    for i in range(n):
        if dscvrd[i] == 0:
            comp = []
            hasCycles = False
            dfs(dscvrd, comp, i, n, neighb, hasCycles)
            if hasCycles:
                if len(comp) > 2:
                    print('YES')
                    print(*comp)
                    return
    print('NO')
    return
            ##cmpntns.append(comp)
    ##print(len(cmpntns))
    ##for comp in cmpntns:
    ##    print(len(comp))
    ##    print(*sorted(comp))


def main():
    n, neighb = readList(sys.stdin)
    findComponents(neighb, n)


main()

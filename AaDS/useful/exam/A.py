import sys

sys.setrecursionlimit(1000000000)


def readList(file):
    n, m = map(int, file.readline().split())
    neighb = []
    for i in range(n * m):
        neighb.append([])
    line = file.readline()
    for j in range(1, m):
        if line[j - 1] == line[j] and line[j] == '#':
            neighb[j - 1].append(j)
            neighb[j].append(j - 1)
    for i in range(1, n):
        nextline = file.readline()
        for j in range(1, m):
            if nextline[j] == '#':
                if nextline[j - 1] == nextline[j]:
                    neighb[10 * i + j - 1].append(10 * i + j)
                    neighb[10 * i + j].append(10 * i + j - 1)
                elif nextline[j] == line[j]:
                    neighb[10*(i - 1) + j - 1].append(10 * (i - 1) + j)
                    neighb[10 * (i - 1) + j].append(10 * (i - 1) + j - 1)
    print(neighb)
    return n * m, neighb


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
    #for comp in cmpnts:
    #    print(len(comp))
    #    print(*comp)


def main():
    n, neighb = readList(sys.stdin)
    findCmpnts(neighb, n)


main()

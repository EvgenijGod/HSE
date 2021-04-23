import sys
import collections as cllcts

sys.setrecursionlimit(100000000)


def readNeighb(file, n):
    neighb = []
    for i in range(n):
        neighb.append([])
    for i in range(n):
        line = list(map(int, file.readline().split()))
        for j in range(n):
            if line[j] == 1:
                neighb[i].append(j)
    return neighb


def findWay(neighb, d, f, n, len):
    way = [f + 1]
    st = f
    len -= 1
    while len >= 0:
        for i in range(n):
            if i in neighb[st] and d[i] == len:
                way.append(i + 1)
                st = i
                len -= 1
                break
    return reversed(way)


def bfs(neighb, n, s, f):
    visited = [False] * n
    d = [1000000] * n
    q = cllcts.deque([s])
    visited[s] = True
    d[s] = 0
    while q:
        u = q.popleft()
        #print(u + 1)
        for neighbour in neighb[u]:
            if not visited[neighbour]:
                visited[neighbour] = True
                q.append(neighbour)
                d[neighbour] = d[u] + 1
    if d[f] == 10000000:
        print(-1)
    elif d[f] == 0:
        print(0)
    else:
        print(d[f])
        print(*findWay(neighb, d, f, n, d[f]))


def main():
    n = int(sys.stdin.readline())
    neighb = readNeighb(sys.stdin, n)
    s, f = map(int, sys.stdin.readline().split())
    bfs(neighb, n, s - 1, f - 1)


main()

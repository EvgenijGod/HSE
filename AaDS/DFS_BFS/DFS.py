import sys


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


def dfs(listEdge, n):
    m = matrixN(listEdge, n)
    stack = [0]
    resList = []
    discovered = [False] * n
    while stack:
        j = stack[len(stack) - 1]
        resList.append(j + 1)
        stack.pop()
        if not discovered[j]:
            discovered[j] = True
            for i in range(n):
                if m[i][j] and not discovered[i]:
                    stack.append(i)
    cnt = 0
    for i in range(n):
        if discovered[i]:
            cnt += 1
    return cnt, sorted(set(resList))


def main():
    n, listEdge = readList(sys.stdin)
    cnt, resList = dfs(listEdge, n)
    print(cnt)
    print(*resList)


main()

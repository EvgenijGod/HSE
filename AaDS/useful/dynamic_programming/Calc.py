import sys


def findway(d, n):
    k = n - 1
    way = [n]
    while k > 0:
        way.append(d[k][1] + 1)
        k = d[k][1]
    print(*reversed(way))


def calc(n):
    d = []
    for i in range(n):
        d.append([-1] * 2)
    d[0][0] = 0
    for i in range(1, n):
        if (i + 1) % 6 == 0:
            ind = i - 1
            if d[(i + 1) // 2 - 1][0] < d[i - 1][0]:
                if d[(i + 1) // 2 - 1][0] < d[(i + 1) // 3 - 1][0]:
                    ind = (i + 1) // 2 - 1
                else:
                    ind = (i + 1) // 3 - 1
            elif d[(i + 1) // 3 - 1][0] < d[i - 1][0]:
                ind = (i + 1) // 3 - 1
            d[i][0] = d[ind][0] + 1
            d[i][1] = ind
        elif (i + 1) % 2 == 0:
            ind = i - 1
            if d[ind][0] > d[(i + 1) // 2 - 1][0]:
                ind = (i + 1) // 2 - 1
            d[i][0] = d[ind][0] + 1
            d[i][1] = ind
        elif (i + 1) % 3 == 0:
            ind = i - 1
            if d[ind][0] > d[(i + 1) // 3 - 1][0]:
                ind = (i + 1) // 3 - 1
            d[i][0] = d[ind][0] + 1
            d[i][1] = ind
        else:
            d[i][0] = d[i - 1][0] + 1
            d[i][1] = i - 1
    print(d[n - 1][0])
    findway(d, n)


def main():
    n = int(sys.stdin.readline())
    calc(n)


main()

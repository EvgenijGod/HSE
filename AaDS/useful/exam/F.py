import sys


def exam(file, n, m):
    isWatched = [0] * n
    cnt = 0
    for i in range(m):
        b, e = map(int, file.readline().split())
        if b == e:
            isWatched[b] = 2
        else:
            isWatched[e] = 1
            isWatched[b] = 1
    i = 0
    while i < n:
        if isWatched[i] == 0:
            cnt += 1
            i += 1
        elif isWatched[i] == 1:
            i += 1
            while isWatched[i] != 1:
                i += 1
            i += 1
        else:
            i += 1
    return cnt


def main():
    n, m = map(int, sys.stdin.readline().split())
    print(exam(sys.stdin, n, m))


main()

import sys


def readArray(file):
    return list(map(int, file.readline().split()))


def binSearch(arr, el, l, r):
    while l <= r:
        m = l + (r - l) // 2
        if arr[m] == el:
            return m
        elif arr[m] > el:
            r = m - 1
        else:
            l = m + 1
    return -1


def main():
    arr = readArray(sys.stdin)
    print(binSearch(arr, 3, 0, len(arr) - 1))


main()

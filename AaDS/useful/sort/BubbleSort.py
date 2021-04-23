import sys


def readArr(file):
    n = int(file.readline())
    return n, list(map(int, file.readline().split()))


def bubblesort(arr, n):
    for i in range(n - 1):
        for j in range(n - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    print(*arr)


def main():
    n, arr = readArr(sys.stdin)
    bubblesort(arr, n)


main()

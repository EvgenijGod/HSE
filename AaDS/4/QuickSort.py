import sys
import random


def readArray(file):
    n = int(file.readline())
    arr = list(map(int, file.readline().split()))
    return n, arr


def partition(arr, l, r):
    i = l - 1
    pivot = arr[r]
    for j in range(l, r):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[r] = arr[r], arr[i + 1]
    return i + 1


def randomizedPartition(arr, l, r):
    i = random.randint(l, r)
    arr[i], arr[r] = arr[r], arr[i]
    return partition(arr, l, r)


def quickSort(arr, l, r):
    if l < r:
        p = randomizedPartition(arr, l, r)
        quickSort(arr, l, p - 1)
        quickSort(arr, p + 1, r)


def main():
    n, arr = readArray(sys.stdin)
    quickSort(arr, 0, n - 1)
    print(*arr)


main()

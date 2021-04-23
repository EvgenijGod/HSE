import sys


def readArr(file):
    n = int(file.readline())
    if n > 0:
        return n, list(map(int, file.readline().split()))
    else:
        return n, []


def findMax(arr, endInd):
    max_ind = 0
    for i in range(endInd + 1):
        if arr[i] > arr[max_ind]:
            max_ind = i
    return max_ind


def putMaxInTheEnd(arr, endInd):
    max_ind = findMax(arr, endInd)
    arr[max_ind], arr[endInd] = arr[endInd], arr[max_ind]


def selectionSort(arr, n):
    for i in range(n):
        putMaxInTheEnd(arr, n - i - 1)
    print(*arr)


def main():
    n, arr = readArr(sys.stdin)
    selectionSort(arr, n)


main()

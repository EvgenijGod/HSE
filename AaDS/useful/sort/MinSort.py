import sys


def readArr(file):
    n = int(file.readline())
    if n > 0:
        return n, list(map(int, file.readline().split()))
    else:
        return n, []


def findMin(arr, stIndex, n):
    min_ind = stIndex
    for i in range(stIndex, n):
        if arr[i] < arr[min_ind]:
            min_ind = i
    return min_ind


def putMinToStart(arr, stIndex, n):
    min_ind = findMin(arr, stIndex, n)
    arr[min_ind], arr[stIndex] = arr[stIndex], arr[min_ind]


def selectionSort(arr, n):
    for i in range(n):
        putMinToStart(arr, i, n)
    print(*arr)



def main():
    n, arr = readArr(sys.stdin)
    selectionSort(arr, n)


main()

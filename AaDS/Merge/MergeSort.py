import sys
import math


def readArray(file):
    n = int(file.readline())
    return n, list(map(int, file.readline().split()))


def merge(arr, p, q, r):
    resList = []
    i = 0
    j = 0
    n = q - p + 1
    m = r - q
    arr1 = arr[p:q + 1]
    arr2 = arr[q + 1:r + 1]
    while i < n or j < m:
        if i >= n:
            for element in arr2[j:]:
                resList.append(element)
            j = m
        elif j >= m:
            for element in arr1[i:]:
                resList.append(element)
            i = n
        elif arr1[i] < arr2[j]:
            resList.append(arr1[i])
            i += 1
        else:
            resList.append(arr2[j])
            j += 1
    arr[p:r + 1] = resList


def mergeSort(arr, p, r):
    if p < r:
        q = math.floor((p + r) / 2)
        mergeSort(arr, p, q)
        mergeSort(arr, q + 1, r)
        merge(arr, p, q, r)
    return arr


def printArray(intList):
    for element in intList:
        print(element, end=' ')


def main():
    n, arr = readArray(sys.stdin)
    sortedArr = mergeSort(arr, 0, n - 1)
    printArray(sortedArr)


main()

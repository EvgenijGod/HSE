import sys


def readArray(file):
    n = int(file.readline())
    return n, list(map(int, file.readline().split()))


def merge(arr1, n, arr2, m):
    resList = []
    i = 0
    j = 0
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
    return resList


def printArray(intList):
    for element in intList:
        print(element, end=' ')


def main():
    n, arr1 = readArray(sys.stdin)
    m, arr2 = readArray(sys.stdin)
    mergedList = merge(arr1, n, arr2, m)
    printArray(mergedList)


main()

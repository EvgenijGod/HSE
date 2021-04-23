import sys


def readArray(file):
    n = int(file.readline())
    return n, list(map(int, file.readline().split()))


def merge(arr1, n, arr2, m):
    i = 0
    j = 0
    mergedArr = []
    while i < n or j < m:
        if i >= n:
            for el in arr2[j:]:
                mergedArr.append(el)
            j = m
        elif j >= m:
            for el in arr1[i:]:
                mergedArr.append(el)
            i = n
        elif arr1[i] < arr2[j]:
            mergedArr.append(arr1[i])
            i += 1
        else:
            mergedArr.append(arr2[j])
            j += 1
    return mergedArr


def main():
    n, arr1 = readArray(sys.stdin)
    m, arr2 = readArray(sys.stdin)
    print(*merge(arr1, n, arr2, m))


main()

import sys


def readArray(file):
    n = int(file.readline())
    return n, list(map(int, file.readline().split()))


def merge(arr, p, q, r):
    i = 0
    j = 0
    arr1 = arr[p:q + 1]
    arr2 = arr[q + 1:r + 1]
    n = q - p + 1
    m = r - q
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
    arr[p:r + 1] = mergedArr


def mergeSort(arr, p, r):
    if p < r:
        q = int((p + r) / 2)
        mergeSort(arr, p, q)
        mergeSort(arr, q + 1, r)
        merge(arr, p, q, r)
    return arr


def main():
    n, arr = readArray(sys.stdin)
    print(*mergeSort(arr, 0, n - 1))


main()

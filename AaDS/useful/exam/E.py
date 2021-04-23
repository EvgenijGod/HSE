import sys


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


def merge3(arr1, arr2, arr3, n, m, k):
    return merge(merge(arr1, n, arr2, m), n + m, arr3, k)


def main():
    n, m, k = map(int, sys.stdin.readline().split())
    arr1 = list(map(int, sys.stdin.readline().split()))
    arr2 = list(map(int, sys.stdin.readline().split()))
    arr3 = list(map(int, sys.stdin.readline().split()))
    print(*merge3(arr1, arr2, arr3, n, m, k))


main()

import sys


def readArray(file):
    n = int(file.readline())
    arr = []
    for i in range(n):
        arr.append(file.readline().strip())
    return n, arr


def bucketSort(arr):
    print('Initial array:')
    print(*arr, sep=', ')
    print('**********')
    n = len(arr[0])
    tmpArr = arr
    for i in range(1, n + 1):
        print('Phase', i)
        buckets = []
        for j in range(10):
            buckets.append([])
        for el in tmpArr:
            digit = int(el[-i])
            buckets[digit].append(el)
        tmpArr = []
        for k in range(10):
            print('Bucket', k, end=': ')
            if not buckets[k]:
                print('empty')
            else:
                print(*buckets[k], sep=', ')
            for el in buckets[k]:
                tmpArr.append(el)
        print('**********')
    print('Sorted array:')
    print(*tmpArr, sep=', ')


def main():
    n, arr = readArray(sys.stdin)
    bucketSort(arr)


main()

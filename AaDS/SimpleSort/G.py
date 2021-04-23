from bisect import bisect_left, bisect_right


def readArray(file):
    n = int(file.readline())
    line = list(map(int, file.readline().split()))
    return n, line


def leftSrch(arr, n, el):
    i = bisect_left(arr, el)
    if i < n:
        if arr[i] == el:
            return i
        else:
            return -1
    else:
        return -1


def rightSrch(arr, n, el):
    i = bisect_right(arr, el)
    if i <= n:
        if arr[i - 1] == el:
            return i - 1
        else:
            return -1
    else:
        return -1


def elSrch(arr1, n, arr2, file):
    for el in arr2:
        l = leftSrch(arr1, n, el)
        r = rightSrch(arr1, n, el)
        file.write(str(l + 1) + ' ' + str(r + 1) + '\n')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, array1 = readArray(inFile)
        m, array2 = readArray(inFile)
        elSrch(array1, n, array2, outFile)
    inFile.close()
    outFile.close()


main()

def readArray(file):
    line = list(map(int, file.readline().split()))
    return line


def binarySearch(arr, el, l, r):
    while l <= r:
        m = l + (r - l) // 2
        if arr[m] == el:
            return m
        elif arr[m] < el:
            l = m + 1
        else:
            r = m - 1
    return -1


def binSrchInArr(arr1, n, arr2, file):
    for el in arr2:
        if binarySearch(arr1, el, 0, n - 1) != -1:
            file.write('YES' + '\n')
        else:
            file.write('NO' + '\n')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, k = map(int, inFile.readline().split())
        array1 = readArray(inFile)
        array2 = readArray(inFile)
        binSrchInArr(array1, n, array2, outFile)
    inFile.close()
    outFile.close()


main()

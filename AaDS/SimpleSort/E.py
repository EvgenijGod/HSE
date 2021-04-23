def readArray(file):
    n = int(file.readline())
    line = list(map(int, file.readline().split()))
    return n, line


def isSorted(arr, n):
    i = 0
    while arr[i] != 1:
        i += 1
    j = i
    while j < n - 1:
        if arr[j] > arr[j + 1]:
            return False
        j += 1
    for k in range(i - 1):
        if arr[k] > arr[k + 1]:
            return False
    if arr[n - 1] > arr[0]:
        return False
    return True


def findPair(arr, n):
    for i in range(n - 1):
        if arr[i] < arr[i + 1] and arr[i + 1] - arr[i] > 1:
            return i, i + 1
    if arr[n - 1] < arr[0] and arr[0] - arr[n - 1] > 1:
        return 0, n - 1


def necklaceSort(arr, n, file):
    while not isSorted(arr, n):
        a, b = findPair(arr, n)
        arr[a], arr[b] = arr[b], arr[a]
        file.write(str(arr[a]) + ' ' + str(arr[b]) + '\n')
    file.write('0')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, array = readArray(inFile)
        necklaceSort(array, n, outFile)
    inFile.close()
    outFile.close()


main()

def readArray(file):
    n = int(file.readline())
    line = list(map(int, file.readline().split()))
    return n, line


def insertionSort(arr, n, file):
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        if j != i - 1:
            for el in arr:
                file.write(str(el) + ' ')
            file.write('\n')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, array = readArray(inFile)
        insertionSort(array, n, outFile)
    inFile.close()
    outFile.close()


main()

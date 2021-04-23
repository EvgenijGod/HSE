def readArray(file):
    n = int(file.readline())
    if n > 0:
        line = list(map(int, file.readline().split()))
        return n, line
    else:
        return 0, []


def findIndexOfMax(arr, endIndex):
    maxIndex = 0
    for i in range(endIndex + 1):
        if arr[i] > arr[maxIndex]:
            maxIndex = i
    return maxIndex


def putMaxInTheEnd(arr, endIndex):
    maxIndex = findIndexOfMax(arr, endIndex)
    arr[maxIndex], arr[endIndex] = arr[endIndex], arr[maxIndex]


def selectionSort(arr, n):
    for i in range(n):
        putMaxInTheEnd(arr, n - i - 1)


def printArray(arr, file):
    for element in arr:
        file.write(str(element) + ' ')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, array = readArray(inFile)
        if n != 0:
            selectionSort(array, n)
            printArray(array, outFile)
    inFile.close()
    outFile.close()


main()

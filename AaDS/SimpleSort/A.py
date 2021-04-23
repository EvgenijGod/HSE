def readArray(file):
    n = int(file.readline())
    if n > 0:
        line = list(map(int, file.readline().split()))
        return n, line
    else:
        return 0, []


def findIndexOfMax(arr):
    maxIndex = 0
    for i in range(len(arr)):
        if arr[i] > arr[maxIndex]:
            maxIndex = i
    return maxIndex


def putMaxInTheEnd(arr, n):
    maxIndex = findIndexOfMax(arr)
    arr[maxIndex], arr[n - 1] = arr[n - 1], arr[maxIndex]


def printArray(arr, file):
    for element in arr:
        file.write(str(element) + ' ')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, array = readArray(inFile)
        if n != 0:
            putMaxInTheEnd(array, n)
            printArray(array, outFile)
    inFile.close()
    outFile.close()


main()

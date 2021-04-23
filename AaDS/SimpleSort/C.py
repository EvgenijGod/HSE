def readArray(file):
    n = int(file.readline())
    line = list(map(int, file.readline().split()))
    return n, line


def bubbleSortCnt(arr, n):
    cnt = 0
    for i in range(1, n):
        for j in range(1, n):
            if arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1]
                cnt += 1
    return cnt


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, array = readArray(inFile)
        outFile.write(str(bubbleSortCnt(array, n)))
    inFile.close()
    outFile.close()


main()

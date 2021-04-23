def readArray(file):
    n = int(file.readline())
    if n == 0:
        return 0, []
    array = list(map(int, file.readline().split()))
    return n, array


def merge(arr, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    lArr = []
    rArr = []
    for i in range(n1):
        lArr.append(arr[p + i])
    lArr.append(1000000001)
    for j in range(n2):
        rArr.append(arr[q + j + 1])
    rArr.append(1000000001)
    i = 0
    j = 0
    mergeArr = []
    for k in range(p, r + 1):
        if lArr[i] <= rArr[j]:
            mergeArr.append(lArr[i])
            i += 1
        else:
            mergeArr.append(rArr[j])
            j += 1
    return mergeArr


def printArr(arr, file):
    for el in arr:
        file.write(str(el) + ' ')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, array1 = readArray(inFile)
        m, array2 = readArray(inFile)
        array = array1 + array2
        mergeArray = merge(array, 0, n - 1, n + m - 1)
        printArr(mergeArray, outFile)
    inFile.close()
    outFile.close()


main()

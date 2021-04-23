def readArray(file):
    n = int(file.readline())
    arr = []
    for i in range(n):
        arr.append(file.readline().strip())
    return n, arr


def printArray(arr, file):
    for i in range(len(arr) - 1):
        file.write(arr[i] + ', ')
    file.write(arr[len(arr) - 1] + '\n')


def bucketSort(arr, file):
    file.write('Initial array:\n')
    printArray(arr, file)
    file.write('**********\n')
    n = len(arr[0])
    tmpArr = arr
    for i in range(1, n + 1):
        file.write('Phase ' + str(i) + '\n')
        buckets = []
        for t in range(10):
            buckets.append([])
        for j in range(len(tmpArr)):
            digit = int(tmpArr[j][-i])
            (buckets[digit]).append(tmpArr[j])
        tmpArr = []
        for k in range(10):
            file.write('Bucket ' + str(k) + ': ')
            if len(buckets[k]) == 0:
                file.write('empty\n')
            else:
                printArray(buckets[k], file)
            for el in buckets[k]:
                tmpArr.append(el)
        file.write('**********\n')
    file.write('Sorted array:\n')
    printArray(tmpArr, file)


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, arr = readArray(inFile)
        bucketSort(arr, outFile)
    inFile.close()
    outFile.close()


main()

def readArray(file):
    n = int(file.readline())
    arr = list(map(int, file.readline().split()))
    return n, arr


def partition(arr, pivot, l, r):
    i = l
    j = r
    isParted = False
    while not isParted:
        while i <= j and arr[i] < pivot:
            i += 1
        while j >= i and arr[j] >= pivot:
            j -= 1
        if j < i:
            isParted = True
        else:
            arr[i], arr[j] = arr[j], arr[i]
    return j


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, arr = readArray(inFile)
        pivot = int(inFile.readline())
        p = partition(arr, pivot, 0, n - 1)
        outFile.write(str(p + 1) + '\n' + str(n - p - 1))
    inFile.close()
    outFile.close()


main()
